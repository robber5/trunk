/*
 * xmpp_c2s.cxx
 *
 * Extensible Messaging and Presence Protocol (XMPP) Core
 * Client to Server communication classes
 *
 * Portable Windows Library
 *
 * Copyright (c) 2004 Reitek S.p.A.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Post Increment
 *
 * Contributor(s): ______________________________________.
 *
 * $Revision: 28484 $
 * $Author: rjongbloed $
 * $Date: 2012-10-05 03:53:11 -0500 (Fri, 05 Oct 2012) $
 */

#ifdef __GNUC__
#pragma implementation "xmpp_c2s.h"
#endif

#include <ptlib.h>
#include <ptclib/xmpp_c2s.h>

#if P_EXPAT

#include <ptclib/pdns.h>
#include <ptclib/cypher.h>


#define new PNEW


// If DNS resolver is enabled, we look for a matching SRV record
XMPP::C2S::TCPTransport::TCPTransport(const PString& hostname)
  : m_Hostname(hostname),
    m_Port(5222)
{
#if P_DNS_RESOLVER
  PDNS::SRVRecordList srvRecords;

  if (PDNS::GetSRVRecords(PString("_xmpp-client._tcp.") + hostname, srvRecords)) {
    PDNS::SRVRecord * rec = srvRecords.GetFirst();

    if (rec) {
      m_Hostname = rec->hostName;
      m_Port = rec->port;
    }
  }
#endif
}


// A port was specified, so well connect exactly where we're told
XMPP::C2S::TCPTransport::TCPTransport(const PString& hostname, WORD port)
  : m_Hostname(hostname),
    m_Port(port)
{
}


XMPP::C2S::TCPTransport::~TCPTransport()
{
  Close();
}


PBoolean XMPP::C2S::TCPTransport::Open()
{
  if (IsOpen())
    Close();

  PTCPSocket * s = new PTCPSocket(m_Hostname, m_Port);
  return PIndirectChannel::Open(s);
}


PBoolean XMPP::C2S::TCPTransport::Close()
{
  return PIndirectChannel::Close();
}

///////////////////////////////////////////////////////

XMPP::C2S::StreamHandler::StreamHandler(const JID& jid, const PString& pwd, PBoolean newAccount)
  : m_VersionMajor(1), m_VersionMinor(0),
    m_NewAccount(newAccount),
    m_JID(jid), m_Password(pwd),
#if P_SASL
    m_SASL("xmpp", BareJID(m_JID), m_JID.GetUser(), m_Password),
#endif
    m_HasBind(false), m_HasSession(false),
    m_State(XMPP::C2S::StreamHandler::Null)
{
  m_PendingIQs.DisallowDeleteObjects();
}


XMPP::C2S::StreamHandler::~StreamHandler()
{
  m_PendingIQsLock.Wait();
  while (m_PendingIQs.GetSize() > 0)
    delete m_PendingIQs.RemoveHead();
  m_PendingIQsLock.Signal();
}


PBoolean XMPP::C2S::StreamHandler::Start(Transport * transport)
{
  if (!transport)
    transport = new XMPP::C2S::TCPTransport(m_JID.GetServer());

  return BaseStreamHandler::Start(transport);
}


PBoolean XMPP::C2S::StreamHandler::Send(XMPP::Stanza * stanza)
{
  if (!stanza)
    return false;

  if (PIsDescendant(stanza, XMPP::IQ)) {
    XMPP::IQ * iq = (XMPP::IQ *)stanza;

    if (iq->GetResponseHandlers().GetSize() > 0) {

      if (Write(*iq)) {
        m_PendingIQsLock.Wait();
        m_PendingIQs.Append(iq);
        m_PendingIQsLock.Signal();
        return true;
      }
      else {
        delete iq;
        return false;
      }
    }
  }
  
  PBoolean res = Write(*stanza);
  delete stanza;
  return res;
}


void XMPP::C2S::StreamHandler::SetVersion(WORD major, WORD minor)
{
  m_VersionMajor = major;
  m_VersionMinor = minor;
}


