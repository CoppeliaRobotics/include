#pragma once

#include "mathDefines.h"
#include "3Vector.h"

class CQuaternion;

class C3X3Matrix  
{
public:
    C3X3Matrix();
    C3X3Matrix(const CQuaternion& q);
    C3X3Matrix(const C3X3Matrix& m);
    C3X3Matrix(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis);
    ~C3X3Matrix();

    void buildInterpolation(const C3X3Matrix& fromThis,const C3X3Matrix& toThat,simReal t); // rotation matrices only
    CQuaternion getQuaternion() const; // a proper rotation matrix is assumed
    void setEulerAngles(simReal a,simReal b,simReal g);
    void setEulerAngles(const C3Vector& v);
    C3Vector getEulerAngles() const; // in case of gimbal lock, alpha is returned as 0.0
    void buildXRotation(simReal angle);
    void buildYRotation(simReal angle);
    void buildZRotation(simReal angle);
    void normalize(); // Z axis is the reference; falls back to identity if Z is zero
    C3Vector getNormalVector() const;

    void clear();
    void setIdentity();
    void transpose();
    void setAxes(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis);
    void getData(simReal d[9]) const;
    void setData(const simReal d[9]);
    bool isValid() const;
    C3X3Matrix getTranspose() const;

    simReal& operator() (size_t i,size_t j);
    const simReal& operator() (size_t i,size_t j) const;

    void operator*= (const C3X3Matrix& m);
    void operator*= (simReal f);
    void operator/= (simReal f);
    void operator+= (const C3X3Matrix& m);
    void operator-= (const C3X3Matrix& m);

    C3X3Matrix& operator= (const C3X3Matrix& m);
    bool operator!= (const C3X3Matrix& m);
    C3X3Matrix operator* (const C3X3Matrix& m) const;
    C3Vector operator* (const C3Vector& v) const;
    C3X3Matrix operator* (simReal f) const;
    C3X3Matrix operator/ (simReal f) const;
    C3X3Matrix operator+ (const C3X3Matrix& m) const;
    C3X3Matrix operator- (const C3X3Matrix& m) const;

    C3Vector axis[3];
};
