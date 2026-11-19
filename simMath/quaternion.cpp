#include "quaternion.h"
#include "mathFuncs.h"

const CQuaternion CQuaternion::identityRotation(1.0,0.0,0.0,0.0);

CQuaternion::CQuaternion()
{
}

CQuaternion::CQuaternion(simReal w,simReal x,simReal y,simReal z)
{
    data[0]=w;
    data[1]=x;
    data[2]=y;
    data[3]=z;
    // We don't normalize here
}

CQuaternion::CQuaternion(const double wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=simReal(wxyz[3]);
        data[1]=simReal(wxyz[0]);
        data[2]=simReal(wxyz[1]);
        data[3]=simReal(wxyz[2]);
    }
    else
    {
        data[0]=simReal(wxyz[0]);
        data[1]=simReal(wxyz[1]);
        data[2]=simReal(wxyz[2]);
        data[3]=simReal(wxyz[3]);
    }
    // We don't normalize here
}

CQuaternion::CQuaternion(const float wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=simReal(wxyz[3]);
        data[1]=simReal(wxyz[0]);
        data[2]=simReal(wxyz[1]);
        data[3]=simReal(wxyz[2]);
    }
    else
    {
        data[0]=simReal(wxyz[0]);
        data[1]=simReal(wxyz[1]);
        data[2]=simReal(wxyz[2]);
        data[3]=simReal(wxyz[3]);
    }
    // We don't normalize here
}
CQuaternion::CQuaternion(const CQuaternion& q)
{
    data[0]=q(0);
    data[1]=q(1);
    data[2]=q(2);
    data[3]=q(3);
    // We don't normalize here
}

CQuaternion::CQuaternion(const C3Vector& v)
{ // Alpha, beta and gamma are in radians!
    setEulerAngles(v);
}

CQuaternion::CQuaternion(simReal a,simReal b,simReal g)
{ // Alpha, beta and gamma are in radians!
    setEulerAngles(a,b,g);
}

CQuaternion::CQuaternion(simReal angle,const C3Vector& axis)
{ // Builds a rotation quaternion around axis (angle in radian!)
    setAngleAndAxis(angle,axis);
}

CQuaternion::CQuaternion(const C3Vector& startV,const C3Vector& endV)
{
    setVectorMapping(startV,endV);
}

CQuaternion::~CQuaternion()
{

}

void CQuaternion::setEulerAngles(simReal a,simReal b,simReal g)
{ // a,b anf g are in radian!
    CQuaternion vx(a,C3Vector(1.0,0.0,0.0));
    CQuaternion vy(b,C3Vector(0.0,1.0,0.0));
    CQuaternion vz(g,C3Vector(0.0,0.0,1.0));
    (*this)=vx*vy*vz;
}

void CQuaternion::setEulerAngles(const C3Vector& v)
{ // v(0), v(1) and v(2) are in radian!
    setEulerAngles(v(0),v(1),v(2));
}

void CQuaternion::setAngleAndAxis(simReal angle,const C3Vector& axis)
{ // angle in radian!
    C3Vector axisTmp=axis;
    if (axisTmp.normalize()==0.0)
    { // Invalid axis: build an identity rotation rather than an invalid quaternion
        setIdentity();
        return;
    }
    simReal sinA=sin(angle/2.0);
    data[1]=axisTmp(0)*sinA;
    data[2]=axisTmp(1)*sinA;
    data[3]=axisTmp(2)*sinA;
    data[0]=cos(angle/2.0);
}

void CQuaternion::setVectorMapping(const C3Vector& startV,const C3Vector& endV)
{ // Builds the rotation that maps startV onto endV
    C3Vector v0(startV.getNormalized());
    C3Vector v1(endV.getNormalized());
    if ((v0.getLength()==0.0)||(v1.getLength()==0.0))
    { // Invalid input vector
        setIdentity();
        return;
    }
    simReal cosAngle=v0*v1;
    C3Vector cross(v0^v1);
    if (cross.getLength()<simReal(0.000001))
    { // Vectors are aligned or anti-aligned
        if (cosAngle>0.0)
            setIdentity();
        else
        { // Rotate 180 degrees around an arbitrary axis perpendicular to v0:
            C3Vector axis;
            if (fabs(v0(0))<simReal(0.9))
                axis=C3Vector::unitXVector^v0;
            else
                axis=C3Vector::unitYVector^v0;
            axis.normalize();
            setAngleAndAxis(piValue,axis);
        }
        return;
    }
    setAngleAndAxis(robustAcos(cosAngle),cross);
}

