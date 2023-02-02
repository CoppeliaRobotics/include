#include "MyMath.h"

CMath::CMath()
{
}

CMath::~CMath()
{
}

simReal CMath::robustAsin(simReal v)
{
    if (!isNumberOk(v))
        return(0.0);
    if (v>=1.0)
        return(piValD2);
    if (v<=-1.0)
        return(-piValD2);
    return(asin(v));
}

simReal CMath::robustAcos(simReal v)
{
    if (!isNumberOk(v))
        return(0.0);
    if (v>=1.0)
        return(0.0);
    if (v<=-1.0)
        return(piValue);
    return(acos(v));
}

simReal CMath::robustMod(simReal v,simReal w)
{
    if ( (!isNumberOk(v))||(!isNumberOk(w)) )
        return(0.0);
    if (w==0.0)
        return(0.0);
    return(fmod(v,w));
}

bool CMath::isNumberOk(simReal v)
{
    return ( (!SIM_IS_NAN(v))&&(fabs(v)!=std::numeric_limits<simReal>::infinity()) );
}
