#pragma implementation "sound.h"

#include <ptlib.h>

#include <time.h>

class SoundHandleEntry : public PObject {

  PCLASSINFO(SoundHandleEntry, PObject)

  public:
    SoundHandleEntry();

    int handle;
    int direction;

    unsigned numChannels;
    unsigned sampleRate;
    unsigned bitsPerSample;
    unsigned fragmentValue;
    PBoolean isInitialised;
};

PDICTIONARY(SoundHandleDict, PString, SoundHandleEntry);

PMutex           PSoundChannel::dictMutex;

static SoundHandleDict & handleDict()
{
  static SoundHandleDict dict;
  return dict;
}

#define LOOPBACK_BUFFER_SIZE 5000
#define BYTESINBUF ((startptr<endptr)?(endptr-startptr):(LOOPBACK_BUFFER_SIZE+endptr-startptr))

char soundbuffer[LOOPBACK_BUFFER_SIZE];
int  startptr, endptr;


PSound::PSound(unsigned channels,
               unsigned samplesPerSecond,
               unsigned bitsPerSample,
               PINDEX   bufferSize,
               const BYTE * buffer)
{
  encoding = 0;
  numChannels = channels;
  sampleRate = samplesPerSecond;
  sampleSize = bitsPerSample;
  SetSize(bufferSize);
  if (buffer != NULL)
    memcpy(GetPointer(), buffer, bufferSize);
}


PSound::PSound(const PFilePath & filename)
{
  encoding = 0;
  numChannels = 1;
  sampleRate = 8000;
  sampleSize = 16;
  Load(filename);
}


PSound & PSound::operator=(const PBYTEArray & data)
{
  PBYTEArray::operator=(data);
  return *this;
}


void PSound::SetFormat(unsigned channels,
                       unsigned samplesPerSecond,
                       unsigned bitsPerSample)
{
  encoding = 0;
  numChannels = channels;
  sampleRate = samplesPerSecond;
  sampleSize = bitsPerSample;
  formatInfo.SetSize(0);
}


PBoolean PSound::Load(const PFilePath & /*filename*/)
{
  return false;
}


PBoolean PSound::Save(const PFilePath & /*filename*/)
{
  return false;
}

///////////////////////////////////////////////////////////////////////////////

SoundHandleEntry::SoundHandleEntry()
{
  handle    = -1;
  direction = 0;
}

///////////////////////////////////////////////////////////////////////////////

PSoundChannel::PSoundChannel()
{
  Construct();
}


PSoundChannel::PSoundChannel(const PString & device,
                             Directions dir,
                             unsigned numChannels,
                             unsigned sampleRate,
                             unsigned bitsPerSample)
{
  Construct();
  Open(device, dir, numChannels, sampleRate, bitsPerSample);
}


void PSoundChannel::Construct()
{
  os_handle = -1;
}


PSoundChannel::~PSoundChannel()
{
  Close();
}


PStringArray PSoundChannel::GetDeviceNames(Directions /*dir*/)
{
  static const char * const devices[] = {
    "loopback"
  };

  return PStringArray(PARRAYSIZE(devices), devices);
}


PString PSoundChannel::GetDefaultDevice(Directions /*dir*/)
{
  return "loopback";
}


PBoolean PSoundChannel::Open(const PString & _device,
                              Directions _dir,
                                unsigned _numChannels,
                                unsigned _sampleRate,
                                unsigned _bitsPerSample)
{
  Close();

  // lock the dictionary
  dictMutex.Wait();

  // make the direction value 1 or 2
  int dir = _dir + 1;

  // if this device in in the dictionary
  if (handleDict().Contains(_device)) {

    SoundHandleEntry & entry = handleDict()[_device];

    // see if the sound channel is already open in this direction
    if ((entry.direction & dir) != 0) {
      dictMutex.Signal();
      return false;
    }

    // flag this entry as open in this direction
    entry.direction |= dir;
    os_handle = entry.handle;

  } else {

    // this is the first time this device has been used
    // open the device in read/write mode always
    if (_device == "loopback") {
      startptr = endptr = 0;
      os_handle = 0; // Use os_handle value 0 to indicate loopback, cannot ever be stdin!
    }
    else  {
      PAssertAlways(PUnimplementedFunction);
      return false;
    }

    // add the device to the dictionary
    SoundHandleEntry * entry = PNEW SoundHandleEntry;
    handleDict().SetAt(_device, entry); 

    // save the information into the dictionary entry
    entry->handle        = os_handle;
    entry->direction     = dir;
    entry->numChannels   = _numChannels;
    entry->sampleRate    = _sampleRate;
    entry->bitsPerSample = _bitsPerSample;
    entry->isInitialised = false;
    entry->fragmentValue = 0x7fff0008;
  }
   
   
  // unlock the dictionary
  dictMutex.Signal();

  // save the direction and device
  direction     = _dir;
  device        = _device;
  isInitialised = false;

  return true;
}

