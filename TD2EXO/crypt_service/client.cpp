// Codeproject: A simple C++ client/server application with CORBA
// Abdennour Kerboub G2


#include <iostream>
#include <string>
#include "OB/CORBA.h"
#include "OB/Cosnaming.h"
#include "crypt.h"


using namespace std;

int main(int argc, char** argv)
{


	CORBA::ORB_var orb;
	
	try {	
		
		
		orb = CORBA::ORB_init(argc, argv);
		
	
		CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
		CosNaming::NamingContext_var nc = 
				CosNaming::NamingContext::_narrow(rootContextObj.in());
	       
		CosNaming::Name name;
		name.length(1);
		name[0].id = (const char *) "CryptographicService";
		name[0].kind = (const char *) "";
	
		CORBA::Object_var managerObj = nc->resolve(name);
	
		::CaesarAlgorithm_var manager = 
			::CaesarAlgorithm::_narrow(managerObj.in());

		string info_in,exit,dummy; 
		CORBA::String_var info_out;
		::CaesarAlgorithm::charsequence_var inseq;
		unsigned long key,shift;
		
		try{

			do{
				cout << "\nCryptographic service client" << endl;
				cout << "----------------------------" << endl;
		
				do{ 
					if (cin.fail())
					{
						cin.clear();
						cin >> dummy;
					}
					cout << "Enter encryption key: ";	
					cin >> key;

				} while (cin.fail());
				
				do{ 
					if (cin.fail())
					{
						cin.clear();
						cin >> dummy;
					}
					cout << "Enter a shift: ";	
					cin >> shift;

				} while (cin.fail());
				
				
				getline(cin,dummy); 
				cout << "Enter a plain text to encrypt: ";
				getline(cin,info_in);
		
			
				inseq = manager->encrypt(info_in.c_str(),key,shift);
				cout << "----------------------------------------------" << endl;
				cout << "Encrypted text is: " << inseq->get_buffer() << endl;
				// Invoke second remote method
				info_out = manager->decrypt(inseq.in(),key,shift);
				cout << "Decrypted text is: " << info_out.in() << endl;
				cout << "----------------------------------------------" << endl;
				cout << "Exit? (y/n): "; 
				cin >> exit;
			} while (exit!="y");

		
			manager->shutdown();

		} catch(const std::exception& std_e){
			cerr << std_e.what() << endl;
		  }
	}catch(const CORBA::Exception& e) {
	
		cerr << e << endl;
   }
  
	if (!CORBA::is_nil(orb)){
		try{		
			orb->destroy(); 
			cout << "Ending CORBA..." << endl;
		} catch(const CORBA::Exception& e)
		{
			cout << "orb->destroy failed:" << e << endl;
			return 1;
		}
   }
   return 0;
}
