#pragma once
#include "v_repLib.h"
#include <string>

enum {  STACK_NULL=0,
        STACK_NUMBER,
        STACK_BOOL,
        STACK_STRING,
        STACK_ARRAY,
        STACK_MAP
};

class CStackObject
{
public:
    CStackObject();
    virtual ~CStackObject();

    virtual CStackObject* copyYourself();

    int getObjectType() const;

    static void buildItemOntoStack(int stackId,CStackObject* obj);
    static CStackObject* buildItemFromTopStackPosition(int stackId);

protected:
    int _objectType;
};
