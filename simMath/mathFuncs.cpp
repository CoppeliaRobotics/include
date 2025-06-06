#include "mathFuncs.h"

bool isNumberOk(simReal v)
{
    return ( (!SIM_IS_NAN(v))&&(fabs(v)!=std::numeric_limits<simReal>::infinity()) );
}

bool isNanOrInf(simReal v)
{
    return std::isnan(v) || (fabs(v) == std::numeric_limits<simReal>::infinity());
}

bool isNanOrInf(const simReal* arr, size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        if (std::isnan(arr[i]) || (fabs(arr[i]) == std::numeric_limits<simReal>::infinity()))
            return true;
    }
    return false;
}

bool isFloatArrayOk(const simReal* arr,int cnt)
{
    bool retVal=true;
    for (int i=0;i<cnt;i++)
    {
        simReal v=arr[i];
        if ( (SIM_IS_NAN(v)) )//||(fabs(v)==std::numeric_limits<simReal>::infinity()) )
        {
            retVal=false;
            break;
        }
    }
    return(retVal);
}

simReal robustAsin(simReal v)
{
    if (!isNumberOk(v))
        return(0.0);
    if (v>=1.0)
        return(piValD2);
    if (v<=-1.0)
        return(-piValD2);
    return(asin(v));
}

simReal robustAcos(simReal v)
{
    if (!isNumberOk(v))
        return(0.0);
    if (v>=1.0)
        return(0.0);
    if (v<=-1.0)
        return(piValue);
    return(acos(v));
}

simReal robustMod(simReal v,simReal w)
{
    if ( (!isNumberOk(v))||(!isNumberOk(w)) )
        return(0.0);
    if (w==0.0)
        return(0.0);
    return(fmod(v,w));
}
