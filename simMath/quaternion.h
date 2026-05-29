#pragma once

#include "mathDefines.h"
#include "3Vector.h"
#include "3X3Matrix.h"

class CQuaternion  
{
public:
    CQuaternion();
    CQuaternion(simReal w,simReal x,simReal y,simReal z);
    CQuaternion(const simReal wxyz[4],bool xyzwLayout=false);
    CQuaternion(const C3Vector& v);
    CQuaternion(const CQuaternion& q);
    CQuaternion(simReal a,simReal b,simReal g);
    CQuaternion(simReal angle,const C3Vector& axis);
    CQuaternion(const C3Vector& startV,const C3Vector& endV);
    ~CQuaternion();

    void setEulerAngles(const C3Vector& v);
    void setEulerAngles(simReal a,simReal b,simReal g);
    void setAngleAndAxis(simReal angle,const C3Vector& axis);
    void setVectorMapping(const C3Vector& startV,const C3Vector& endV);
    void buildInterpolation(const CQuaternion& fromThis,const CQuaternion& toThat,simReal t);
    void buildInterpolation_otherWayRound(const CQuaternion& fromThis,const CQuaternion& toThat,simReal t);
    void buildRandomOrientation();

    simReal getAngleBetweenQuaternions(const CQuaternion& q) const;
    CQuaternion getAngleAndAxis() const;
    C3Vector getAngleAndAxis(simReal& angle) const;
    C3Vector getAxis(size_t index) const;
    C3X3Matrix getMatrix() const;
    C3Vector getEulerAngles() const;
    void getData(simReal wxyz[4],bool xyzwLayout=false) const;
    void setData(const float wxyz[4],bool xyzwLayout=false);
    void setData(const double wxyz[4],bool xyzwLayout=false);
    void normalize();
    void clear();
    void setIdentity();
    CQuaternion getInverse() const;
    void inverse();

    simReal& operator() (size_t i);
    const simReal& operator() (size_t i) const;

    void operator*= (simReal d);
    void operator*= (const CQuaternion& v);
    void operator/= (simReal d);
    void operator+= (const CQuaternion& v);

    CQuaternion& operator= (const CQuaternion& v);
    bool operator!= (const CQuaternion& v);
    CQuaternion operator* (const CQuaternion& v) const;
    C3Vector operator* (const C3Vector& v) const;
    CQuaternion operator* (simReal d) const;
    CQuaternion operator/ (simReal d) const;
    CQuaternion operator+ (const CQuaternion& v) const;

    static const CQuaternion identityRotation;

    simReal data[4]; // quaternion storage: wxyz
};

using C4Vector = CQuaternion; // for backward compatibility
