//
// h4501.h
//
// Code automatically generated by asnparse.
//

#if ! H323_DISABLE_H4501

#ifndef __H4501_H
#define __H4501_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/asner.h>

#include "h225.h"
#include "x880.h"


//
// EntityType
//

class H4501_EntityType : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_EntityType, PASN_Choice);
#endif
  public:
    H4501_EntityType(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_endpoint,
      e_anyEntity
    };

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// AddressInformation
//

class H4501_AddressInformation : public H225_AliasAddress
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_AddressInformation, H225_AliasAddress);
#endif
  public:
    H4501_AddressInformation(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    PObject * Clone() const;
};


//
// InterpretationApdu
//

class H4501_InterpretationApdu : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_InterpretationApdu, PASN_Choice);
#endif
  public:
    H4501_InterpretationApdu(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_discardAnyUnrecognizedInvokePdu,
      e_clearCallIfAnyInvokePduNotRecognized,
      e_rejectAnyUnrecognizedInvokePdu
    };

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// ServiceApdus
//

class H4501_ArrayOf_ROS;

class H4501_ServiceApdus : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_ServiceApdus, PASN_Choice);
#endif
  public:
    H4501_ServiceApdus(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_rosApdus
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_ArrayOf_ROS &() const;
#else
    operator H4501_ArrayOf_ROS &();
    operator const H4501_ArrayOf_ROS &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// InvokeIdSet
//

class H4501_InvokeIdSet : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_InvokeIdSet, PASN_Integer);
#endif
  public:
    H4501_InvokeIdSet(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    H4501_InvokeIdSet & operator=(int v);
    H4501_InvokeIdSet & operator=(unsigned v);
    PObject * Clone() const;
};


//
// InvokeIDs
//

class H4501_InvokeIDs : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_InvokeIDs, PASN_Integer);
#endif
  public:
    H4501_InvokeIDs(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    H4501_InvokeIDs & operator=(int v);
    H4501_InvokeIDs & operator=(unsigned v);
    PObject * Clone() const;
};


//
// PresentedAddressScreened
//

class H4501_AddressScreened;

class H4501_PresentedAddressScreened : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PresentedAddressScreened, PASN_Choice);
#endif
  public:
    H4501_PresentedAddressScreened(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_presentationAllowedAddress,
      e_presentationRestricted,
      e_numberNotAvailableDueToInterworking,
      e_presentationRestrictedAddress
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_AddressScreened &() const;
#else
    operator H4501_AddressScreened &();
    operator const H4501_AddressScreened &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// PresentedAddressUnscreened
//

class H4501_Address;

class H4501_PresentedAddressUnscreened : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PresentedAddressUnscreened, PASN_Choice);
#endif
  public:
    H4501_PresentedAddressUnscreened(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_presentationAllowedAddress,
      e_presentationRestricted,
      e_numberNotAvailableDueToInterworking,
      e_presentationRestrictedAddress
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_Address &() const;
#else
    operator H4501_Address &();
    operator const H4501_Address &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// PresentedNumberScreened
//

class H4501_NumberScreened;

class H4501_PresentedNumberScreened : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PresentedNumberScreened, PASN_Choice);
#endif
  public:
    H4501_PresentedNumberScreened(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_presentationAllowedAddress,
      e_presentationRestricted,
      e_numberNotAvailableDueToInterworking,
      e_presentationRestrictedAddress
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_NumberScreened &() const;
#else
    operator H4501_NumberScreened &();
    operator const H4501_NumberScreened &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// PresentedNumberUnscreened
//

class H225_PartyNumber;

class H4501_PresentedNumberUnscreened : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PresentedNumberUnscreened, PASN_Choice);
#endif
  public:
    H4501_PresentedNumberUnscreened(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_presentationAllowedAddress,
      e_presentationRestricted,
      e_numberNotAvailableDueToInterworking,
      e_presentationRestrictedAddress
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H225_PartyNumber &() const;
#else
    operator H225_PartyNumber &();
    operator const H225_PartyNumber &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// PartySubaddress
//

class H4501_UserSpecifiedSubaddress;
class H4501_NSAPSubaddress;

class H4501_PartySubaddress : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PartySubaddress, PASN_Choice);
#endif
  public:
    H4501_PartySubaddress(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_userSpecifiedSubaddress,
      e_nsapSubaddress
    };