void CQuaternion::alignQuaternion(const C3Vector& v)
{
    if (v.getLength() < 0.00001)
    {
        setIdentity();
        return;
    }

    C3Vector w = v.getNormalized();
    const C3Vector zAxis(0.0, 0.0, 1.0);
    simReal cosAngle = zAxis * w;

    if (cosAngle > 1.0 - 0.00001)
        setIdentity();
    else if (cosAngle < -1.0 + 0.00001)
        setAngleAndAxis(piValue, C3Vector(1.0, 0.0, 0.0));
    else
    {
        C3Vector cross = (zAxis ^ w).getNormalized();
        setAngleAndAxis(robustAcos(cosAngle), cross);
    }
}

C3Vector CQuaternion::getAngleAndAxis(simReal& angle) const
{
    C3Vector retV;
    CQuaternion d(*this);
    if (d(0)<0.0)
        d=d*-1.0;
    simReal l=sqrt(d(0)*d(0)+d(1)*d(1)+d(2)*d(2)+d(3)*d(3));
    if (l==0.0)
    { // Invalid quaternion: return a zero rotation
        angle=0.0;
        retV(0)=0.0;
        retV(1)=0.0;
        retV(2)=1.0;
        return(retV);
    }
    simReal cosA=d(0)/l; // Quaternion needs to be normalized
    if (cosA>1.0) // Just make sure..
        cosA=1.0;
    angle=robustAcos(cosA)*2.0;
    if (angle>0.000001)
    {
        simReal sinA=sqrt(1.0-cosA*cosA);
        if (fabs(sinA)<simReal(0.00005))
        { // Very small rotation: the axis is ill-conditioned, so normalize the
          // (small) vector part to still return a unit axis
            simReal lv=sqrt(d(1)*d(1)+d(2)*d(2)+d(3)*d(3));
            if (lv==0.0)
            {
                retV(0)=0.0;
                retV(1)=0.0;
                retV(2)=1.0;
            }
            else
            {
                retV(0)=d(1)/lv;
                retV(1)=d(2)/lv;
                retV(2)=d(3)/lv;
            }
        }
        else
        {
            sinA*=l; // Quaternion needs to be normalized
            retV(0)=d(1)/sinA;
            retV(1)=d(2)/sinA;
            retV(2)=d(3)/sinA;
        }
    }
    else
    {
        retV(0)=0.0;
        retV(1)=0.0;
        retV(2)=1.0;
    }
    return(retV);
}

CQuaternion CQuaternion::getAngleAndAxis() const
{ // Returned vector is (angle,x,y,z) (angle is in radians)
    simReal angle;
    C3Vector a(getAngleAndAxis(angle));
    CQuaternion retVal(angle,a(0),a(1),a(2));
    return(retVal);
}

C3Vector CQuaternion::getEulerAngles() const
{
    return(getMatrix().getEulerAngles());
}

simReal CQuaternion::getAngleBetweenQuaternions(const CQuaternion& q) const
{
    simReal angle=fabs(data[0]*q(0)+data[1]*q(1)+data[2]*q(2)+data[3]*q(3));
    return(robustAcos(angle)*2.0);
}

void CQuaternion::buildInterpolation(const CQuaternion& fromThis,const CQuaternion& toThat,simReal t)
{
    CQuaternion AA(fromThis);
    CQuaternion BB(toThat);
    if (AA(0)*BB(0)+AA(1)*BB(1)+AA(2)*BB(2)+AA(3)*BB(3)<0.0)
        AA=AA*-1.0;
    CQuaternion r((AA.getInverse()*BB).getAngleAndAxis());
    (*this)=(AA*CQuaternion(r(0)*t,C3Vector(r(1),r(2),r(3))));
    // The product of two unit quaternions is unit length (up to round-off)
}

