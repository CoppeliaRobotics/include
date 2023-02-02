#include "4Vector.h"
#include "MyMath.h"

const C4Vector C4Vector::identityRotation(1.0,0.0,0.0,0.0);

C4Vector::C4Vector()
{
}

C4Vector::C4Vector(simReal w,simReal x,simReal y,simReal z)
{
    data[0]=w;
    data[1]=x;
    data[2]=y;
    data[3]=z;
    // We don't normalize here
}

C4Vector::C4Vector(const simReal wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=wxyz[3];
        data[1]=wxyz[0];
        data[2]=wxyz[1];
        data[3]=wxyz[2];
    }
    else
    {
        data[0]=wxyz[0];
        data[1]=wxyz[1];
        data[2]=wxyz[2];
        data[3]=wxyz[3];
    }
    // We don't normalize here
}

C4Vector::C4Vector(const C4Vector& q)
{
    data[0]=q(0);
    data[1]=q(1);
    data[2]=q(2);
    data[3]=q(3);
    // We don't normalize here
}

C4Vector::C4Vector(const C3Vector& v)
{ // Alpha, beta and gamma are in radians!
    setEulerAngles(v);
}

C4Vector::C4Vector(simReal a,simReal b,simReal g)
{ // Alpha, beta and gamma are in radians!
    setEulerAngles(a,b,g);
}

C4Vector::C4Vector(simReal angle,const C3Vector& axis)
{ // Builds a rotation quaternion around axis (angle in radian!)
    setAngleAndAxis(angle,axis);
}

C4Vector::C4Vector(const C3Vector& startV,const C3Vector& endV)
{
    setVectorMapping(startV,endV);
}

C4Vector::~C4Vector()
{

}

void C4Vector::setEulerAngles(simReal a,simReal b,simReal g)
{ // a,b anf g are in radian!
    C4Vector vx(a,C3Vector(1.0,0.0,0.0));
    C4Vector vy(b,C3Vector(0.0,1.0,0.0));
    C4Vector vz(g,C3Vector(0.0,0.0,1.0));
    (*this)=vx*vy*vz;
}

void C4Vector::setEulerAngles(const C3Vector& v)
{ // v(0), v(1) and v(2) are in radian!
    setEulerAngles(v(0),v(1),v(2));
}

void C4Vector::setAngleAndAxis(simReal angle,const C3Vector& axis)
{ // angle in radian!
    C3Vector axisTmp=axis;
    axisTmp.normalize();
    simReal sinA=sin(angle/2.0);
    data[1]=axisTmp(0)*sinA;
    data[2]=axisTmp(1)*sinA;
    data[3]=axisTmp(2)*sinA;
    data[0]=cos(angle/2.0);
}

void C4Vector::setVectorMapping(const C3Vector& startV,const C3Vector& endV)
{
    C3Vector v0(startV.getNormalized());
    C3Vector v1(endV.getNormalized());
    C3Vector cross(v0^v1);
    simReal cosAngle=v0*v1;
    if (cosAngle>1.0)
        setIdentity();
    else
        setAngleAndAxis(CMath::robustAcos(cosAngle),cross);
}

C3Vector C4Vector::getAngleAndAxis(simReal& angle) const
{
    C3Vector retV;
    C4Vector d(*this);
    if (d(0)<0.0)
        d=d*-1.0;
    simReal l=sqrt(d(0)*d(0)+d(1)*d(1)+d(2)*d(2)+d(3)*d(3));
    simReal cosA=d(0)/l; // Quaternion needs to be normalized
    if (cosA>1.0) // Just make sure..
        cosA=1.0;
    angle=CMath::robustAcos(cosA)*2.0;
    if (angle>0.000001)
    {
        simReal sinA=sqrt(1.0-cosA*cosA);
        if (fabs(sinA)<simReal(0.00005))
            sinA=1.0;
        else
            sinA*=l; // Quaternion needs to be normalized
        retV(0)=d(1)/sinA;
        retV(1)=d(2)/sinA;
        retV(2)=d(3)/sinA;
    }
    else
    {
        retV(0)=0.0;
        retV(1)=0.0;
        retV(2)=1.0;
    }
    return(retV);
}

