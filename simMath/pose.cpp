#include "pose.h"
#include "4X4Matrix.h"

const CPose CPose::identityTransformation(CQuaternion(1.0,0.0,0.0,0.0),C3Vector(0.0,0.0,0.0));

// File-local helpers with direct data access (avoid cross-translation-unit calls
// in the most frequently used pose operations). The quaternion has to be unit length.

static inline C3Vector rotatePoseVector(const CQuaternion& q,const C3Vector& v)
{
    const simReal w=q.data[0];
    const simReal x=q.data[1],y=q.data[2],z=q.data[3];
    const simReal vx=v.data[0],vy=v.data[1],vz=v.data[2];
    const simReal tx=2.0*(y*vz-z*vy);
    const simReal ty=2.0*(z*vx-x*vz);
    const simReal tz=2.0*(x*vy-y*vx);
    C3Vector retV;
    retV.data[0]=vx+w*tx+(y*tz-z*ty);
    retV.data[1]=vy+w*ty+(z*tx-x*tz);
    retV.data[2]=vz+w*tz+(x*ty-y*tx);
    return(retV);
}

static inline void multiplyPoses(CPose& r,const CPose& a,const CPose& b,bool normalizeQ)
{
    C3Vector rx=rotatePoseVector(a.Q,b.X);
    rx.data[0]+=a.X.data[0];
    rx.data[1]+=a.X.data[1];
    rx.data[2]+=a.X.data[2];
    const simReal w1=a.Q.data[0],x1=a.Q.data[1],y1=a.Q.data[2],z1=a.Q.data[3];
    const simReal w2=b.Q.data[0],x2=b.Q.data[1],y2=b.Q.data[2],z2=b.Q.data[3];
    simReal w=w1*w2-x1*x2-y1*y2-z1*z2;
    simReal x=w1*x2+w2*x1+y1*z2-z1*y2;
    simReal y=w1*y2+w2*y1+z1*x2-x1*z2;
    simReal z=w1*z2+w2*z1+x1*y2-y1*x2;
    if (normalizeQ)
    {
        const simReal l=sqrt(w*w+x*x+y*y+z*z);
        if (l!=0.0)
        {
            w/=l;
            x/=l;
            y/=l;
            z/=l;
        }
    }
    r.X.data[0]=rx.data[0];
    r.X.data[1]=rx.data[1];
    r.X.data[2]=rx.data[2];
    r.Q.data[0]=w;
    r.Q.data[1]=x;
    r.Q.data[2]=y;
    r.Q.data[3]=z;
}

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
{ // Directly filled to avoid a temporary 3x3 matrix and its copy
    C4X4Matrix retM;
    const simReal w=Q.data[0];
    const simReal x=Q.data[1],y=Q.data[2],z=Q.data[3];
    const simReal xx=x*x;
    const simReal xy=x*y;
    const simReal xz=x*z;
    const simReal xw=x*w;
    const simReal yy=y*y;
    const simReal yz=y*z;
    const simReal yw=y*w;
    const simReal zz=z*z;
    const simReal zw=z*w;
    retM.M.axis[0].data[0]=1.0-2.0*(yy+zz);
    retM.M.axis[1].data[0]=2.0*(xy-zw);
    retM.M.axis[2].data[0]=2.0*(xz+yw);
    retM.M.axis[0].data[1]=2.0*(xy+zw);
    retM.M.axis[1].data[1]=1.0-2.0*(xx+zz);
    retM.M.axis[2].data[1]=2.0*(yz-xw);
    retM.M.axis[0].data[2]=2.0*(xz-yw);
    retM.M.axis[1].data[2]=2.0*(yz+xw);
    retM.M.axis[2].data[2]=1.0-2.0*(xx+yy);
    retM.X.data[0]=X.data[0];
    retM.X.data[1]=X.data[1];
    retM.X.data[2]=X.data[2];
    return(retM);
}

CPose& CPose::operator= (const CPose& v)
{
    Q=v.Q;
    X=v.X;
    return(*this);
}

void CPose::setMultResult(const CPose& v1,const CPose& v2)
{
    multiplyPoses(*this,v1,v2,false);
}

CPose CPose::operator* (const CPose& v) const
{ // Transformation multiplication
    CPose retV;
    multiplyPoses(retV,*this,v,true);
    return(retV);
}

void CPose::operator*= (const CPose& v)
{
    multiplyPoses(*this,*this,v,false);
}

C3Vector CPose::operator* (const C3Vector& v) const
{ // Vector transformation
    C3Vector retV=rotatePoseVector(Q,v);
    retV.data[0]+=X.data[0];
    retV.data[1]+=X.data[1];
    retV.data[2]+=X.data[2];
    return(retV);
}

void CPose::inverse()
{
    (*this)=getInverse();
}

CPose CPose::getInverse() const
{
    CPose retV;
    retV.Q.data[0]=Q.data[0];
    retV.Q.data[1]=-Q.data[1];
    retV.Q.data[2]=-Q.data[2];
    retV.Q.data[3]=-Q.data[3];
    const C3Vector t=rotatePoseVector(retV.Q,X);
    retV.X.data[0]=-t.data[0];
    retV.X.data[1]=-t.data[1];
    retV.X.data[2]=-t.data[2];
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