void CQuaternion::buildInterpolation_otherWayRound(const CQuaternion& fromThis,const CQuaternion& toThat,simReal t)
{
    CQuaternion AA(fromThis);
    CQuaternion BB(toThat);
    if (AA(0)*BB(0)+AA(1)*BB(1)+AA(2)*BB(2)+AA(3)*BB(3)<0.0)
        AA=AA*-1.0;
    CQuaternion r((AA.getInverse()*BB).getAngleAndAxis());

    // r(0) is the rotation angle
    // r(1),r(2),r(3) is the rotation axis
    // Here, since we want to rotate the other way round, we inverse the axis and rotate by 2*pi-r(0) instead:
    (*this)=(AA*CQuaternion((piValT2-r(0))*t,C3Vector(r(1)*-1.0,r(2)*-1.0,r(3)*-1.0)));
    // The product of two unit quaternions is unit length (up to round-off)
}

void CQuaternion::buildRandomOrientation()
{
    C3Vector u(SIM_RAND_FLOAT,SIM_RAND_FLOAT,SIM_RAND_FLOAT);
    data[0]=sqrt(1.0-u(0))*sin(piValT2*u(1));
    data[1]=sqrt(1.0-u(0))*cos(piValT2*u(1));
    data[2]=sqrt(u(0))*sin(piValT2*u(2));
    data[3]=sqrt(u(0))*cos(piValT2*u(2));
}

void CQuaternion::getData(simReal wxyz[4],bool xyzwLayout/*=false*/) const
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

void CQuaternion::setData(const float wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=(simReal)wxyz[3];
        data[1]=(simReal)wxyz[0];
        data[2]=(simReal)wxyz[1];
        data[3]=(simReal)wxyz[2];
    }
    else
    {
        data[0]=(simReal)wxyz[0];
        data[1]=(simReal)wxyz[1];
        data[2]=(simReal)wxyz[2];
        data[3]=(simReal)wxyz[3];
    }
}

void CQuaternion::setData(const double wxyz[4],bool xyzwLayout/*=false*/)
{
    if (xyzwLayout)
    {
        data[0]=(simReal)wxyz[3];
        data[1]=(simReal)wxyz[0];
        data[2]=(simReal)wxyz[1];
        data[3]=(simReal)wxyz[2];
    }
    else
    {
        data[0]=(simReal)wxyz[0];
        data[1]=(simReal)wxyz[1];
        data[2]=(simReal)wxyz[2];
        data[3]=(simReal)wxyz[3];
    }
}

simReal& CQuaternion::operator() (size_t i)
{
    return(data[i]);
}

const simReal& CQuaternion::operator() (size_t i) const
{
    return(data[i]);
}

void CQuaternion::normalize()
{
    simReal l=sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]+data[3]*data[3]);
    if (l!=0.0)
    { // A zero quaternion is left unchanged
        data[0]/=l;
        data[1]/=l;
        data[2]/=l;
        data[3]/=l;
    }
}

void CQuaternion::clear()
{
    data[0]=0.0;
    data[1]=0.0;
    data[2]=0.0;
    data[3]=0.0;
}

void CQuaternion::setIdentity()
{
    data[0]=1.0;
    data[1]=0.0;
    data[2]=0.0;
    data[3]=0.0;
}

CQuaternion CQuaternion::getInverse() const
{
    return(CQuaternion(data[0],-data[1],-data[2],-data[3]));
}

void CQuaternion::inverse()
{
    data[1]=-data[1];
    data[2]=-data[2];
    data[3]=-data[3];
}

CQuaternion CQuaternion::operator/ (simReal d) const
{
    CQuaternion retV;
    retV(0)=data[0]/d;
    retV(1)=data[1]/d;
    retV(2)=data[2]/d;
    retV(3)=data[3]/d;
    return(retV);
}

