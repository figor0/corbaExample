#include <fstream>
#include <CORBA.h>
#include <iostream>

#include "object.hh"

int main(int argc, char* argv[])
{
   try
   {
	  int op1 = 5, op2 = 13;
	  std::ifstream inp_file ("MyORef.ior");
	  if (!inp_file)
	  {
		  std::cout << "File MyORef.ior not found.\n";
		  return 1;
	  }
	  // Чтение объектной ссылки в строковом
	  // виде из файла
	  char str[1000];
	  inp_file >> str;
	  inp_file.close();
	  // Инициализация взаимодействия с CORBA
	  CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
	  // Получение объектной ссылки преобразованием
	  // из строки
	  CORBA::Object_var obj = orb->string_to_object (str);
	  MyInterface_var oRef = MyInterface::_narrow (obj);
	  if (CORBA::is_nil(oRef))
	  {
		 std::cout << "Failure during getting of object"
				 " reference\n";
	  }
	  else
	  {
		 // Вызов удаленного метода
		 int res = oRef->Summa (op1, op2);
		 std::cout << op1 << " + " << op2 << " = "
			  << res << std::endl;
	  }
   }
   catch(const CORBA::Exception& e)
   {
	   std::cerr << e._name() << std::endl;
	   return(1);
   }
   return 0;
}
