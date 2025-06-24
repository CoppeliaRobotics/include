#include "stackNull.h"
#include <simLib/simLib.h>

CStackNull::CStackNull()
{
    _objectType=STACK_NULL;
}

CStackNull::~CStackNull()
{
}

std::string CStackNull::toString() const
{
    return("nil");
}

CStackObject* CStackNull::copyYourself()
{
    CStackNull* retVal=new CStackNull();
    return(retVal);
}