C4Vector C4Vector::getAngleAndAxis() const
{ // Returned vector is (angle,x,y,z) (angle is in radians)
    simReal angle;
    C3Vector a(getAngleAndAxis(angle));
    C4Vector retVal(angle,a(0),a(1),a(2));
    return(retVal);
}

C3Vector C4Vector::getEulerAngles() const
{
    return(getMatrix().getEulerAngles());
}

simReal C4Vector::getAngleBetweenQuaternions(const C4Vector& q) const
{
    simReal angle=fabs(data[0]*q(0)+data[1]*q(1)+data[2]*q(2)+data[3]*q(3));
    return(CMath::robustAcos(angle)*2.0);
}

void C4Vector::buildInterpolation(const C4Vector& fromThis,const C4Vector& toThat,simReal t)
{
    C4Vector AA(fromThis);
    C4Vector BB(toThat);
    if (AA(0)*BB(0)+AA(1)*BB(1)+AA(2)*BB(2)+AA(3)*BB(3)<0.0)
        AA=AA*-1.0;
    C4Vector r((AA.getInverse()*BB).getAngleAndAxis());
    (*this)=(AA*C4Vector(r(0)*t,C3Vector(r(1),r(2),r(3))));
    // Already normalized through * operator
}

void C4Vector::buildInterpolation_otherWayRound(const C4Vector& fromThis,const C4Vector& toThat,simReal t)
{
    C4Vector AA(fromThis);
    C4Vector BB(toThat);
    if (AA(0)*BB(0)+AA(1)*BB(1)+AA(2)*BB(2)+AA(3)*BB(3)<0.0)
        AA=AA*-1.0;
    C4Vector r((AA.getInverse()*BB).getAngleAndAxis());

    // r(0) is the rotation angle
    // r(1),r(2),r(3) is the rotation axis
    // Here, since we want to rotate the other way round, we inverse the axis and rotate by 2*pi-r(0) instead:
    (*this)=(AA*C4Vector((piValT2-r(0))*t,C3Vector(r(1)*-1.0,r(2)*-1.0,r(3)*-1.0)));
    // Already normalized through * operator
}

void C4Vector::buildRandomOrientation()
{
    C3Vector u(SIM_RAND_FLOAT,SIM_RAND_FLOAT,SIM_RAND_FLOAT);
    data[0]=sqrt(1.0-u(0))*sin(piValT2*u(1));
    data[1]=sqrt(1.0-u(0))*cos(piValT2*u(1));
    data[2]=sqrt(u(0))*sin(piValT2*u(2));
    data[3]=sqrt(u(0))*cos(piValT2*u(2));
}

void C4Vector::getData(simReal wxyz[4],bool xyzwLayout/*=false*/) const
{
    if (xyzwLayout)
    {
        wxyz[3]=data[0];
        wxyz[0]=data[1];
        wxyz[1]=data[2];
        wxyz[2]=data[3];
    }
    else
    {
        wxyz[0]=data[0];
        wxyz[1]=data[1];
        wxyz[2]=data[2];
        wxyz[3]=data[3];
    }
}

void C4Vector::setData(const simReal wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=wxyz[3];
        data[1]=wxyz[0];
        data[2]=wxyz[1];
        data[3]=wxyz[2];
    }
    else
    {
        data[0]=wxyz[0];
        data[1]=wxyz[1];
        data[2]=wxyz[2];
        data[3]=wxyz[3];
    }
}

simReal& C4Vector::operator() (size_t i)
{
    return(data[i]);
}

const simReal& C4Vector::operator() (size_t i) const
{
    return(data[i]);
}

void C4Vector::normalize()
{
    simReal l=sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]+data[3]*data[3]);
    data[0]/=l;
    data[1]/=l;
    data[2]/=l;
    data[3]/=l;
}

void C4Vector::clear()
{
    data[0]=0.0;
    data[1]=0.0;
    data[2]=0.0;
    data[3]=0.0;
}

void C4Vector::setIdentity()
{
    data[0]=1.0;
    data[1]=0.0;
    data[2]=0.0;
    data[3]=0.0;
}

C4Vector C4Vector::getInverse() const
{
    return(C4Vector(data[0],-data[1],-data[2],-data[3]));
}

