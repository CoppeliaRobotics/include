#include "MyMath.h"
#include "3Vector.h"
#include "3X3Matrix.h"
#include "4X4Matrix.h"
#include "7Vector.h"

const C3Vector C3Vector::unitXVector(1.0,0.0,0.0);
const C3Vector C3Vector::unitYVector(0.0,1.0,0.0);
const C3Vector C3Vector::unitZVector(0.0,0.0,1.0);
const C3Vector C3Vector::zeroVector(0.0,0.0,0.0);

C3Vector::C3Vector()
{
}

C3Vector::C3Vector(simReal v0,simReal v1,simReal v2)
{
    data[0]=v0;
    data[1]=v1;
    data[2]=v2;
}

C3Vector::C3Vector(const simReal v[3])
{
    data[0]=v[0];
    data[1]=v[1];
    data[2]=v[2];
}

C3Vector::C3Vector(const C3Vector& v)
{
    (*this)=v;
}

C3Vector::~C3Vector()
{
}

simReal C3Vector::getAngle(const C3Vector& v) const
{ // Return value is in radian!!
    C3Vector a(getNormalized());
    C3Vector b(v.getNormalized());
    return(CMath::robustAcos(a*b));
}


C3X3Matrix C3Vector::getProductWithStar() const
{
    C3X3Matrix retM;
    retM(0,0)=0.0;
    retM(0,1)=-data[2];
    retM(0,2)=data[1];
    retM(1,0)=data[2];
    retM(1,1)=0.0;
    retM(1,2)=-data[0];
    retM(2,0)=-data[1];
    retM(2,1)=data[0];
    retM(2,2)=0.0;
    return(retM);
}

void C3Vector::operator*= (const C4X4Matrix& m)
{
//  (*this)=m*(*this);
    simReal x=data[0];
    simReal y=data[1];
    simReal z=data[2];
    data[0]=m.M.axis[0].data[0]*x+m.M.axis[1].data[0]*y+m.M.axis[2].data[0]*z+m.X.data[0];
    data[1]=m.M.axis[0].data[1]*x+m.M.axis[1].data[1]*y+m.M.axis[2].data[1]*z+m.X.data[1];
    data[2]=m.M.axis[0].data[2]*x+m.M.axis[1].data[2]*y+m.M.axis[2].data[2]*z+m.X.data[2];
}
void C3Vector::operator*= (const C3X3Matrix& m)
{
//  (*this)=m*(*this);
    simReal x=data[0];
    simReal y=data[1];
    simReal z=data[2];
    data[0]=m.axis[0].data[0]*x+m.axis[1].data[0]*y+m.axis[2].data[0]*z;
    data[1]=m.axis[0].data[1]*x+m.axis[1].data[1]*y+m.axis[2].data[1]*z;
    data[2]=m.axis[0].data[2]*x+m.axis[1].data[2]*y+m.axis[2].data[2]*z;
}


void C3Vector::operator*= (const C7Vector& transf)
{
    (*this)=transf*(*this);
}

void C3Vector::buildInterpolation(const C3Vector& fromThis,const C3Vector& toThat,simReal t)
{
    (*this)=fromThis+((toThat-fromThis)*t);
}

simReal* C3Vector::ptr()
{
    return(data);
}

bool C3Vector::isColinear(const C3Vector& v,simReal precision) const
{
    simReal scalProdSq=(*this)*v;
    scalProdSq=scalProdSq*scalProdSq;
    simReal l1=(*this)*(*this);
    simReal l2=v*v;
    return((scalProdSq/(l1*l2))>=precision);
}

simReal& C3Vector::operator() (size_t i)
{
    return(data[i]);
}

const simReal& C3Vector::operator() (size_t i) const
{
    return(data[i]);
}

simReal C3Vector::getLength() const
{
    return(sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]));
}

void C3Vector::setData(const float v[3])
{
    data[0]=(simReal)v[0];
    data[1]=(simReal)v[1];
    data[2]=(simReal)v[2];
}

void C3Vector::setData(const double v[3])
{
    data[0]=(simReal)v[0];
    data[1]=(simReal)v[1];
    data[2]=(simReal)v[2];
}

void C3Vector::getData(simReal v[3]) const
{
    v[0]=data[0];
    v[1]=data[1];
    v[2]=data[2];
}

void C3Vector::setData(simReal v0,simReal v1,simReal v2)
{
    data[0]=v0;
    data[1]=v1;
    data[2]=v2;
}