#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_UserSpecifiedSubaddress &() const;
#else
    operator H4501_UserSpecifiedSubaddress &();
    operator const H4501_UserSpecifiedSubaddress &() const;
#endif
#if defined(__GNUC__) && __GNUC__ <= 2 && __GNUC_MINOR__ < 9
    operator H4501_NSAPSubaddress &() const;
#else
    operator H4501_NSAPSubaddress &();
    operator const H4501_NSAPSubaddress &() const;
#endif

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// NSAPSubaddress
//

class H4501_NSAPSubaddress : public PASN_OctetString
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_NSAPSubaddress, PASN_OctetString);
#endif
  public:
    H4501_NSAPSubaddress(unsigned tag = UniversalOctetString, TagClass tagClass = UniversalTagClass);

    H4501_NSAPSubaddress(const char * v);
    H4501_NSAPSubaddress(const PString & v);
    H4501_NSAPSubaddress(const PBYTEArray & v);

    H4501_NSAPSubaddress & operator=(const char * v);
    H4501_NSAPSubaddress & operator=(const PString & v);
    H4501_NSAPSubaddress & operator=(const PBYTEArray & v);
    PObject * Clone() const;
};


//
// SubaddressInformation
//

class H4501_SubaddressInformation : public PASN_OctetString
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_SubaddressInformation, PASN_OctetString);
#endif
  public:
    H4501_SubaddressInformation(unsigned tag = UniversalOctetString, TagClass tagClass = UniversalTagClass);

    H4501_SubaddressInformation(const char * v);
    H4501_SubaddressInformation(const PString & v);
    H4501_SubaddressInformation(const PBYTEArray & v);

    H4501_SubaddressInformation & operator=(const char * v);
    H4501_SubaddressInformation & operator=(const PString & v);
    H4501_SubaddressInformation & operator=(const PBYTEArray & v);
    PObject * Clone() const;
};


//
// ScreeningIndicator
//

class H4501_ScreeningIndicator : public PASN_Enumeration
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_ScreeningIndicator, PASN_Enumeration);
#endif
  public:
    H4501_ScreeningIndicator(unsigned tag = UniversalEnumeration, TagClass tagClass = UniversalTagClass);

    enum Enumerations {
      e_userProvidedNotScreened,
      e_userProvidedVerifiedAndPassed,
      e_userProvidedVerifiedAndFailed,
      e_networkProvided
    };

    H4501_ScreeningIndicator & operator=(unsigned v);
    PObject * Clone() const;
};


//
// PresentationAllowedIndicator
//

class H4501_PresentationAllowedIndicator : public PASN_Boolean
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_PresentationAllowedIndicator, PASN_Boolean);
#endif
  public:
    H4501_PresentationAllowedIndicator(unsigned tag = UniversalBoolean, TagClass tagClass = UniversalTagClass);

    H4501_PresentationAllowedIndicator & operator=(PBoolean v);
    PObject * Clone() const;
};


//
// GeneralErrorList
//

class H4501_GeneralErrorList : public PASN_Enumeration
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_GeneralErrorList, PASN_Enumeration);
#endif
  public:
    H4501_GeneralErrorList(unsigned tag = UniversalEnumeration, TagClass tagClass = UniversalTagClass);

    enum Enumerations {
      e_userNotSubscribed,
      e_rejectedByNetwork,
      e_rejectedByUser,
      e_notAvailable,
      e_insufficientInformation = 5,
      e_invalidServedUserNumber,
      e_invalidCallState,
      e_basicServiceNotProvided,
      e_notIncomingCall,
      e_supplementaryServiceInteractionNotAllowed,
      e_resourceUnavailable,
      e_callFailure = 25,
      e_proceduralError = 43
    };

    H4501_GeneralErrorList & operator=(unsigned v);
    PObject * Clone() const;
};


