#pragma once

#include "mathDefines.h"

class C3X3Matrix;
class C4X4Matrix;
class C7Vector;

class C3Vector  
{
public:

    C3Vector();
    C3Vector(simReal v0,simReal v1,simReal v2);
    C3Vector(const simReal v[3]);
    C3Vector(const C3Vector& v);
    ~C3Vector();

    void buildInterpolation(const C3Vector& fromThis,const C3Vector& toThat,simReal t);
    simReal getAngle(const C3Vector& v) const;
    C3X3Matrix getProductWithStar() const;
    simReal* ptr();
    bool isColinear(const C3Vector& v,simReal precision) const;
    simReal getLength() const;
    void setData(const float v[3]);
    void setData(const double v[3]);
    void getData(simReal v[3]) const;
    void setData(simReal v0,simReal v1,simReal v2);
    C3Vector getNormalized() const;
    void keepMax(const C3Vector& v);
    void keepMin(const C3Vector& v);
    bool isValid() const;
    void normalize();
    void clear();

    simReal& operator() (size_t i);
    const simReal& operator() (size_t i) const;

    void operator*= (const C4X4Matrix& m);
    void operator*= (const C3X3Matrix& m);
    void operator*= (const C7Vector& transf);
    void operator*= (simReal d);
    void operator/= (simReal d);
    void operator+= (const C3Vector& v);
    void operator-= (const C3Vector& v);
    void operator^= (const C3Vector& v);

    C3Vector& operator= (const C3Vector& v);
    bool operator!= (const C3Vector& v);
    C3Vector operator* (simReal d) const;
    simReal operator* (const C3Vector& v) const;
    C3Vector operator/ (simReal d) const;
    C3Vector operator+ (const C3Vector& v) const;
    C3Vector operator- (const C3Vector& v) const;
    C3Vector operator^ (const C3Vector& v) const;

    static const C3Vector unitXVector;
    static const C3Vector unitYVector;
    static const C3Vector unitZVector;
    static const C3Vector zeroVector;

    simReal data[3];
};




