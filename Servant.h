#include "object.hh"

class MyInterfaceImpl : public POA_MyInterface
{
public:
   MyInterfaceImpl () {}
   CORBA::Long Summa(CORBA::Long _op1,
					 CORBA::Long _op2);
};


