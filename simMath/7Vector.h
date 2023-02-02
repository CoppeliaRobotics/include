#pragma once

#include "mathDefines.h"
#include "3Vector.h"
#include "4Vector.h"

class C4X4Matrix;

class C7Vector  
{
public:
    C7Vector();
    C7Vector(const C7Vector& v);
    C7Vector(const C4Vector& q);
    C7Vector(const C3Vector& x);
    C7Vector(const C4Vector& q,const C3Vector& x);
    C7Vector(const C4X4Matrix& m);
    C7Vector(simReal angle,const C3Vector& pos,const C3Vector& dir);
    ~C7Vector();

    void setIdentity();
    C4X4Matrix getMatrix() const;
    C7Vector getInverse() const;
    void setMultResult(const C7Vector& v1,const C7Vector& v2);
    void buildInterpolation(const C7Vector& fromThis,const C7Vector& toThat,simReal t);
    void inverse();
    C3Vector getAxis(size_t index) const;
    void getData(simReal d[7],bool xyzwLayout=false) const;
    void setData(const simReal d[7],bool xyzwLayout=false);
    void setFromMatrix(const C4X4Matrix& m);

    simReal& operator() (size_t i);
    const simReal& operator() (size_t i) const;

    void operator*= (const C7Vector& v);

    C7Vector& operator= (const C7Vector& v);
    bool operator!= (const C7Vector& v);
    C7Vector operator* (const C7Vector& v) const;
    C3Vector operator* (const C3Vector& v) const;

    static const C7Vector identityTransformation;
    
    C4Vector Q;
    C3Vector X;
};
