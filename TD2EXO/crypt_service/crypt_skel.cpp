// 	Abdennour Kerboub G2

#include <OB/CORBAServer.h>
#include "crypt_skel.h"

#ifndef OB_INTEGER_VERSION
#   error No ORBacus version defined! Is <OB/CORBA.h> included?
#endif

#ifndef OB_NO_VERSION_CHECK
#   if (OB_INTEGER_VERSION != 4030300L)
#       error ORBacus version mismatch!
#   endif
#endif


void
POA_CaesarAlgorithm::_OB_op_encrypt(OB::Upcall_ptr _ob_up)
{
    OB::StrForStruct _ob_a0;
    ::CORBA::ULong _ob_a1;
    ::CORBA::ULong _ob_a2;
    OB::InputStreamImpl* _ob_in = _OB_preUnmarshal(_ob_up);
    _ob_a0 = _ob_in -> read_string();
    _ob_a1 = _ob_in -> read_ulong();
    _ob_a2 = _ob_in -> read_ulong();
    _OB_postUnmarshal(_ob_up);
    ::CaesarAlgorithm::charsequence_var _ob_r = encrypt(_ob_a0, _ob_a1, _ob_a2);
    _OB_postinvoke(_ob_up);
    OB::OutputStreamImpl* _ob_out = _OB_preMarshal(_ob_up);
    ::CORBA::ULong _ob_len0 = _ob_r.in().length();
    _ob_out -> write_ulong(_ob_len0);
    _ob_out -> write_char_array(_ob_r.in().get_buffer(), _ob_len0);
    _OB_postMarshal(_ob_up);
}


void
POA_CaesarAlgorithm::_OB_op_decrypt(OB::Upcall_ptr _ob_up)
{
    ::CaesarAlgorithm::charsequence _ob_a0;
    ::CORBA::ULong _ob_a1;
    ::CORBA::ULong _ob_a2;
    OB::InputStreamImpl* _ob_in = _OB_preUnmarshal(_ob_up);
    ::CORBA::ULong _ob_len0 = _ob_in -> read_ulong();
    _ob_a0.length(_ob_len0);
    _ob_in -> read_char_array(_ob_a0.get_buffer(), _ob_len0);
    _ob_a1 = _ob_in -> read_ulong();
    _ob_a2 = _ob_in -> read_ulong();
    _OB_postUnmarshal(_ob_up);
    ::CORBA::String_var _ob_r = decrypt(_ob_a0, _ob_a1, _ob_a2);
    _OB_postinvoke(_ob_up);
    OB::OutputStreamImpl* _ob_out = _OB_preMarshal(_ob_up);
    _ob_out -> write_string(_ob_r.in());
    _OB_postMarshal(_ob_up);
}


void
POA_CaesarAlgorithm::_OB_op_shutdown(OB::Upcall_ptr _ob_up)
{
    _OB_preUnmarshal(_ob_up);
    _OB_postUnmarshal(_ob_up);
    ::CORBA::Boolean _ob_r = shutdown();
    _OB_postinvoke(_ob_up);
    OB::OutputStreamImpl* _ob_out = _OB_preMarshal(_ob_up);
    _ob_out -> write_boolean(_ob_r);
    _OB_postMarshal(_ob_up);
}


::CORBA::Boolean
POA_CaesarAlgorithm::_is_a(const char* type)
    throw(::CORBA::SystemException)
{
    const char** _ob_ids = CaesarAlgorithm::_OB_staticIds();
    for(::CORBA::ULong _ob_i = 0; _ob_ids[_ob_i] != 0; ++_ob_i)
        if(strcmp(type, _ob_ids[_ob_i]) == 0)
            return true;

    return false;
}

::CORBA::RepositoryId
POA_CaesarAlgorithm::_primary_interface(const PortableServer::ObjectId&,
                                        PortableServer::POA_ptr)
{
    return ::CORBA::string_dup(CaesarAlgorithm::_OB_staticIds()[0]);
}

CaesarAlgorithm_ptr
POA_CaesarAlgorithm::_this()
{
    ::CORBA::Object_var obj = _OB_createReference();
    CaesarAlgorithm_var result = CaesarAlgorithm::_narrow(obj);
    return result._retn();
}

OB::DirectStubImpl_ptr
POA_CaesarAlgorithm::_OB_createDirectStubImpl(PortableServer::POA_ptr poa,
                                              const PortableServer::ObjectId& oid)
{
    return new OBDirectStubImpl_CaesarAlgorithm(poa, oid, this);
}

void
POA_CaesarAlgorithm::_OB_dispatch(OB::Upcall_ptr _ob_up)
{
    static const char* _ob_names[] =
    {
        "decrypt",
        "encrypt",
        "shutdown"
    };
    static const ::CORBA::ULong _ob_numNames = 3;

    switch(_OB_findOperation(_ob_up, _ob_names, _ob_numNames))
    {
    case 0: 
        _OB_op_decrypt(_ob_up);
        return;

    case 1: 
        _OB_op_encrypt(_ob_up);
        return;

    case 2: 
        _OB_op_shutdown(_ob_up);
        return;
    }

    _OB_dispatchBase(_ob_up);
}


OBDirectStubImpl_CaesarAlgorithm::OBDirectStubImpl_CaesarAlgorithm(
    PortableServer::POA_ptr poa,
    const PortableServer::ObjectId& oid,
    PortableServer::ServantBase* servant)
#ifdef HAVE_VCPLUSPLUS_BUGS
{
    _ob_initialize(poa, oid, servant);
}
#else
    : OB::DirectStubImpl(poa, oid, servant)
{
}
#endif


::CaesarAlgorithm::charsequence*
OBDirectStubImpl_CaesarAlgorithm::encrypt(const char* _ob_a0,
                                          ::CORBA::ULong _ob_a1,
                                          ::CORBA::ULong _ob_a2)
{
    OB::InvocationHandler _ob_handler(this, "encrypt");
    return dynamic_cast<POA_CaesarAlgorithm*>(_ob_servant_) -> encrypt(_ob_a0, _ob_a1, _ob_a2);
}


char*
OBDirectStubImpl_CaesarAlgorithm::decrypt(const ::CaesarAlgorithm::charsequence& _ob_a0,
                                          ::CORBA::ULong _ob_a1,
                                          ::CORBA::ULong _ob_a2)
{
    OB::InvocationHandler _ob_handler(this, "decrypt");
    return dynamic_cast<POA_CaesarAlgorithm*>(_ob_servant_) -> decrypt(_ob_a0, _ob_a1, _ob_a2);
}


::CORBA::Boolean
OBDirectStubImpl_CaesarAlgorithm::shutdown()
{
    OB::InvocationHandler _ob_handler(this, "shutdown");
    return dynamic_cast<POA_CaesarAlgorithm*>(_ob_servant_) -> shutdown();
}
