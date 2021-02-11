// Abdennour Kerboub G2



#include <OB/CORBAClient.h>
#include "crypt.h"

#ifndef OB_INTEGER_VERSION
#   error No ORBacus version defined! Is <OB/CORBA.h> included?
#endif

#ifndef OB_NO_VERSION_CHECK
#   if (OB_INTEGER_VERSION != 4030300L)
#       error ORBacus version mismatch!
#   endif
#endif

::OB::TypeCodeConst _tc_CaesarAlgorithm(
"010000000e00000034000000010000001800000049444c3a436165736172416c676f726974686"
"d3a312e300010000000436165736172416c676f726974686d00"
);

::OB::TypeCodeConst CaesarAlgorithm::_tc_charsequence(
"01ee917c15000000580000000106927c2500000049444c3a436165736172416c676f726974686"
"d2f6368617273657175656e63653a312e30009520100d0000006368617273657175656e636500"
"f6b900130000000c000000010000000900000000000000"
);


const char* CaesarAlgorithm::ids_[] =
{
    "IDL:CaesarAlgorithm:1.0",
    0
};

void
OBDuplicate(CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _add_ref();
}

void
OBRelease(CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _remove_ref();
}

CaesarAlgorithm_ptr
CaesarAlgorithm::_narrow(::CORBA::Object_ptr p)
{
    if(!::CORBA::is_nil(p))
    {
        CaesarAlgorithm_ptr v = 
            dynamic_cast< CaesarAlgorithm_ptr >(p);
        if(v)
            return _duplicate(v);

        if(p -> _is_a(ids_[0]))
        {
            OBProxy_CaesarAlgorithm* val = new OBProxy_CaesarAlgorithm;
            val -> _OB_copyFrom(p);
            return val;
        }
    }

    return _nil();
}

CaesarAlgorithm_ptr
CaesarAlgorithm::_narrow(::CORBA::AbstractBase_ptr p)
{
    if(!::CORBA::is_nil(p))
    {
        CaesarAlgorithm_ptr v =
            dynamic_cast< CaesarAlgorithm_ptr >(p);
        if(v)
            return _duplicate(v);

        ::CORBA::Object_var obj = p -> _to_object();
        return _narrow(obj);
    }
    return _nil();
}

CaesarAlgorithm_ptr
CaesarAlgorithm::_unchecked_narrow(::CORBA::Object_ptr p)
{
    if(!::CORBA::is_nil(p))
    {
        CaesarAlgorithm_ptr v =
            dynamic_cast< CaesarAlgorithm_ptr >(p);
        if(v)
            return _duplicate(v);

        OBProxy_CaesarAlgorithm* val = new OBProxy_CaesarAlgorithm;
        val -> _OB_copyFrom(p);
        return val;
    }

    return _nil();
}

CaesarAlgorithm_ptr
CaesarAlgorithm::_unchecked_narrow(::CORBA::AbstractBase_ptr p)
{
    if(!::CORBA::is_nil(p))
    {
        ::CORBA::Object_var obj = p -> _to_object();
        return _unchecked_narrow(obj);
    }
    return _nil();
}

const char**
CaesarAlgorithm::_OB_staticIds()
{
    return ids_;
}

void
OBMarshal(CaesarAlgorithm_ptr _ob_v, OB::OutputStreamImpl* _ob_out)
{
    _ob_out -> write_Object(_ob_v);
}

void
OBUnmarshal(CaesarAlgorithm_ptr& _ob_v, OB::InputStreamImpl* _ob_in)
{
    CaesarAlgorithm_var old = _ob_v;
    ::CORBA::Object_var p = _ob_in -> read_Object();

    if(!::CORBA::is_nil(p))
    {
        OBProxy_CaesarAlgorithm* _ob_obj = new OBProxy_CaesarAlgorithm;
        _ob_obj -> _OB_copyFrom(p);
        _ob_v = _ob_obj;
    }
    else
        _ob_v = CaesarAlgorithm::_nil();
}

void
operator<<=(::CORBA::Any& any, CaesarAlgorithm_ptr* v)
{
    any.replace(_tc_CaesarAlgorithm, (::CORBA::Object_ptr)*v, true);
}

void
operator<<=(::CORBA::Any& any, CaesarAlgorithm_ptr v)
{
    CaesarAlgorithm_ptr val = CaesarAlgorithm::_duplicate(v);
    any <<= &val;
}

::CORBA::Boolean
operator>>=(const ::CORBA::Any& any, CaesarAlgorithm_ptr& v)
{
    if(any.check_type(_tc_CaesarAlgorithm))
    {
        ::CORBA::Object_ptr val = (::CORBA::Object_ptr)any.value();

        if(!::CORBA::is_nil(val))
        {
            if(!(v = dynamic_cast< CaesarAlgorithm_ptr >(val)))
            {
                OBProxy_CaesarAlgorithm* obj = new OBProxy_CaesarAlgorithm;
                obj -> _OB_copyFrom(val);
                v = obj;
                (::CORBA::Any&)any <<= &v;
            }
        }
        else
            v = CaesarAlgorithm::_nil();

        return true;
    }
    else
        return false;
}


