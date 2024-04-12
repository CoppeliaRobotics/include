#include "stackNumber.h"
#include <sstream>

CStackNumber::CStackNumber(double n)
{
    _objectType=STACK_NUMBER;
    _value=n;
    _isInt = false;
}

CStackNumber::CStackNumber(int n)
{
    _objectType=STACK_NUMBER;
    _value=(double)n;
    _isInt = true;
}

CStackNumber::~CStackNumber()
{
}

std::string CStackNumber::toString() const
{
    std::stringstream ss;
    ss << _value;
    return(ss.str());
}

float CStackNumber::getFloatValue() const
{
    return((float)_value);
}

int CStackNumber::getIntValue() const
{
    return((int)_value);
}

long CStackNumber::getLongValue() const
{
    return((long)_value);
}

double CStackNumber::getValue() const
{
    return(_value);
}

bool CStackNumber::isInt() const
{
    return _isInt;
}

void CStackNumber::setFloatValue(float n)
{
    _value=(double)n;
    _isInt = false;
}

void CStackNumber::setIntValue(int n)
{
    _value=(int)n;
    _isInt = true;
}

void CStackNumber::setLongValue(long n)
{
    _value=(long)n;
    _isInt = true;
}

void CStackNumber::setValue(double n)
{
    _value=n;
}

CStackObject* CStackNumber::copyYourself()
{
    CStackNumber* retVal=new CStackNumber(_value);
    return(retVal);
}
