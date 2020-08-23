#include <fstream>
#include <CORBA.h>
#include <iostream>
#include "Servant.h"

int main(int argc, char* argv[])
{
   try
   {
	   CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
	   CORBA::Object_var obj_ptr = orb->resolve_initial_references("RootPOA");
	   PortableServer::POA_var poa_ptr = PortableServer::POA::_narrow(obj_ptr);
	   MyInterfaceImpl* servant = new MyInterfaceImpl;
	   CORBA::Object_ptr oRef = servant->_this();
	   PortableServer::ObjectId_var ench_id = poa_ptr->activate_object(servant);
	   CORBA::String_var str = orb->object_to_string (oRef);
	   std::ofstream oref_file ("MyORef.ior");
	   oref_file.write (str, strlen(str)+1);
	   oref_file.close();
	   PortableServer::POAManager_var pmanager = poa_ptr->the_POAManager();
	   pmanager->activate();
	   std::cout << "Waiting for client requests..." << std::endl;
	   orb->run();
   }
   catch(const CORBA::Exception& e)
   {
	   std::cerr << e._name() << std::endl;
	   return(1);
   }
   return 0;
}
