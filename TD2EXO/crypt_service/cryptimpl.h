// 	Abdennour Kerboub G2


#include <iostream>
#include <string>
#include <conio.h>

#include "OB/CORBA.h"
#include "crypt_skel.h"

class CryptographicImpl : virtual public ::POA_CaesarAlgorithm,
								virtual public PortableServer::RefCountServantBase
							
{			
	CORBA::ORB_var orb; 

	public:
		CryptographicImpl(CORBA::ORB_var orb)
		{
			this->orb = orb;
		}

	
		virtual ::CaesarAlgorithm::charsequence* encrypt(const char* info,::CORBA::ULong k,::CORBA::ULong shift) 
			throw(::CORBA::SystemException)
		{
			std::string msg = info;
			int len = msg.length();
			::CaesarAlgorithm::charsequence* outseq = new ::CaesarAlgorithm::charsequence;
			outseq->length(len + 1);
			std::string::iterator i = msg.begin();
			std::string::iterator end = msg.end();
			int j = 0;
			while (i != end)
			{
				 *i+= shift;
				 *i ^= k;
				 (*outseq)[j++] = *i++;
			}
			(*outseq)[len] = '\0';
			return outseq;

		}
			
		
	
		virtual char* decrypt(const ::CaesarAlgorithm::charsequence& info,::CORBA::ULong k,::CORBA::ULong shift) 
			throw(::CORBA::SystemException)
		{
			char* r = CORBA::string_alloc(info.length());
	
			for (int i = 0;i < info.length() - 1;i++)
			{				
				r[i]  = info[i];
				r[i] ^= k;
				r[i] -= shift;
				 
			}
			r[info.length() - 1] = '\0';
			return r;
		}	
	
		
		virtual ::CORBA::Boolean shutdown() throw(::CORBA::SystemException)
		{
			orb->shutdown(false);
			return true;
		}
};
