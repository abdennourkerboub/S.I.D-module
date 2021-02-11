// Abdennour Kerboub G2



#ifndef ___crypt_h__
#define ___crypt_h__


#ifndef OB_INTEGER_VERSION
#   error No ORBacus version defined! Is <OB/CORBA.h> included?
#endif

#ifndef OB_NO_VERSION_CHECK
#   if (OB_INTEGER_VERSION != 4030300L)
#       error ORBacus version mismatch!
#   endif
#endif

class CaesarAlgorithm;
typedef CaesarAlgorithm* CaesarAlgorithm_ptr;
typedef CaesarAlgorithm* CaesarAlgorithmRef;

extern OB::TypeCodeConst _tc_CaesarAlgorithm;

void OBDuplicate(CaesarAlgorithm_ptr);
void OBRelease(CaesarAlgorithm_ptr);

void OBMarshal(CaesarAlgorithm_ptr, OB::OutputStreamImpl*);
void OBUnmarshal(CaesarAlgorithm_ptr&, OB::InputStreamImpl*);

typedef OB::ObjVar< CaesarAlgorithm > CaesarAlgorithm_var;
typedef OB::ObjOut< CaesarAlgorithm > CaesarAlgorithm_out;

class OBStubImpl_CaesarAlgorithm;
typedef OBStubImpl_CaesarAlgorithm* OBStubImpl_CaesarAlgorithm_ptr;

void OBDuplicate(OBStubImpl_CaesarAlgorithm_ptr);
void OBRelease(OBStubImpl_CaesarAlgorithm_ptr);

typedef OB::ObjVar< OBStubImpl_CaesarAlgorithm > OBStubImpl_CaesarAlgorithm_var;


class CaesarAlgorithm : virtual public ::CORBA::Object
{
    CaesarAlgorithm(const CaesarAlgorithm&);
    void operator=(const CaesarAlgorithm&);

protected:

    static const char* ids_[];

public:

    CaesarAlgorithm() { }
    virtual ~CaesarAlgorithm() { }

    typedef CaesarAlgorithm_ptr _ptr_type;
    typedef CaesarAlgorithm_var _var_type;

    static inline CaesarAlgorithm_ptr
    _duplicate(CaesarAlgorithm_ptr p)
    {
        if(p)
            p -> _add_ref();
        return p;
    }

    static inline CaesarAlgorithm_ptr
    _nil()
    {
        return 0;
    }

    static CaesarAlgorithm_ptr _narrow(::CORBA::Object_ptr);
    static CaesarAlgorithm_ptr _unchecked_narrow(::CORBA::Object_ptr);

    static CaesarAlgorithm_ptr _narrow(::CORBA::AbstractBase_ptr);
    static CaesarAlgorithm_ptr _unchecked_narrow(::CORBA::AbstractBase_ptr);

    static const char** _OB_staticIds();

  
    class OBUnique_charsequence { };

    typedef OB::FixSeq< ::CORBA::Char, OBUnique_charsequence > charsequence;
    typedef OB::SeqVar< OB::FixSeq< ::CORBA::Char, OBUnique_charsequence > > charsequence_var;
    typedef OB::SeqOut< OB::FixSeq< ::CORBA::Char, OBUnique_charsequence > > charsequence_out;
    static OB::TypeCodeConst _tc_charsequence;

    struct OBInfo_charsequence : public OB::ConstructedInfo
    {
        OBInfo_charsequence() { }

        virtual void free(void* p) const
        {
            delete (charsequence*)p;
        }

        virtual void* dup(const void* p) const
        {
            return new charsequence(*(const charsequence*)p);
        }

        virtual void marshal(const void*, OB::OutputStreamImpl*) const;
        virtual void unmarshal(void*, OB::InputStreamImpl*) const;
    };

   
    virtual charsequence* encrypt(const char* info,
                                  ::CORBA::ULong k,
                                  ::CORBA::ULong shift) = 0;

   
    virtual char* decrypt(const charsequence& info,
                          ::CORBA::ULong k,
                          ::CORBA::ULong shift) = 0;

  
    virtual ::CORBA::Boolean shutdown() = 0;
};


