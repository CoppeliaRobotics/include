#pragma once

#include "mathDefines.h"
#include "3Vector.h"

class C4Vector;

class C3X3Matrix  
{
public:
    C3X3Matrix();
    C3X3Matrix(const C4Vector& q);
    C3X3Matrix(const C3X3Matrix& m);
    C3X3Matrix(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis);
    ~C3X3Matrix();

    void buildInterpolation(const C3X3Matrix& fromThis,const C3X3Matrix& toThat,simReal t);
    C4Vector getQuaternion() const;
    void setEulerAngles(simReal a,simReal b,simReal g);
    void setEulerAngles(const C3Vector& v);
    C3Vector getEulerAngles() const;
    void buildXRotation(simReal angle);
    void buildYRotation(simReal angle);
    void buildZRotation(simReal angle);
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
    C3X3Matrix operator* (const C3X3Matrix& m) const;
    C3Vector operator* (const C3Vector& v) const;
    C3X3Matrix operator* (simReal f) const;
    C3X3Matrix operator/ (simReal f) const;
    C3X3Matrix operator+ (const C3X3Matrix& m) const;
    C3X3Matrix operator- (const C3X3Matrix& m) const;

    C3Vector axis[3];
};
