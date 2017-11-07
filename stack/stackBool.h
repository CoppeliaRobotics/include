#pragma once

#include "stackObject.h"

class CStackBool : public CStackObject
{
public:
    CStackBool(bool theValue);
    virtual ~CStackBool();

    CStackObject* copyYourself();

    bool getValue();
    void setValue(bool theValue);

protected:
    bool _value;
};