void XMPP::C2S::StreamHandler::GetVersion(WORD& major, WORD& minor) const
{
  major = m_VersionMajor;
  minor = m_VersionMinor;
}


void XMPP::C2S::StreamHandler::SetState(XMPP::C2S::StreamHandler::StreamState s)
{
  if (s == XMPP::C2S::StreamHandler::Null && m_State == XMPP::C2S::StreamHandler::Established)
    OnSessionReleased();
  else if (s == XMPP::C2S::StreamHandler::Established && m_State != XMPP::C2S::StreamHandler::Established)
    OnSessionEstablished();

  m_State = s;
}


PNotifierList& XMPP::C2S::StreamHandler::IQNamespaceHandlers(const PString& xml_namespace)
{
  if (!m_IQNamespaceHandlers.Contains(xml_namespace))
    m_IQNamespaceHandlers.SetAt(xml_namespace, new PNotifierList);

  return m_IQNamespaceHandlers[xml_namespace];
}


PNotifierList& XMPP::C2S::StreamHandler::MessageSenderHandlers(const JID& from)
{
  if (!m_MessageSenderHandlers.Contains(from))
    m_MessageSenderHandlers.SetAt(from, new PNotifierList);

  return m_MessageSenderHandlers[from];
}


PBoolean XMPP::C2S::StreamHandler::Discover(const PString& xmlns,
                                            const PString& jid,
                                            const PNotifier & responseHandler,
                                            const PString& node)
{
  if (!IsEstablished()) {
    PTRACE(1, "XMPP\tDisco: invalid stream state");
    return false;
  }
  else if (responseHandler.IsNULL()) {
    PTRACE(1, "XMPP\tDisco: invalid response handler");
    return false;
  }

  PXMLElement * query = new PXMLElement(NULL, XMPP::IQQueryTag());
  query->SetAttribute(XMPP::NamespaceTag(), xmlns);

  if (!node.IsEmpty())
    query->SetAttribute("node", node);

  XMPP::IQ * iq = new XMPP::IQ(XMPP::IQ::Get, query);
  iq->SetTo(jid);
  iq->GetResponseHandlers().Add(responseHandler);
  
  return Send(iq);
}


PBoolean XMPP::C2S::StreamHandler::DiscoverItems(const PString& jid, const PNotifier & responseHandler, const PString& node)
{
  if (node.IsEmpty())
    PTRACE(3, "XMPP\tDisco: discovering items for " << jid);
  else {
    PTRACE(3, "XMPP\tDisco: discovering items for " << jid << ", node " << node);
  }

  return Discover("http://jabber.org/protocol/disco#items", jid, responseHandler, node);
}


PBoolean XMPP::C2S::StreamHandler::DiscoverInfo(const PString& jid, const PNotifier & responseHandler, const PString& node)
{
  if (node.IsEmpty())
    PTRACE(3, "XMPP\tDisco: discovering info for " << jid);
  else {
    PTRACE(3, "XMPP\tDisco: discovering info for " << jid << ", node " << node);
  }

  return Discover("http://jabber.org/protocol/disco#info", jid, responseHandler, node);
}




