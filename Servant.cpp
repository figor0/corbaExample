#include "Servant.h"

CORBA::Long MyInterfaceImpl::Summa(CORBA::Long _op1, CORBA::Long _op2)
{
	return _op1 + _op2;
}