PBoolean PSoundChannel::Setup()
{
  if (os_handle < 0)
    return false;

  if (isInitialised)
    return true;

  // lock the dictionary
  dictMutex.Wait();

  // the device must always be in the dictionary
  PAssertOS(handleDict().Contains(device));

  // get record for the device
  SoundHandleEntry & entry = handleDict()[device];

  PBoolean stat = false;
  if (entry.isInitialised)  {
    isInitialised = true;
    stat          = true;
  } else if (device == "loopback")
    stat = true;
  else {
    PAssertAlways(PUnimplementedFunction);
  }

  entry.isInitialised = true;
  isInitialised       = true;

  dictMutex.Signal();

  return stat;
}

PBoolean PSoundChannel::Close()
{
  // if the channel isn't open, do nothing
  if (os_handle < 0)
    return true;

  if (os_handle == 0) {
    os_handle = -1;
    return true;
  }

  // the device must be in the dictionary
  dictMutex.Wait();
  SoundHandleEntry * entry;
  PAssert((entry = handleDict().GetAt(device)) != NULL, "Unknown sound device \"" + device + "\" found");

  // modify the directions bit mask in the dictionary
  entry->direction ^= (direction+1);

  // if this is the last usage of this entry, then remove it
  if (entry->direction == 0) {
    handleDict().RemoveAt(device);
    dictMutex.Signal();
    return PChannel::Close();
  }

  // flag this channel as closed
  dictMutex.Signal();
  os_handle = -1;
  return true;
}

PBoolean PSoundChannel::Write(const void * buf, PINDEX len)
{
  static struct timespec ts = {0, 5000000};

  if (!Setup()) {
    return false;
	}

  if (os_handle > 0) {
    while (!ConvertOSError(::write(os_handle, (char *)buf, len)))
      if (GetErrorCode() != Interrupted) {
        return false;
			}
    return true;
  }

  int index = 0;

  while (len > 0) {
    len--;
    soundbuffer[endptr++] = ((char *)buf)[index++];
    if (endptr == LOOPBACK_BUFFER_SIZE)
      endptr = 0;
    while (((startptr - 1) == endptr) || ((endptr==LOOPBACK_BUFFER_SIZE - 1) && (startptr==0))) {
      nanosleep(&ts, 0);
    }
  }
  return true;
}

PBoolean PSoundChannel::Read(void * buf, PINDEX len)
{
  static struct timespec ts = {0, 5000000};

  if (!Setup())
    return false;

  if (os_handle > 0) {
    while (!ConvertOSError(::read(os_handle, (char *)buf, len)))
      if (GetErrorCode() != Interrupted)
        return false;
    return true;
  }

  int index = 0;
	
  while (len > 0) {

	int i = 0;
    while ((startptr == endptr) && (i < 30)){		// int i is a very dirty hack to get the
																								// call-termination to work. Transmit thread
																								// will otherwise not end! (channels.cxx line 706
																								// while() will get stuck. This should be fixed.
			i++;
      nanosleep(&ts, 0);
		}
    len--;
    ((char *)buf)[index++]=soundbuffer[startptr++];
    if (startptr == LOOPBACK_BUFFER_SIZE)
      startptr = 0;
  } 

  return true;
}