C3Vector C3Vector::getNormalized() const
{
    C3Vector retV;
    simReal l=sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]);
    if (l!=0.0)
    {
        retV(0)=data[0]/l;
        retV(1)=data[1]/l;
        retV(2)=data[2]/l;
        return(retV);
    }
    return(C3Vector::zeroVector);
}

void C3Vector::keepMax(const C3Vector& v)
{
    if (v(0)>data[0])
        data[0]=v(0);
    if (v(1)>data[1])
        data[1]=v(1);
    if (v(2)>data[2])
        data[2]=v(2);
}

void C3Vector::keepMin(const C3Vector& v)
{
    if (v(0)<data[0])
        data[0]=v(0);
    if (v(1)<data[1])
        data[1]=v(1);
    if (v(2)<data[2])
        data[2]=v(2);
}

bool C3Vector::isValid() const
{
    return((SIM_IS_FINITE(data[0])!=0)&&(SIM_IS_FINITE(data[1])!=0)&&(SIM_IS_FINITE(data[2])!=0)&&(SIM_IS_NAN(data[0])==0)&&(SIM_IS_NAN(data[1])==0)&&(SIM_IS_NAN(data[2])==0));
}

void C3Vector::normalize()
{
    simReal l=sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]);
    if (l!=0.0)
    {
        data[0]=data[0]/l;
        data[1]=data[1]/l;
        data[2]=data[2]/l;
    }
}

void C3Vector::clear()
{
    data[0]=0.0;
    data[1]=0.0;
    data[2]=0.0;
}

C3Vector C3Vector::operator/ (simReal d) const
{
    C3Vector retV;
    retV(0)=data[0]/d;
    retV(1)=data[1]/d;
    retV(2)=data[2]/d;
    return(retV);
}

void C3Vector::operator/= (simReal d)
{
    data[0]/=d;
    data[1]/=d;
    data[2]/=d;
}

C3Vector C3Vector::operator* (simReal d) const
{
    C3Vector retV;
    retV(0)=data[0]*d;
    retV(1)=data[1]*d;
    retV(2)=data[2]*d;
    return(retV);
}

void C3Vector::operator*= (simReal d)
{
    data[0]*=d;
    data[1]*=d;
    data[2]*=d;
}

C3Vector& C3Vector::operator= (const C3Vector& v)
{
    data[0]=v(0);
    data[1]=v(1);
    data[2]=v(2);
    return(*this);
}

bool C3Vector::operator!= (const C3Vector& v)
{
    return( (data[0]!=v(0))||(data[1]!=v(1))||(data[2]!=v(2)) );
}

C3Vector C3Vector::operator+ (const C3Vector& v) const
{
    C3Vector retV;
    retV(0)=data[0]+v(0);
    retV(1)=data[1]+v(1);
    retV(2)=data[2]+v(2);
    return(retV);
}

void C3Vector::operator+= (const C3Vector& v)
{
    data[0]+=v(0);
    data[1]+=v(1);
    data[2]+=v(2);
}

C3Vector C3Vector::operator- (const C3Vector& v) const
{
    C3Vector retV;
    retV(0)=data[0]-v(0);
    retV(1)=data[1]-v(1);
    retV(2)=data[2]-v(2);
    return(retV);
}

void C3Vector::operator-= (const C3Vector& v)
{
    data[0]-=v(0);
    data[1]-=v(1);
    data[2]-=v(2);
}

C3Vector C3Vector::operator^ (const C3Vector& v) const
{ // Cross product
    C3Vector retV;
    retV(0)=data[1]*v(2)-data[2]*v(1);
    retV(1)=data[2]*v(0)-data[0]*v(2);
    retV(2)=data[0]*v(1)-data[1]*v(0);
    return(retV);
}

void C3Vector::operator^= (const C3Vector& v)
{ // Cross product
    C3Vector retV;
    retV(0)=data[1]*v(2)-data[2]*v(1);
    retV(1)=data[2]*v(0)-data[0]*v(2);
    retV(2)=data[0]*v(1)-data[1]*v(0);
    data[0]=retV(0);
    data[1]=retV(1);
    data[2]=retV(2);
}

simReal C3Vector::operator* (const C3Vector& v) const
{ // Scalar product
    return(data[0]*v.data[0]+data[1]*v.data[1]+data[2]*v.data[2]);
}
