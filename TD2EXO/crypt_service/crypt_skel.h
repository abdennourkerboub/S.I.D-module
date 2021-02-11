// 	Abdennour Kerboub G2

#ifndef ___crypt_skel_h__
#define ___crypt_skel_h__

#include "crypt.h"


#ifndef OB_INTEGER_VERSION
#   error No ORBacus version defined! Is <OB/CORBA.h> included?
#endif

#ifndef OB_NO_VERSION_CHECK
#   if (OB_INTEGER_VERSION != 4030300L)
#       error ORBacus version mismatch!
#   endif
#endif


class POA_CaesarAlgorithm : virtual public PortableServer::ServantBase
{
    POA_CaesarAlgorithm(const POA_CaesarAlgorithm&);
    void operator=(const POA_CaesarAlgorithm&);

protected:

  
    void _OB_op_encrypt(OB::Upcall_ptr);

  
    void _OB_op_decrypt(OB::Upcall_ptr);

  
    void _OB_op_shutdown(OB::Upcall_ptr);

public:

    POA_CaesarAlgorithm() { }

    virtual ::CORBA::Boolean _is_a(const char*)
        throw(::CORBA::SystemException);

    virtual ::CORBA::RepositoryId _primary_interface(
        const PortableServer::ObjectId&,
        PortableServer::POA_ptr);

    CaesarAlgorithm_ptr _this();

    virtual OB::DirectStubImpl_ptr _OB_createDirectStubImpl(
        PortableServer::POA_ptr,
        const PortableServer::ObjectId&);
    virtual void _OB_dispatch(OB::Upcall_ptr);

  
    virtual ::CaesarAlgorithm::charsequence* encrypt(const char* info,
                                                     ::CORBA::ULong k,
                                                     ::CORBA::ULong shift)
        throw(::CORBA::SystemException) = 0;

 
    virtual char* decrypt(const ::CaesarAlgorithm::charsequence& info,
                          ::CORBA::ULong k,
                          ::CORBA::ULong shift)
        throw(::CORBA::SystemException) = 0;


    virtual ::CORBA::Boolean shutdown()
        throw(::CORBA::SystemException) = 0;
};


class OBDirectStubImpl_CaesarAlgorithm : virtual public OBStubImpl_CaesarAlgorithm,
                                         virtual public OB::DirectStubImpl
{
    OBDirectStubImpl_CaesarAlgorithm(const OBDirectStubImpl_CaesarAlgorithm&);
    void operator=(const OBDirectStubImpl_CaesarAlgorithm&);

protected:

#ifdef HAVE_VCPLUSPLUS_BUGS

    OBDirectStubImpl_CaesarAlgorithm() { }

#endif

    OBDirectStubImpl_CaesarAlgorithm(PortableServer::POA_ptr,
                                     const PortableServer::ObjectId&,
                                     PortableServer::ServantBase*);

    friend class POA_CaesarAlgorithm;

public:


    virtual ::CaesarAlgorithm::charsequence* encrypt(const char* info,
                                                     ::CORBA::ULong k,
                                                     ::CORBA::ULong shift);


    virtual char* decrypt(const ::CaesarAlgorithm::charsequence& info,
                          ::CORBA::ULong k,
                          ::CORBA::ULong shift);


    virtual ::CORBA::Boolean shutdown();
};

#endif
