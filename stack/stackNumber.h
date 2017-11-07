#pragma once

#include "stackObject.h"

class CStackNumber : public CStackObject
{
public:
    CStackNumber(double n);
    virtual ~CStackNumber();

    CStackObject* copyYourself();

    float getFloatValue();
    double getValue();
    void setFloatValue(float n);
    void setValue(double n);

protected:
    double _value;
};