PBoolean PSoundChannel::SetFormat(unsigned numChannels,
                              unsigned sampleRate,
                              unsigned bitsPerSample)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  // check parameters
  PAssert((bitsPerSample == 8) || (bitsPerSample == 16), PInvalidParameter);
  PAssert(numChannels >= 1 && numChannels <= 2, PInvalidParameter);

  Abort();

  // lock the dictionary
  dictMutex.Wait();

  // the device must always be in the dictionary
  PAssertOS(handleDict().Contains(device));

  // get record for the device
  SoundHandleEntry & entry = handleDict()[device];

  entry.numChannels   = numChannels;
  entry.sampleRate    = sampleRate;
  entry.bitsPerSample = bitsPerSample;
  entry.isInitialised  = false;

  // unlock dictionary
  dictMutex.Signal();

  // mark this channel as uninitialised
  isInitialised = false;

  return true;
}


PBoolean PSoundChannel::SetBuffers(PINDEX size, PINDEX count)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  Abort();

  PAssert(size > 0 && count > 0 && count < 65536, PInvalidParameter);
  int arg = 1;
  while (size > (PINDEX)(1 << arg))
    arg++;

  arg |= count << 16;

  // lock the dictionary
  dictMutex.Wait();

  // the device must always be in the dictionary
  PAssertOS(handleDict().Contains(device));

  // get record for the device
  SoundHandleEntry & entry = handleDict()[device];

  // set information in the common record
  entry.fragmentValue = arg;
  entry.isInitialised = false;

  // flag this channel as not initialised
  isInitialised       = false;

  dictMutex.Signal();

  return true;
}


PBoolean PSoundChannel::GetBuffers(PINDEX & size, PINDEX & count)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  // lock the dictionary
  dictMutex.Wait();

  // the device must always be in the dictionary
  PAssertOS(handleDict().Contains(device));

  SoundHandleEntry & entry = handleDict()[device];

  int arg = entry.fragmentValue;

  dictMutex.Signal();

  count = arg >> 16;
  size = 1 << (arg&0xffff);
  return true;
}


PBoolean PSoundChannel::PlaySound(const PSound & sound, PBoolean wait)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  Abort();

  if (!Write((const BYTE *)sound, sound.GetSize()))
    return false;

  if (wait)
    return WaitForPlayCompletion();

  return true;
}


PBoolean PSoundChannel::PlayFile(const PFilePath & filename, PBoolean wait)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  return false;
}


PBoolean PSoundChannel::HasPlayCompleted()
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  if (os_handle == 0)
    return BYTESINBUF <= 0;

  PAssertAlways(PUnimplementedFunction);
  return false;
}


PBoolean PSoundChannel::WaitForPlayCompletion()
{
  static struct timespec ts = {0, 1000000};

  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  if (os_handle == 0) {
    while (BYTESINBUF > 0)
      nanosleep(&ts, 0);
    return true;
  }

  PAssertAlways(PUnimplementedFunction);
  return false;
}


PBoolean PSoundChannel::RecordSound(PSound & sound)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  return false;
}


PBoolean PSoundChannel::RecordFile(const PFilePath & filename)
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  return false;
}


PBoolean PSoundChannel::StartRecording()
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  if (os_handle == 0)
    return true;

  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(os_handle, &fds);

  struct timeval timeout;
  memset(&timeout, 0, sizeof(timeout));

  return ConvertOSError(::select(1, &fds, NULL, NULL, &timeout));
}


PBoolean PSoundChannel::IsRecordBufferFull()
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  if (os_handle == 0)
    return (BYTESINBUF > 0);

  PAssertAlways(PUnimplementedFunction);
  return false;
}


PBoolean PSoundChannel::AreAllRecordBuffersFull()
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  if (os_handle == 0)
    return (BYTESINBUF == LOOPBACK_BUFFER_SIZE);

  PAssertAlways(PUnimplementedFunction);
  return false;
}


PBoolean PSoundChannel::WaitForRecordBufferFull()
{
  if (os_handle < 0) {
    return SetErrorValues(NotOpen, EBADF);
  }

  return PXSetIOBlock(PXReadBlock, readTimeout);
}


PBoolean PSoundChannel::WaitForAllRecordBuffersFull()
{
  return false;
}


PBoolean PSoundChannel::Abort()
{
  if (os_handle == 0) {
    startptr = endptr = 0;
    return true;
  }

  PAssertAlways(PUnimplementedFunction);
  return false;
}


// End of file
