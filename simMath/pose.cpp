#include "pose.h"
#include "4X4Matrix.h"

const CPose CPose::identityTransformation(CQuaternion(1.0,0.0,0.0,0.0),C3Vector(0.0,0.0,0.0));

CPose::CPose()
{
}

CPose::CPose(const CPose& v)
{
    (*this)=v;
}

CPose::CPose(const CQuaternion& q)
{
    Q=q;
    X.clear();
}

CPose::CPose(const C3Vector& x)
{
    X=x;
    Q.setIdentity();
}

CPose::CPose(const CQuaternion& q,const C3Vector& x)
{
    Q=q;
    X=x;
}

CPose::CPose(const C4X4Matrix& m)
{
    setFromMatrix(m);
}

CPose::CPose(simReal angle,const C3Vector& pos,const C3Vector& dir)
{ // Builds a rotation around dir at position pos of angle angle (in radians)
    CPose shift1;
    shift1.setIdentity();
    shift1.X(0)=-pos(0);
    shift1.X(1)=-pos(1);
    shift1.X(2)=-pos(2);
    CPose shift2;
    shift2.setIdentity();
    shift2.X=pos;
    CPose rot;
    rot.setIdentity();
    rot.Q.setAngleAndAxis(angle,dir);
    (*this)=shift2*rot*shift1;
}


CPose::~CPose()
{

}

C3Vector CPose::getAxis(size_t index) const
{
    return(Q.getAxis(index));
}

void CPose::setIdentity()
{
    Q.setIdentity();
    X.clear();
}

C4X4Matrix CPose::getMatrix() const
{
    return(C4X4Matrix(Q.getMatrix(),X));
}

CPose& CPose::operator= (const CPose& v)
{
    Q=v.Q;
    X=v.X;
    return(*this);
}

void CPose::setMultResult(const CPose& v1,const CPose& v2)
{
    X=v1.X+(v1.Q*v2.X);
    Q=v1.Q*v2.Q;
}

CPose CPose::operator* (const CPose& v) const
{ // Transformation multiplication
    CPose retV;
    retV.X=X+(Q*v.X);
    retV.Q=Q*v.Q;
    retV.Q.normalize();
    return(retV);
}

void CPose::operator*= (const CPose& v)
{ 
    X+=(Q*v.X);
    Q*=v.Q;
}

C3Vector CPose::operator* (const C3Vector& v) const
{ // Vector transformation
    return(X+(Q*v)); 
}

void CPose::inverse()
{
    (*this)=getInverse();
}

CPose CPose::getInverse() const
{
    CPose retV;
    retV.Q=Q.getInverse();
    retV.X=(retV.Q*X)*-1.0;
    return(retV);
}

void CPose::buildInterpolation(const CPose& fromThis,const CPose& toThat,simReal t)
{   // Builds the interpolation (based on t) from 'fromThis' to 'toThat'
    Q.buildInterpolation(fromThis.Q,toThat.Q,t);
    X.buildInterpolation(fromThis.X,toThat.X,t);
}

void CPose::getData(simReal d[7],bool xyzwLayout/*=false*/) const
{
    X.getData(d+0);
    Q.getData(d+3,xyzwLayout);
}

void CPose::setData(const simReal d[7],bool xyzwLayout/*=false*/)
{
    X.setData(d+0);
    Q.setData(d+3,xyzwLayout);
}


bool CPose::operator!= (const CPose& v)
{
    return( (Q!=v.Q)||(X!=v.X) );
}

simReal& CPose::operator() (size_t i)
{
    if (i<3)
        return(X(i));
    else
        return(Q(i-3));
}

const simReal& CPose::operator() (size_t i) const
{
    if (i<3)
        return(X(i));
    else
        return(Q(i-3));
}

void CPose::setFromMatrix(const C4X4Matrix& m)
{
    (*this)=m.getTransformation();
}
