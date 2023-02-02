#pragma once

#include <math.h>
#include <limits>
#include <float.h>
#include <cstdlib>
#include <cmath>
#include "simTypes.h"

#ifdef SIM_MATH_DOUBLE
typedef double simReal;
#define FLOAT_MAX DBL_MAX
#define piValue (3.14159265359)
#define piValD2 (1.570796326794)
#define piValT2 (6.28318530718)
#define radToDeg (57.2957795130785499)
#define degToRad (0.017453292519944444)
#define SIM_RAND_FLOAT (static_cast<double>(rand())/static_cast<double>(RAND_MAX))
#else
typedef float simReal;
#define FLOAT_MAX FLT_MAX
#define piValue float(3.14159265359)
#define piValD2 float(1.570796326794)
#define piValT2 float(6.28318530718)
#define radToDeg float(57.2957795130785499)
#define degToRad float(0.017453292519944444)
#define SIM_RAND_FLOAT (static_cast<float>(rand())/static_cast<float>(RAND_MAX))
#endif

#define FLOATFLOAT_MAX FLT_MAX
#define SIM_MAX_INT INT_MAX
#define SIM_IS_NAN(x) ((std::isnan)(x))
#define SIM_IS_FINITE(x) ((std::isfinite)(x))