void
CaesarAlgorithm::OBInfo_charsequence::marshal(const void* _ob_v, OB::OutputStreamImpl* _ob_out) const
{
    const ::CaesarAlgorithm::charsequence& _ob_seq = *(const ::CaesarAlgorithm::charsequence*)_ob_v;
    ::CORBA::ULong _ob_len0 = _ob_seq.length();
    _ob_out -> write_ulong(_ob_len0);
    _ob_out -> write_char_array(_ob_seq.get_buffer(), _ob_len0);
}

void
CaesarAlgorithm::OBInfo_charsequence::unmarshal(void* _ob_v, OB::InputStreamImpl* _ob_in) const
{
    ::CaesarAlgorithm::charsequence& _ob_seq = *(::CaesarAlgorithm::charsequence*)_ob_v;
    ::CORBA::ULong _ob_len0 = _ob_in -> read_ulong();
    _ob_seq.length(_ob_len0);
    _ob_in -> read_char_array(_ob_seq.get_buffer(), _ob_len0);
}

void
operator<<=(::CORBA::Any& any, CaesarAlgorithm::charsequence* v)
{
    static const CaesarAlgorithm::OBInfo_charsequence info;
    any.replace(CaesarAlgorithm::_tc_charsequence, v, true, &info);
}

void
operator<<=(::CORBA::Any& any, const CaesarAlgorithm::charsequence& v)
{
    any <<= new CaesarAlgorithm::charsequence(v);
}

::CORBA::Boolean
operator>>=(const ::CORBA::Any& any, const CaesarAlgorithm::charsequence*& v)
{
    if(any.check_type(CaesarAlgorithm::_tc_charsequence))
    {
        if(!any.info())
        {
            OB::InputStream_var _ob_in = any.create_input_stream();
            CaesarAlgorithm::charsequence* val = new CaesarAlgorithm::charsequence;
            ::CORBA::ULong _ob_len0 = _ob_in -> read_ulong();
            (*val).length(_ob_len0);
            _ob_in -> read_char_array((*val).get_buffer(), _ob_len0);
            (::CORBA::Any&)any <<= val;
        }

        v = (CaesarAlgorithm::charsequence*)any.value();
        return true;
    }
    else
        return false;
}


OB::MarshalStubImpl_ptr
OBProxy_CaesarAlgorithm::_OB_createMarshalStubImpl()
{
    return new OBMarshalStubImpl_CaesarAlgorithm;
}

const char**
OBProxy_CaesarAlgorithm::_OB_ids() const
{
    return ::CaesarAlgorithm::ids_;
}


::CaesarAlgorithm::charsequence*
OBProxy_CaesarAlgorithm::encrypt(const char* _ob_a0,
                                 ::CORBA::ULong _ob_a1,
                                 ::CORBA::ULong _ob_a2)
{
    ::CORBA::ULong _ob_retry = 0, _ob_hop = 0;
    while(true)
    {
        try
        {
            OB::StubImplBase_var _ob_stubImplBase = _OB_getStubImpl();
            OBStubImpl_CaesarAlgorithm_ptr _ob_stubImpl = 
                dynamic_cast< OBStubImpl_CaesarAlgorithm_ptr>(_ob_stubImplBase.in());
            return _ob_stubImpl -> encrypt(_ob_a0, _ob_a1, _ob_a2);
        }
        catch(const OB::ExceptionBase& _ob_ex)
        {
            _OB_handleException(_ob_ex, _ob_retry, _ob_hop);
        }
    }
}


char*
OBProxy_CaesarAlgorithm::decrypt(const ::CaesarAlgorithm::charsequence& _ob_a0,
                                 ::CORBA::ULong _ob_a1,
                                 ::CORBA::ULong _ob_a2)
{
    ::CORBA::ULong _ob_retry = 0, _ob_hop = 0;
    while(true)
    {
        try
        {
            OB::StubImplBase_var _ob_stubImplBase = _OB_getStubImpl();
            OBStubImpl_CaesarAlgorithm_ptr _ob_stubImpl = 
                dynamic_cast< OBStubImpl_CaesarAlgorithm_ptr>(_ob_stubImplBase.in());
            return _ob_stubImpl -> decrypt(_ob_a0, _ob_a1, _ob_a2);
        }
        catch(const OB::ExceptionBase& _ob_ex)
        {
            _OB_handleException(_ob_ex, _ob_retry, _ob_hop);
        }
    }
}


::CORBA::Boolean
OBProxy_CaesarAlgorithm::shutdown()
{
    ::CORBA::ULong _ob_retry = 0, _ob_hop = 0;
    while(true)
    {
        try
        {
            OB::StubImplBase_var _ob_stubImplBase = _OB_getStubImpl();
            OBStubImpl_CaesarAlgorithm_ptr _ob_stubImpl = 
                dynamic_cast< OBStubImpl_CaesarAlgorithm_ptr>(_ob_stubImplBase.in());
            return _ob_stubImpl -> shutdown();
        }
        catch(const OB::ExceptionBase& _ob_ex)
        {
            _OB_handleException(_ob_ex, _ob_retry, _ob_hop);
        }
    }
}


