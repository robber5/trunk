/*
 * asnper.h
 *
 * Abstract Syntax Notation Encoding Rules classes
 *
 * Portable Windows Library
 *
 */

#ifdef P_INCLUDE_BER

/** Class for ASN basic Encoding Rules stream.
*/
class PBER_Stream : public PASN_Stream
{
    PCLASSINFO(PBER_Stream, PASN_Stream);
  public:
    PBER_Stream();
    PBER_Stream(const PBYTEArray & bytes);
    PBER_Stream(const BYTE * buf, PINDEX size);

    PBER_Stream & operator=(const PBYTEArray & bytes);

    virtual PBoolean Read(PChannel & chan);
    virtual PBoolean Write(PChannel & chan);

    virtual PBoolean NullDecode(PASN_Null &);
    virtual void NullEncode(const PASN_Null &);
    virtual PBoolean BooleanDecode(PASN_Boolean &);
    virtual void BooleanEncode(const PASN_Boolean &);
    virtual PBoolean IntegerDecode(PASN_Integer &);
    virtual void IntegerEncode(const PASN_Integer &);
    virtual PBoolean EnumerationDecode(PASN_Enumeration &);
    virtual void EnumerationEncode(const PASN_Enumeration &);
    virtual PBoolean RealDecode(PASN_Real &);
    virtual void RealEncode(const PASN_Real &);
    virtual PBoolean ObjectIdDecode(PASN_ObjectId &);
    virtual void ObjectIdEncode(const PASN_ObjectId &);
    virtual PBoolean BitStringDecode(PASN_BitString &);
    virtual void BitStringEncode(const PASN_BitString &);
    virtual PBoolean OctetStringDecode(PASN_OctetString &);
    virtual void OctetStringEncode(const PASN_OctetString &);
    virtual PBoolean ConstrainedStringDecode(PASN_ConstrainedString &);
    virtual void ConstrainedStringEncode(const PASN_ConstrainedString &);
    virtual PBoolean BMPStringDecode(PASN_BMPString &);
    virtual void BMPStringEncode(const PASN_BMPString &);
    virtual PBoolean ChoiceDecode(PASN_Choice &);
    virtual void ChoiceEncode(const PASN_Choice &);
    virtual PBoolean ArrayDecode(PASN_Array &);
    virtual void ArrayEncode(const PASN_Array &);
    virtual PBoolean SequencePreambleDecode(PASN_Sequence &);
    virtual void SequencePreambleEncode(const PASN_Sequence &);
    virtual PBoolean SequenceKnownDecode(PASN_Sequence &, PINDEX, PASN_Object &);
    virtual void SequenceKnownEncode(const PASN_Sequence &, PINDEX, const PASN_Object &);
    virtual PBoolean SequenceUnknownDecode(PASN_Sequence &);
    virtual void SequenceUnknownEncode(const PASN_Sequence &);

    virtual PASN_Object * CreateObject(unsigned tag,
                                       PASN_Object::TagClass tagClass,
                                       PBoolean primitive) const;

    PBoolean HeaderDecode(unsigned & tagVal,
                      PASN_Object::TagClass & tagClass,
                      PBoolean & primitive,
                      unsigned & len);
    PBoolean HeaderDecode(PASN_Object & obj, unsigned & len);
    void HeaderEncode(const PASN_Object & obj);
};


#endif


// End Of File ///////////////////////////////////////////////////////////////