void XMPP::C2S::StreamHandler::OnOpen(XMPP::Stream& stream, INT extra)
{
  PString streamOn(PString::Printf, "<?xml version='1.0' encoding='UTF-8' ?>"
    "<stream:stream to='%s' xmlns='jabber:client' "
    "xmlns:stream='http://etherx.jabber.org/streams'", (const char *)m_JID.GetServer());

  if (m_VersionMajor >= 1)
    streamOn.sprintf(" version='%d.%d'>", (int)m_VersionMajor, (int)m_VersionMinor);
  else // old jabber protocol
    streamOn += ">";

  stream.Reset();
  stream.Write(streamOn);

  /* Now read the server response: we need this as we must figure out whether the
     server support the new XMPP protocol or it is an old jabber server
  */
  PString data;
  PINDEX beg = P_MAX_INDEX, end = P_MAX_INDEX;

  while(beg == P_MAX_INDEX || end == P_MAX_INDEX) {
    char buffer[256];
    buffer[sizeof(buffer)-1] = '\0';
    if (!((PChannel&)stream).Read(buffer, sizeof(buffer)-1)) {
      // Error!!!
      stream.Close();
      return;
    }
    data += buffer;
  
    if (beg == P_MAX_INDEX)
      beg = data.Find("<stream:stream ");
    if (beg != P_MAX_INDEX)
      end = data.Find('>', beg);
    if (end != P_MAX_INDEX) {
      PString str = data.Mid(beg, end - beg + 1);
      PINDEX v = str.Find("version='");

      if (v == P_MAX_INDEX) {
        m_VersionMajor = 0;
        m_VersionMinor = 9;
      } else {
        str = str.Mid(v + 9);
        int maj, min;
        if (sscanf(str, "%d.%d", &maj, &min) != 2) {
          m_VersionMajor = 0;
          m_VersionMinor = 9;
        } else {
          m_VersionMajor = maj < 1 ? (WORD)0 : (WORD)1;
          m_VersionMinor = maj < 1 ? (WORD)9 : (WORD)0;
        }
      }
    }
  }

  PXMLStreamParser * parser = stream.GetParser();

  // Now we have to feed to the parser whatever we read so far
  if (parser == NULL || !parser->Parse(data, data.GetLength(), false)) {
    // Error!!!
    stream.Close();
    return;
  }

  PXMLElement * root = parser->GetXMLTree();

  if (root != NULL)
    m_StreamID = root->GetAttribute("id");

  BaseStreamHandler::OnOpen(stream, extra);

  if (m_VersionMajor == 0)
    StartAuthNegotiation();
}


void XMPP::C2S::StreamHandler::OnClose(XMPP::Stream& stream, INT extra)
{
  SetState(XMPP::C2S::StreamHandler::Null);
  m_HasBind = false;
  m_HasSession = false;
  PString streamOff("</stream:stream>");

  stream.Write(streamOff);

  BaseStreamHandler::OnClose(stream, extra);
}


void XMPP::C2S::StreamHandler::StartRegistration()
{
    PString reg(PString::Printf, "<iq type='set' to='%s' id='reg1'>"
                                     "<query xmlns='jabber:iq:register'>"
                                        "<username>%s</username>"
                                        "<password>%s</password>"
                                     "</query></iq>",
                                     (const char *)m_JID.GetServer(),
                                     (const char *)m_JID.GetUser(),
                                     (const char *)m_Password);

    m_Stream->Write(reg);
    SetState(XMPP::C2S::StreamHandler::RegStarted);
}


void XMPP::C2S::StreamHandler::StartAuthNegotiation()
{
  if (m_NewAccount) {
    StartRegistration();
    return;
  }

#if P_SASL
  // We have SASL, but we might have not found a mechanism in
  // common, or we are just supporting the old jabber protocol
  if (m_VersionMajor > 0 && !m_Mechanism.IsEmpty()) {
    // Go with SASL!
    PString output;

    if (!m_SASL.Start(m_Mechanism, output)) {
      Stop();
      return;
    }

    PStringStream auth;
    auth << "<auth xmlns='urn:ietf:params:xml:ns:xmpp-sasl' mechanism='"
         << m_Mechanism << '\'';

    if (output.IsEmpty())
      auth << "/>";
    else
      auth << '>' << output << "</auth>";

    m_Stream->Write(auth);
    SetState(XMPP::C2S::StreamHandler::SASLStarted);
  }
  else
#endif
  {
    // JEP-0078 Non SASL authentication
    PString auth(PString::Printf, "<iq type='get' to='%s' id='auth1'>"
                                     "<query xmlns='jabber:iq:auth'>"
                                        "<username>%s</username>"
                                     "</query></iq>",
                                     (const char *)m_JID.GetServer(), (const char *)m_JID.GetUser());

    m_Stream->Write(auth);
    SetState(XMPP::C2S::StreamHandler::NonSASLStarted);
  }
}