void C4Vector::inverse()
{
    data[1]=-data[1];
    data[2]=-data[2];
    data[3]=-data[3];
}

C4Vector C4Vector::operator/ (simReal d) const
{
    C4Vector retV;
    retV(0)=data[0]/d;
    retV(1)=data[1]/d;
    retV(2)=data[2]/d;
    retV(3)=data[3]/d;
    return(retV);
}

C4Vector C4Vector::operator* (simReal d) const
{
    C4Vector retV;
    retV(0)=data[0]*d;
    retV(1)=data[1]*d;
    retV(2)=data[2]*d;
    retV(3)=data[3]*d;
    return(retV);
}

C4Vector& C4Vector::operator= (const C4Vector& v)
{
    data[0]=v(0);
    data[1]=v(1);
    data[2]=v(2);
    data[3]=v(3);
    return(*this);
}

bool C4Vector::operator!= (const C4Vector& v)
{
    return( (data[0]!=v(0))||(data[1]!=v(1))||(data[2]!=v(2))||(data[3]!=v(3)) );
}

C4Vector C4Vector::operator* (const C4Vector& v) const
{ // Quaternion multiplication.
    C4Vector retV;
    retV(0)=data[0]*v(0)-data[1]*v(1)-data[2]*v(2)-data[3]*v(3);
    retV(1)=data[0]*v(1)+v(0)*data[1]+data[2]*v(3)-data[3]*v(2);
    retV(2)=data[0]*v(2)+v(0)*data[2]+data[3]*v(1)-data[1]*v(3);
    retV(3)=data[0]*v(3)+v(0)*data[3]+data[1]*v(2)-data[2]*v(1);
    //  retV.normalize(); // NOOOOOOO!!!!!! We might compute the rotation of a vector which should be (q*v*qI).normalize and not q*((v*qi).normalize).normalize !!
    return(retV);
}

C3Vector C4Vector::getAxis(size_t index) const
{
    C3X3Matrix m=getMatrix();
    return(m.axis[index]);
}

C3Vector C4Vector::operator* (const C3Vector& v) const
{ // Rotation of a vector.
    C4Vector tmpV(1.0,v(0),v(1),v(2));
    tmpV=(*this)*(tmpV*getInverse());
    return(C3Vector(tmpV(1),tmpV(2),tmpV(3)));
}

C4Vector C4Vector::operator+ (const C4Vector& v) const
{
    C4Vector retV;
    retV(0)=data[0]+v(0);
    retV(1)=data[1]+v(1);
    retV(2)=data[2]+v(2);
    retV(3)=data[3]+v(3);
    return(retV);
}

C3X3Matrix C4Vector::getMatrix() const
{
    C3X3Matrix retM;
    simReal xx=data[1]*data[1];
    simReal xy=data[1]*data[2];
    simReal xz=data[1]*data[3];
    simReal xw=data[1]*data[0];
    simReal yy=data[2]*data[2];
    simReal yz=data[2]*data[3];
    simReal yw=data[2]*data[0];
    simReal zz=data[3]*data[3];
    simReal zw=data[3]*data[0];

    retM(0,0)=1.0-2.0*(yy+zz);
    retM(0,1)=2.0*(xy-zw);
    retM(0,2)=2.0*(xz+yw);
    retM(1,0)=2.0*(xy+zw);
    retM(1,1)=1.0-2.0*(xx+zz);
    retM(1,2)=2.0*(yz-xw);
    retM(2,0)=2.0*(xz-yw);
    retM(2,1)=2.0*(yz+xw);
    retM(2,2)=1.0-2.0*(xx+yy);
    return(retM);
}

void C4Vector::operator/= (simReal d)
{
    data[0]/=d;
    data[1]/=d;
    data[2]/=d;
    data[3]/=d;
}

void C4Vector::operator*= (simReal d)
{
    data[0]*=d;
    data[1]*=d;
    data[2]*=d;
    data[3]*=d;
}

void C4Vector::operator*= (const C4Vector& v)
{
    (*this)=(*this)*v;
    // Already normalized through * operator
}

void C4Vector::operator+= (const C4Vector& v)
{
    data[0]+=v(0);
    data[1]+=v(1);
    data[2]+=v(2);
    data[3]+=v(3);
}