void
OBDuplicate(OBStubImpl_CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _OB_incRef();
}

void
OBRelease(OBStubImpl_CaesarAlgorithm_ptr p)
{
    if(p)
        p -> _OB_decRef();
}


::CaesarAlgorithm::charsequence*
OBMarshalStubImpl_CaesarAlgorithm::encrypt(const char* _ob_a0,
                                           ::CORBA::ULong _ob_a1,
                                           ::CORBA::ULong _ob_a2)
{
    while(true)
    {
        OB::Downcall_var _ob_down = _OB_createDowncall("encrypt", true);
        try
        {
            OB::OutputStreamImpl* _ob_out = _OB_preMarshal(_ob_down);
            try
            {
                _ob_out -> write_string(_ob_a0);
                _ob_out -> write_ulong(_ob_a1);
                _ob_out -> write_ulong(_ob_a2);
            }
            catch(const ::CORBA::SystemException& _ob_ex)
            {
                _OB_marshalEx(_ob_down, _ob_ex);
            }
            _OB_postMarshal(_ob_down);
            _OB_request(_ob_down);
            bool _ob_uex;
            OB::InputStreamImpl* _ob_in = _OB_preUnmarshal(_ob_down, _ob_uex);
            if(_ob_uex)
            {
                _OB_postUnmarshal(_ob_down);
            }
            else
            {
                ::CaesarAlgorithm::charsequence_var _ob_r;
                try
                {
                    _ob_r = new ::CaesarAlgorithm::charsequence;
                    ::CORBA::ULong _ob_len0 = _ob_in -> read_ulong();
                    _ob_r -> length(_ob_len0);
                    _ob_in -> read_char_array(_ob_r -> get_buffer(), _ob_len0);
                }
                catch(const ::CORBA::SystemException& _ob_ex)
                {
                    _OB_unmarshalEx(_ob_down, _ob_ex);
                }
                _OB_postUnmarshal(_ob_down);
                return _ob_r._retn();
            }
        }
        catch(const OB::FailureException& _ob_ex)
        {
            _OB_handleFailureException(_ob_down, _ob_ex);
        }
    }
}


char*
OBMarshalStubImpl_CaesarAlgorithm::decrypt(const ::CaesarAlgorithm::charsequence& _ob_a0,
                                           ::CORBA::ULong _ob_a1,
                                           ::CORBA::ULong _ob_a2)
{
    while(true)
    {
        OB::Downcall_var _ob_down = _OB_createDowncall("decrypt", true);
        try
        {
            OB::OutputStreamImpl* _ob_out = _OB_preMarshal(_ob_down);
            try
            {
                ::CORBA::ULong _ob_len0 = _ob_a0.length();
                _ob_out -> write_ulong(_ob_len0);
                _ob_out -> write_char_array(_ob_a0.get_buffer(), _ob_len0);
                _ob_out -> write_ulong(_ob_a1);
                _ob_out -> write_ulong(_ob_a2);
            }
            catch(const ::CORBA::SystemException& _ob_ex)
            {
                _OB_marshalEx(_ob_down, _ob_ex);
            }
            _OB_postMarshal(_ob_down);
            _OB_request(_ob_down);
            bool _ob_uex;
            OB::InputStreamImpl* _ob_in = _OB_preUnmarshal(_ob_down, _ob_uex);
            if(_ob_uex)
            {
                _OB_postUnmarshal(_ob_down);
            }
            else
            {
                ::CORBA::String_var _ob_r;
                try
                {
                    _ob_r = _ob_in -> read_string();
                }
                catch(const ::CORBA::SystemException& _ob_ex)
                {
                    _OB_unmarshalEx(_ob_down, _ob_ex);
                }
                _OB_postUnmarshal(_ob_down);
                return _ob_r._retn();
            }
        }
        catch(const OB::FailureException& _ob_ex)
        {
            _OB_handleFailureException(_ob_down, _ob_ex);
        }
    }
}


::CORBA::Boolean
OBMarshalStubImpl_CaesarAlgorithm::shutdown()
{
    while(true)
    {
        OB::Downcall_var _ob_down = _OB_createDowncall("shutdown", true);
        try
        {
            _OB_preMarshal(_ob_down);
            _OB_postMarshal(_ob_down);
            _OB_request(_ob_down);
            bool _ob_uex;
            OB::InputStreamImpl* _ob_in = _OB_preUnmarshal(_ob_down, _ob_uex);
            if(_ob_uex)
            {
                _OB_postUnmarshal(_ob_down);
            }
            else
            {
                ::CORBA::Boolean _ob_r;
                try
                {
                    _ob_r = _ob_in -> read_boolean();
                }
                catch(const ::CORBA::SystemException& _ob_ex)
                {
                    _OB_unmarshalEx(_ob_down, _ob_ex);
                }
                _OB_postUnmarshal(_ob_down);
                return _ob_r;
            }
        }
        catch(const OB::FailureException& _ob_ex)
        {
            _OB_handleFailureException(_ob_down, _ob_ex);
        }
    }
}
