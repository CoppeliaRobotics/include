#pragma once

#include "stackObject.h"

class CStackNull : public CStackObject
{
public:
    CStackNull();
    virtual ~CStackNull();

    CStackObject* copyYourself();
};
