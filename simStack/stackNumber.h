#pragma once

#include "stackObject.h"

class CStackNumber : public CStackObject
{
public:
    CStackNumber(double n);
    CStackNumber(int n);
    virtual ~CStackNumber();

    std::string toString() const;

    CStackObject* copyYourself();

    float getFloatValue() const;
    int getIntValue() const;
    long getLongValue() const;
    double getValue() const;
    bool isInt() const;
    void setFloatValue(float n);
    void setIntValue(int n);
    void setLongValue(long n);
    void setValue(double n);


protected:
    double _value;
    bool _isInt;
};