//
// H225InformationElement
//

class H4501_H225InformationElement : public PASN_OctetString
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_H225InformationElement, PASN_OctetString);
#endif
  public:
    H4501_H225InformationElement(unsigned tag = UniversalOctetString, TagClass tagClass = UniversalTagClass);

    H4501_H225InformationElement(const char * v);
    H4501_H225InformationElement(const PString & v);
    H4501_H225InformationElement(const PBYTEArray & v);

    H4501_H225InformationElement & operator=(const char * v);
    H4501_H225InformationElement & operator=(const PString & v);
    H4501_H225InformationElement & operator=(const PBYTEArray & v);
    PObject * Clone() const;
};


//
// Extension
//

class H4501_Extension : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_Extension, PASN_Sequence);
#endif
  public:
    H4501_Extension(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    X880_Code m_extensionId;
    PASN_OctetString m_extensionArgument;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// ArrayOf_ROS
//

class X880_ROS;

class H4501_ArrayOf_ROS : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_ArrayOf_ROS, PASN_Array);
#endif
  public:
    H4501_ArrayOf_ROS(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    X880_ROS & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// ArrayOf_AliasAddress
//

class H225_AliasAddress;

class H4501_ArrayOf_AliasAddress : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_ArrayOf_AliasAddress, PASN_Array);
#endif
  public:
    H4501_ArrayOf_AliasAddress(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    H225_AliasAddress & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// NetworkFacilityExtension
//

class H4501_NetworkFacilityExtension : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_NetworkFacilityExtension, PASN_Sequence);
#endif
  public:
    H4501_NetworkFacilityExtension(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_sourceEntityAddress,
      e_destinationEntityAddress
    };

    H4501_EntityType m_sourceEntity;
    H4501_AddressInformation m_sourceEntityAddress;
    H4501_EntityType m_destinationEntity;
    H4501_AddressInformation m_destinationEntityAddress;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// AddressScreened
//

class H4501_AddressScreened : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_AddressScreened, PASN_Sequence);
#endif
  public:
    H4501_AddressScreened(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_partySubaddress
    };

    H225_PartyNumber m_partyNumber;
    H4501_ScreeningIndicator m_screeningIndicator;
    H4501_PartySubaddress m_partySubaddress;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// NumberScreened
//

class H4501_NumberScreened : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_NumberScreened, PASN_Sequence);
#endif
  public:
    H4501_NumberScreened(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    H225_PartyNumber m_partyNumber;
    H4501_ScreeningIndicator m_screeningIndicator;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// Address
//

class H4501_Address : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_Address, PASN_Sequence);
#endif
  public:
    H4501_Address(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_partySubaddress
    };

    H225_PartyNumber m_partyNumber;
    H4501_PartySubaddress m_partySubaddress;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// EndpointAddress
//

class H4501_EndpointAddress : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_EndpointAddress, PASN_Sequence);
#endif
  public:
    H4501_EndpointAddress(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_remoteExtensionAddress
    };

    H4501_ArrayOf_AliasAddress m_destinationAddress;
    H225_AliasAddress m_remoteExtensionAddress;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// UserSpecifiedSubaddress
//

class H4501_UserSpecifiedSubaddress : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_UserSpecifiedSubaddress, PASN_Sequence);
#endif
  public:
    H4501_UserSpecifiedSubaddress(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_oddCountIndicator
    };

    H4501_SubaddressInformation m_subaddressInformation;
    PASN_Boolean m_oddCountIndicator;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// SupplementaryService
//

class H4501_SupplementaryService : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H4501_SupplementaryService, PASN_Sequence);
#endif
  public:
    H4501_SupplementaryService(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_networkFacilityExtension,
      e_interpretationApdu
    };

    H4501_NetworkFacilityExtension m_networkFacilityExtension;
    H4501_InterpretationApdu m_interpretationApdu;
    H4501_ServiceApdus m_serviceApdu;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


#endif // __H4501_H

#endif // if ! H323_DISABLE_H4501


// End of h4501.h
