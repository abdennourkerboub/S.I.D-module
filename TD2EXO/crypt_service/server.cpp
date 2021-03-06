// 	Abdennour Kerboub G2

#include <iostream>
#include "OB/CORBA.h"
#include <OB/Cosnaming.h>
#include "crypt.h"
#include "cryptimpl.h"

using namespace std;

int main(int argc, char** argv)
{

	CORBA::ORB_var orb;
	CryptographicImpl* CrypImpl = NULL;

	try {
		
		orb = CORBA::ORB_init(argc, argv);
		
		CORBA::Object_var rootPOAObj = orb->resolve_initial_references("RootPOA");
		
		PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(rootPOAObj.in());
		
		
		CORBA::PolicyList policies;
		policies.length(1);
		
		policies[0] = 
			rootPOA->create_thread_policy(PortableServer::SINGLE_THREAD_MODEL);
		
		
		PortableServer::POAManager_var manager = rootPOA->the_POAManager();
		
		
		PortableServer::POA_var myPOA = rootPOA->create_POA("myPOA", manager, policies);

		
		CORBA::ULong len = policies.length();
		for (CORBA::ULong i = 0; i < len; i++) 
			policies[i]->destroy();

		
		CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
		
		CosNaming::NamingContext_var nc =
			CosNaming::NamingContext::_narrow(rootContextObj.in());

		
		CrypImpl = new CryptographicImpl(orb);	
		
		PortableServer::ObjectId_var myObjID = myPOA->activate_object(CrypImpl);
		
		CORBA::Object_var o = myPOA->servant_to_reference(CrypImpl);
		
		CORBA::String_var s = orb->object_to_string(o);
		cout << "The IOR of the object is: " << s.in() << endl;

		CosNaming::Name name;
		name.length(1);
		name[0].id = (const char *) "CryptographicService";
		name[0].kind = (const char *) "";
		
		nc->rebind(name,o);
	  
		
		manager->activate();
		cout << "The server is ready. Awaiting for incoming requests..." << endl;
		
		orb->run();
        	
	} catch(const CORBA::Exception& e) {
		
		cerr << e << endl;
  }
  
 
  if (CrypImpl)
		CrypImpl->_remove_ref();

  
  if (!CORBA::is_nil(orb)){
	  try{
		orb->destroy(); 
		cout << "Ending CORBA..." << endl;
	  } catch (const CORBA::Exception& e)
	  {
		  cout << "orb->destroy() failed:" << e << endl;
		  return 1;		
	  }
  }
  return 0;
}