void XMPP::C2S::StreamHandler::OnSessionEstablished()
{
  m_SessionEstablishedHandlers(*this, 0);
}


void XMPP::C2S::StreamHandler::OnSessionReleased()
{
  m_SessionReleasedHandlers(*this, 0);
}


void XMPP::C2S::StreamHandler::OnElement(PXML& pdu)
{
  switch (m_State)
  {
  case Null:
    HandleNullState(pdu);
    break;

  case RegStarted:
    HandleRegStartedState(pdu);
    break;

  case TLSStarted:
    HandleTLSStartedState(pdu);
    break;

#if P_SASL
  case SASLStarted:
    HandleSASLStartedState(pdu);
    break;
#endif

  case NonSASLStarted:
    HandleNonSASLStartedState(pdu);
    break;

  case StreamSent:
    HandleStreamSentState(pdu);
    break;

  case BindSent:
    HandleBindSentState(pdu);
    break;

  case SessionSent:
    HandleSessionSentState(pdu);
    break;

  case Established:
    HandleEstablishedState(pdu);
    break;

  default:
    // Error
    PAssertAlways(PLogicError);
  }
}


void XMPP::C2S::StreamHandler::HandleNullState(PXML& pdu)
{
  if (pdu.GetRootElement()->GetName() != "stream:features")
  {
    Stop();
    return;
  }

  /* This is what we are kind of expecting (more or less)
  <stream:features>
    <starttls xmlns='urn:ietf:params:xml:ns:xmpp-tls'>
      <required/>
    </starttls>
    <mechanisms xmlns='urn:ietf:params:xml:ns:xmpp-sasl'>
      <mechanism>DIGEST-MD5</mechanism>
      <mechanism>PLAIN</mechanism>
    </mechanisms>
  </stream:features>
  */

//  PXMLElement * starttls = pdu.GetRootElement()->GetElement("starttls");
  PStringSet ourMechSet;

  // We might have to negotiate the TLS first, but we set up the SASL phase now

#if P_SASL
  PXMLElement * mechList = pdu.GetRootElement()->GetElement("mechanisms");
  if (!mechList || !m_SASL.Init(m_JID.GetServer(), ourMechSet))
  {
    // SASL initialisation failed, goodbye...
    Stop();
    return;
  }

  PXMLElement * mech;
  PINDEX i = 0;

  while ((mech = mechList->GetElement("mechanism", i++)) != 0)
  {
    if (ourMechSet.Contains(mech->GetData())) // Hit
      break;
  }
  if (mech != NULL)
    m_Mechanism = mech->GetData();
#endif

  // That's how it'll be once we support TLS
  /*if (starttls && (m_UseTLS || starttls->GetElement("required") != 0))
  {
    // we must start the TLS nogotiation...
    SetState(XMPP::C2S::StreamHandler::TLSStarted);
  }
  else*/
    StartAuthNegotiation();
}


void XMPP::C2S::StreamHandler::HandleRegStartedState(PXML& pdu)
{
  PXMLElement * elem = pdu.GetRootElement();

  if (elem->GetName() != "iq" || elem->GetAttribute("type") != "result") {
    Stop();
    return;
  }

  m_NewAccount = false;
  StartAuthNegotiation();
}


void XMPP::C2S::StreamHandler::HandleTLSStartedState(PXML& /*pdu*/)
{
  PAssertAlways(PUnimplementedFunction);
}


#if P_SASL
void XMPP::C2S::StreamHandler::HandleSASLStartedState(PXML& pdu)
{
  PString name = pdu.GetRootElement()->GetName();

  if (name == "challenge")
  {
    PString input = pdu.GetRootElement()->GetData();
    PString output;

    if (m_SASL.Negotiate(input, output) == PSASLClient::Fail)
    {
      Stop();
      return;
    }
    PString response("<response xmlns='urn:ietf:params:xml:ns:xmpp-sasl'");
    if (output.IsEmpty())
      response += "/>";
    else
    {
      response += ">";
      response += output;
      response += "</response>";
    }
    m_Stream->Write(response);
  }
  else if (name == "success")
  {
    m_SASL.End();
    OnOpen(*m_Stream, 0); // open the inner stream (i.e. reset the parser)
    SetState(XMPP::C2S::StreamHandler::StreamSent);
  }
  else
  {
    Stop();
  }
}
#endif


