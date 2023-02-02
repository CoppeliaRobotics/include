#pragma once

#include "mathDefines.h"

class CMath  
{
public:
    CMath();
    virtual ~CMath();

    static simReal robustAsin(simReal v);
    static simReal robustAcos(simReal v);
    static simReal robustMod(simReal v,simReal w);
    static bool isNumberOk(simReal v);
};
