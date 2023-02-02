#pragma once

#include "mathDefines.h"
#include "3Vector.h"
#include "3X3Matrix.h"

class C4Vector  
{
public:
    C4Vector();
    C4Vector(simReal w,simReal x,simReal y,simReal z);
    C4Vector(const simReal wxyz[4],bool xyzwLayout=false);
    C4Vector(const C3Vector& v);
    C4Vector(const C4Vector& q);
    C4Vector(simReal a,simReal b,simReal g);
    C4Vector(simReal angle,const C3Vector& axis);
    C4Vector(const C3Vector& startV,const C3Vector& endV);
    ~C4Vector();

    void setEulerAngles(const C3Vector& v);
    void setEulerAngles(simReal a,simReal b,simReal g);
    void setAngleAndAxis(simReal angle,const C3Vector& axis);
    void setVectorMapping(const C3Vector& startV,const C3Vector& endV);
    void buildInterpolation(const C4Vector& fromThis,const C4Vector& toThat,simReal t);
    void buildInterpolation_otherWayRound(const C4Vector& fromThis,const C4Vector& toThat,simReal t);
    void buildRandomOrientation();

    simReal getAngleBetweenQuaternions(const C4Vector& q) const;
    C4Vector getAngleAndAxis() const;
    C3Vector getAngleAndAxis(simReal& angle) const;
    C3Vector getAxis(size_t index) const;
    C3X3Matrix getMatrix() const;
    C3Vector getEulerAngles() const;
    void getData(simReal wxyz[4],bool xyzwLayout=false) const;
    void setData(const simReal wxyz[4],bool xyzwLayout=false);
    void normalize();
    void clear();
    void setIdentity();
    C4Vector getInverse() const;
    void inverse();

    simReal& operator() (size_t i);
    const simReal& operator() (size_t i) const;

    void operator*= (simReal d);
    void operator*= (const C4Vector& v);
    void operator/= (simReal d);
    void operator+= (const C4Vector& v);

    C4Vector& operator= (const C4Vector& v);
    bool operator!= (const C4Vector& v);
    C4Vector operator* (const C4Vector& v) const;
    C3Vector operator* (const C3Vector& v) const;
    C4Vector operator* (simReal d) const;
    C4Vector operator/ (simReal d) const;
    C4Vector operator+ (const C4Vector& v) const;

    static const C4Vector identityRotation;

    simReal data[4]; // quaternion storage: wxyz
};