void XMPP::C2S::StreamHandler::HandleNonSASLStartedState(PXML& pdu)
{
  PXMLElement * elem = pdu.GetRootElement();

  if (elem->GetName() != "iq" || elem->GetAttribute("type") != "result") {
    Stop();
    return;
  }

  elem = elem->GetElement(XMPP::IQQueryTag());

  if (elem == NULL) { // Authentication succeded
    SetState(XMPP::C2S::StreamHandler::Established);
  }
  else {

    PString auth(PString::Printf, "<iq type='set' to='%s' id='auth2'>"
                                     "<query xmlns='jabber:iq:auth'>", (const char *)m_JID.GetServer());

    PINDEX i = 0;
    PXMLElement * item;
    PBoolean uid = false, pwd = false, digest = false, res = false;

    while ((item = (PXMLElement *)elem->GetElement(i++)) != NULL) {
      PString name = item->GetName();

      if (name *= "username")
        uid = true;
      else if (name *= "password")
        pwd = true;
      else if (name *= "digest")
        digest = true;
      else if (name *= "resource")
        res = true;
    }

    if (uid)
      auth += "<username>" + m_JID.GetUser() + "</username>";

    if (res)
      auth += "<resource>" + m_JID.GetResource() + "</resource>";

#if P_SSL
    if (digest) {
      PMessageDigest::Result bin_digest;
      PMessageDigestSHA1::Encode(m_StreamID + m_Password, bin_digest);
      PString digest;

      const BYTE * data = bin_digest.GetPointer();

      for (PINDEX i = 0, max = bin_digest.GetSize(); i < max ; i++)
        digest.sprintf("%02x", (unsigned)data[i]);

      auth += "<digest>" + digest + "</digest>";
    }
    else 
#endif

    if (pwd)
      auth += "<password>" + m_Password + "</password>";

    auth += "</query></iq>";
    m_Stream->Write(auth);
  }
}


void XMPP::C2S::StreamHandler::HandleStreamSentState(PXML& pdu)
{
  if (pdu.GetRootElement()->GetName() != "stream:features")
  {
    Stop();
    return;
  }
  /*
  <stream:features>
  <bind xmlns='urn:ietf:params:xml:ns:xmpp-bind'/>
  <session xmlns='urn:ietf:params:xml:ns:xmpp-session'/>
  </stream:features>
  */

  m_HasBind = pdu.GetRootElement()->GetElement("bind") != NULL;
  m_HasSession = pdu.GetRootElement()->GetElement("session") != NULL;

  if (m_HasBind)
  {
    PString bind("<iq type='set' id='bind_1'>"
      "<bind xmlns='urn:ietf:params:xml:ns:xmpp-bind'");

    if (m_JID.GetResource().IsEmpty())
      bind += "/></iq>";
    else
    {
      bind += "><resource>";
      bind += m_JID.GetResource();
      bind += "</resource></bind></iq>";
    }

    m_Stream->Write(bind);
    SetState(XMPP::C2S::StreamHandler::BindSent);
  }
  else if (m_HasSession)
    HandleBindSentState(pdu);
  else
    SetState(XMPP::C2S::StreamHandler::Established);
}


void XMPP::C2S::StreamHandler::HandleBindSentState(PXML& pdu)
{
  if (m_State == XMPP::C2S::StreamHandler::BindSent)
  {
    PXMLElement * elem = pdu.GetRootElement();

    if (elem->GetName() != "iq" || elem->GetAttribute("type") != "result")
    {
      Stop();
      return;
    }

    if ((elem = elem->GetElement("bind")) == NULL || (elem = elem->GetElement("jid")) == NULL)
    {
      Stop();
      return;
    }

    PString jid = elem->GetData();
  }

  if (m_HasSession)
  {
    PString session = "<iq id='sess_1' type='set'><session xmlns='urn:ietf:params:xml:ns:xmpp-session'/></iq>";
    m_Stream->Write(session);
    SetState(XMPP::C2S::StreamHandler::SessionSent);
  }
  else
    SetState(XMPP::C2S::StreamHandler::Established);
}