CQuaternion CQuaternion::operator* (simReal d) const
{
    CQuaternion retV;
    retV(0)=data[0]*d;
    retV(1)=data[1]*d;
    retV(2)=data[2]*d;
    retV(3)=data[3]*d;
    return(retV);
}

CQuaternion& CQuaternion::operator= (const CQuaternion& v)
{
    data[0]=v(0);
    data[1]=v(1);
    data[2]=v(2);
    data[3]=v(3);
    return(*this);
}

bool CQuaternion::operator!= (const CQuaternion& v)
{
    return( (data[0]!=v(0))||(data[1]!=v(1))||(data[2]!=v(2))||(data[3]!=v(3)) );
}

CQuaternion CQuaternion::operator* (const CQuaternion& v) const
{ // Quaternion multiplication.
    CQuaternion retV;
    retV(0)=data[0]*v(0)-data[1]*v(1)-data[2]*v(2)-data[3]*v(3);
    retV(1)=data[0]*v(1)+v(0)*data[1]+data[2]*v(3)-data[3]*v(2);
    retV(2)=data[0]*v(2)+v(0)*data[2]+data[3]*v(1)-data[1]*v(3);
    retV(3)=data[0]*v(3)+v(0)*data[3]+data[1]*v(2)-data[2]*v(1);
    //  retV.normalize(); // NOOOOOOO!!!!!! We might compute the rotation of a vector which should be (q*v*qI).normalize and not q*((v*qi).normalize).normalize !!
    return(retV);
}

C3Vector CQuaternion::getAxis(size_t index) const
{
    C3X3Matrix m=getMatrix();
    return(m.axis[index]);
}

C3Vector CQuaternion::operator* (const C3Vector& v) const
{ // Rotation of a vector (this quaternion has to be unit length)
    const simReal w=data[0];
    const simReal x=data[1],y=data[2],z=data[3];
    const simReal vx=v.data[0],vy=v.data[1],vz=v.data[2];
    const simReal tx=2.0*(y*vz-z*vy);
    const simReal ty=2.0*(z*vx-x*vz);
    const simReal tz=2.0*(x*vy-y*vx);
    return(C3Vector(vx+w*tx+(y*tz-z*ty),
                    vy+w*ty+(z*tx-x*tz),
                    vz+w*tz+(x*ty-y*tx)));
}

CQuaternion CQuaternion::operator+ (const CQuaternion& v) const
{
    CQuaternion retV;
    retV(0)=data[0]+v(0);
    retV(1)=data[1]+v(1);
    retV(2)=data[2]+v(2);
    retV(3)=data[3]+v(3);
    return(retV);
}

C3X3Matrix CQuaternion::getMatrix() const
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

    retM.axis[0].data[0]=1.0-2.0*(yy+zz);
    retM.axis[1].data[0]=2.0*(xy-zw);
    retM.axis[2].data[0]=2.0*(xz+yw);
    retM.axis[0].data[1]=2.0*(xy+zw);
    retM.axis[1].data[1]=1.0-2.0*(xx+zz);
    retM.axis[2].data[1]=2.0*(yz-xw);
    retM.axis[0].data[2]=2.0*(xz-yw);
    retM.axis[1].data[2]=2.0*(yz+xw);
    retM.axis[2].data[2]=1.0-2.0*(xx+yy);
    return(retM);
}

void CQuaternion::operator/= (simReal d)
{
    data[0]/=d;
    data[1]/=d;
    data[2]/=d;
    data[3]/=d;
}

void CQuaternion::operator*= (simReal d)
{
    data[0]*=d;
    data[1]*=d;
    data[2]*=d;
    data[3]*=d;
}

void CQuaternion::operator*= (const CQuaternion& v)
{
    (*this)=(*this)*v;
    // Unit-length quaternions stay unit length (up to round-off)
}

void CQuaternion::operator+= (const CQuaternion& v)
{
    data[0]+=v(0);
    data[1]+=v(1);
    data[2]+=v(2);
    data[3]+=v(3);
}
