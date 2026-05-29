#pragma once

#include "mathDefines.h"
#include "3Vector.h"
#include "quaternion.h"

class C4X4Matrix;

class CPose  
{
public:
    CPose();
    CPose(const CPose& v);
    CPose(const CQuaternion& q);
    CPose(const C3Vector& x);
    CPose(const CQuaternion& q,const C3Vector& x);
    CPose(const C4X4Matrix& m);
    CPose(simReal angle,const C3Vector& pos,const C3Vector& dir);
    ~CPose();

    void setIdentity();
    C4X4Matrix getMatrix() const;
    CPose getInverse() const;
    void setMultResult(const CPose& v1,const CPose& v2);
    void buildInterpolation(const CPose& fromThis,const CPose& toThat,simReal t);
    void inverse();
    C3Vector getAxis(size_t index) const;
    void getData(simReal d[7],bool xyzwLayout=false) const;
    void setData(const simReal d[7],bool xyzwLayout=false);
    void setFromMatrix(const C4X4Matrix& m);

    simReal& operator() (size_t i);
    const simReal& operator() (size_t i) const;

    void operator*= (const CPose& v);

    CPose& operator= (const CPose& v);
    bool operator!= (const CPose& v);
    CPose operator* (const CPose& v) const;
    C3Vector operator* (const C3Vector& v) const;

    static const CPose identityTransformation;
    
    CQuaternion Q;
    C3Vector X;
};

using C7Vector = CPose; // for backward compatibility
