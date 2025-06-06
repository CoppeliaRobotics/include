#pragma once

#include "mathDefines.h"

bool isNumberOk(simReal v);
bool isNanOrInf(simReal v);
bool isNanOrInf(const simReal* arr, size_t cnt);
bool isFloatArrayOk(const simReal* arr, int cnt);
simReal robustAsin(simReal v);
simReal robustAcos(simReal v);
simReal robustMod(simReal v,simReal w);