class OBProxy_CaesarAlgorithm : virtual public ::CaesarAlgorithm,
                                virtual public OBCORBA::Object
{
    OBProxy_CaesarAlgorithm(const OBProxy_CaesarAlgorithm&);
    void operator=(const OBProxy_CaesarAlgorithm&);

protected:

    virtual OB::MarshalStubImpl_ptr _OB_createMarshalStubImpl();

public:

    OBProxy_CaesarAlgorithm() { }
    virtual ~OBProxy_CaesarAlgorithm() { }

    virtual const char** _OB_ids() const;

 
    ::CaesarAlgorithm::charsequence* encrypt(const char* info,
                                             ::CORBA::ULong k,
                                             ::CORBA::ULong shift);

   
    char* decrypt(const ::CaesarAlgorithm::charsequence& info,
                  ::CORBA::ULong k,
                  ::CORBA::ULong shift);

 
    ::CORBA::Boolean shutdown();
};


class OBStubImpl_CaesarAlgorithm : virtual public OB::StubImplBase
{
    OBStubImpl_CaesarAlgorithm(const OBStubImpl_CaesarAlgorithm&);
    void operator=(const OBStubImpl_CaesarAlgorithm&);

protected:

    OBStubImpl_CaesarAlgorithm() { }

public:

    static inline OBStubImpl_CaesarAlgorithm_ptr
    _duplicate(OBStubImpl_CaesarAlgorithm_ptr p)
    {
        if(p)
            p -> _OB_incRef();
        return p;
    }

    static inline OBStubImpl_CaesarAlgorithm_ptr
    _nil()
    {
        return 0;
    }


    virtual ::CaesarAlgorithm::charsequence* encrypt(const char* info,
                                                     ::CORBA::ULong k,
                                                     ::CORBA::ULong shift) = 0;

  
    virtual char* decrypt(const ::CaesarAlgorithm::charsequence& info,
                          ::CORBA::ULong k,
                          ::CORBA::ULong shift) = 0;

 
    virtual ::CORBA::Boolean shutdown() = 0;
};


class OBMarshalStubImpl_CaesarAlgorithm : 
    virtual public OBStubImpl_CaesarAlgorithm,
    virtual public OB::MarshalStubImpl
{
    OBMarshalStubImpl_CaesarAlgorithm(const OBMarshalStubImpl_CaesarAlgorithm&);
    void operator=(const OBMarshalStubImpl_CaesarAlgorithm&);

protected:

    OBMarshalStubImpl_CaesarAlgorithm() { }
    friend class OBProxy_CaesarAlgorithm;

public:

  
    virtual ::CaesarAlgorithm::charsequence* encrypt(const char* info,
                                                     ::CORBA::ULong k,
                                                     ::CORBA::ULong shift);

 
    virtual char* decrypt(const ::CaesarAlgorithm::charsequence& info,
                          ::CORBA::ULong k,
                          ::CORBA::ULong shift);

 
    virtual ::CORBA::Boolean shutdown();
};


namespace CORBA
{

inline void
release(::CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _remove_ref();
}

inline Boolean
is_nil(::CaesarAlgorithm_ptr p)
{
    return p == 0;
}

inline void
release(OBStubImpl_CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _OB_decRef();
}

inline Boolean
is_nil(OBStubImpl_CaesarAlgorithm_ptr p)
{
    return p == 0;
}

} 

void operator<<=(::CORBA::Any&, CaesarAlgorithm_ptr*);
void operator<<=(::CORBA::Any&, CaesarAlgorithm_ptr);
CORBA::Boolean operator>>=(const ::CORBA::Any&, CaesarAlgorithm_ptr&);

inline void
operator<<=(::CORBA::Any_var& any, CaesarAlgorithm_ptr* val)
{
    any.inout() <<= val;
}

inline void
operator<<=(::CORBA::Any_var& any, CaesarAlgorithm_ptr val)
{
    any.inout() <<= val;
}

inline CORBA::Boolean
operator>>=(const ::CORBA::Any_var& any, CaesarAlgorithm_ptr& val)
{
    return any.in() >>= val;
}


void operator<<=(::CORBA::Any&, CaesarAlgorithm::charsequence*);
void operator<<=(::CORBA::Any&, const CaesarAlgorithm::charsequence&);
CORBA::Boolean operator>>=(const ::CORBA::Any&, const CaesarAlgorithm::charsequence*&);

inline void
operator<<=(::CORBA::Any_var& any, CaesarAlgorithm::charsequence* val)
{
    any.inout() <<= val;
}

inline void
operator<<=(::CORBA::Any_var& any, const CaesarAlgorithm::charsequence& val)
{
    any.inout() <<= val;
}

inline ::CORBA::Boolean
operator>>=(const ::CORBA::Any_var& any, const CaesarAlgorithm::charsequence*& val)
{
    return any.in() >>= val;
}

#endif