void XMPP::C2S::StreamHandler::HandleSessionSentState(PXML& pdu)
{
  PXMLElement * elem = pdu.GetRootElement();

  if (elem->GetName() != "iq" || elem->GetAttribute("type") != "result")
  {
    Stop();
    return;
  }

  SetState(XMPP::C2S::StreamHandler::Established);
}


void XMPP::C2S::StreamHandler::HandleEstablishedState(PXML& pdu)
{
  PCaselessString name = pdu.GetRootElement()->GetName();

  if (name == "stream:error") {
    OnError(pdu);
    Stop();
  }
  else if (name == XMPP::MessageStanzaTag()) {
    XMPP::Message msg(pdu);

    if (msg.IsValid())
      OnMessage(msg);
    else
      Stop("bad-format");
  }
  else if (name == XMPP::PresenceStanzaTag()) {
    XMPP::Presence pre(pdu);

    if (pre.IsValid())
      OnPresence(pre);
    else
      Stop("bad-format");
  }
  else if (name == XMPP::IQStanzaTag()) {
    XMPP::IQ iq(pdu);

    if (iq.IsValid())
      OnIQ(iq);
    else
      Stop("bad-format");
  }
  else
    Stop("unsupported-stanza-type");
}


void XMPP::C2S::StreamHandler::OnError(PXML& pdu)
{
  m_ErrorHandlers(pdu, 0);
}


void XMPP::C2S::StreamHandler::OnMessage(XMPP::Message& pdu)
{
  JID from = pdu.GetFrom();

  /* Fire the generic message handles only if there isn't a notifier list 
  for this particular originator or the list is empty
  */
  if (!m_MessageSenderHandlers.Contains(from) || !m_MessageSenderHandlers[from](pdu, 0))
    m_MessageHandlers(pdu, 0);
}


void XMPP::C2S::StreamHandler::OnPresence(XMPP::Presence& pdu)
{
  m_PresenceHandlers(pdu, 0);
}


void XMPP::C2S::StreamHandler::OnIQ(XMPP::IQ& pdu)
{
  XMPP::IQ::IQType type = pdu.GetType();
  XMPP::IQ * origMsg = NULL;

  if (type == XMPP::IQ::Result || type == XMPP::IQ::Error) {
    PString id = pdu.GetID();

    m_PendingIQsLock.Wait();
    for (StanzaList::iterator i = m_PendingIQs.begin(); i != m_PendingIQs.end(); i++)
      if (((XMPP::IQ&)(*i)).GetID() == id) {
        origMsg = (XMPP::IQ *)m_PendingIQs.Remove(&*i);
        pdu.SetOriginalMessage(origMsg);
      }
    m_PendingIQsLock.Signal();
  }

  if (origMsg != NULL)
    origMsg->GetResponseHandlers()(pdu, 0);

  // Let's see if someone is registered to handle this namespace
  PXMLElement * query = (PXMLElement *)pdu.GetRootElement()->GetElement(0);
  PString xmlns = query != NULL ? query->GetAttribute(XMPP::NamespaceTag()) : PString::Empty();

  if (!xmlns.IsEmpty() && m_IQNamespaceHandlers.Contains(xmlns))
    m_IQNamespaceHandlers[xmlns](pdu, 0);

  // Now the "normal" handlers
  m_IQHandlers(pdu, 0);

  // If it was a set or a get and nobody took care of it, we send and error back
  if ((type == XMPP::IQ::Set || type == XMPP::IQ::Get) && !pdu.HasBeenProcessed()) {
    XMPP::IQ * error = pdu.BuildError("cancel", "feature-not-implemented");
    Send(error);
  }
}


#endif // P_EXPAT

// End of File ///////////////////////////////////////////////////////////////



