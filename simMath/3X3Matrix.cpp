#include "3X3Matrix.h"
#include "quaternion.h"
#include "mathFuncs.h"

C3X3Matrix::C3X3Matrix()
{

}

C3X3Matrix::C3X3Matrix(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis)
{
    (*this).axis[0]=xAxis;
    (*this).axis[1]=yAxis;
    (*this).axis[2]=zAxis;
}

C3X3Matrix::C3X3Matrix(const CQuaternion& q)
{
    (*this)=q.getMatrix();
}

C3X3Matrix::C3X3Matrix(const C3X3Matrix& m)
{
    (*this).axis[0]=m.axis[0];
    (*this).axis[1]=m.axis[1];
    (*this).axis[2]=m.axis[2];
}

C3X3Matrix::~C3X3Matrix()
{

}

void C3X3Matrix::setEulerAngles(simReal a,simReal b,simReal g)
{ // a,b anf g are in radian!
    simReal A=cos(a);
    simReal B=sin(a);
    simReal C=cos(b);
    simReal D=sin(b);
    simReal E=cos(g);
    simReal F=sin(g);
    simReal AD=A*D;
    simReal BD=B*D;
    axis[0].data[0]=C*E;
    axis[1].data[0]=-C*F;
    axis[2].data[0]=D;
    axis[0].data[1]=BD*E+A*F;
    axis[1].data[1]=-BD*F+A*E;
    axis[2].data[1]=-B*C;
    axis[0].data[2]=-AD*E+B*F;
    axis[1].data[2]=AD*F+B*E;
    axis[2].data[2]=A*C;
}

void C3X3Matrix::setEulerAngles(const C3Vector& v)
{ // v(0), v(1) and v(2) are in radian!
    setEulerAngles(v.data[0],v.data[1],v.data[2]);
}

C3Vector C3X3Matrix::getEulerAngles() const
{ // Angles are in radians. In case of gimbal lock (|sin(beta)|>=0.999995), alpha is returned as 0.0
    C3Vector retV;
    simReal m02=axis[2].data[0];
    if (m02>1.0)
        m02=1.0;   // Just in case
    if (m02<-1.0)
        m02=-1.0;  // Just in case
    
    retV.data[1]=robustAsin(m02);
    if (m02<0.0)
        m02=-m02;
    if (m02<simReal(0.999995))
    {   // No gimbal lock
        retV.data[0]=atan2(-axis[2].data[1],axis[2].data[2]);
        retV.data[2]=atan2(-axis[1].data[0],axis[0].data[0]);
    }
    else
    {   // Gimbal lock has occured
        retV.data[0]=0.0;
        retV.data[2]=atan2(axis[0].data[1],axis[1].data[1]);
    }
    return(retV);
}

CQuaternion C3X3Matrix::getQuaternion() const
{   
    CQuaternion retV;
    simReal trace=axis[0].data[0]+axis[1].data[1]+axis[2].data[2];
    if (trace>=0.0)    // trace>0.00000001)
    {
        simReal s=sqrt(trace+1.0)*2.0;
        retV.data[1]=(axis[1].data[2]-axis[2].data[1])/s;
        retV.data[2]=(axis[2].data[0]-axis[0].data[2])/s;
        retV.data[3]=(axis[0].data[1]-axis[1].data[0])/s;
        retV.data[0]=simReal(0.25)*s;
    }
    else
    {
        if ((axis[0].data[0]>=axis[1].data[1])&&(axis[0].data[0]>=axis[2].data[2]))
        {
            simReal s=sqrt(1.0+axis[0].data[0]-axis[1].data[1]-axis[2].data[2])*2.0;
            retV.data[1]=simReal(0.25)*s;
            retV.data[2]=(axis[0].data[1]+axis[1].data[0])/s;
            retV.data[3]=(axis[2].data[0]+axis[0].data[2])/s;
            retV.data[0]=(axis[1].data[2]-axis[2].data[1])/s;
        }
        else
        {
            if ((axis[1].data[1]>=axis[0].data[0])&&(axis[1].data[1]>=axis[2].data[2]))
            {
                simReal s=sqrt(1.0+axis[1].data[1]-axis[0].data[0]-axis[2].data[2])*2.0;
                retV.data[1]=(axis[0].data[1]+axis[1].data[0])/s;
                retV.data[2]=simReal(0.25)*s;
                retV.data[3]=(axis[1].data[2]+axis[2].data[1])/s;
                retV.data[0]=(axis[2].data[0]-axis[0].data[2])/s;
            }
            else
            {
                simReal s=sqrt(1.0+axis[2].data[2]-axis[0].data[0]-axis[1].data[1])*2.0;
                retV.data[1]=(axis[2].data[0]+axis[0].data[2])/s;
                retV.data[2]=(axis[1].data[2]+axis[2].data[1])/s;
                retV.data[3]=simReal(0.25)*s;
                retV.data[0]=(axis[0].data[1]-axis[1].data[0])/s;
            }
        }
    }
    const simReal l=sqrt(retV.data[0]*retV.data[0]+retV.data[1]*retV.data[1]+retV.data[2]*retV.data[2]+retV.data[3]*retV.data[3]);
    if (l!=0.0)
    {
        retV.data[0]/=l;
        retV.data[1]/=l;
        retV.data[2]/=l;
        retV.data[3]/=l;
    }
    return(retV);
}

void C3X3Matrix::buildInterpolation(const C3X3Matrix& fromThis,const C3X3Matrix& toThat,simReal t)
{   // Builds the interpolation (based on t) from 'fromThis' to 'toThat'
    CQuaternion out;
    out.buildInterpolation(fromThis.getQuaternion(),toThat.getQuaternion(),t);
    (*this)=out;
}

void C3X3Matrix::buildXRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0].data[0]=1.0;
    axis[1].data[0]=0.0;
    axis[2].data[0]=0.0;
    axis[0].data[1]=0.0;
    axis[1].data[1]=c;
    axis[2].data[1]=-s;
    axis[0].data[2]=0.0;
    axis[1].data[2]=s;
    axis[2].data[2]=c;
}

void C3X3Matrix::buildYRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0].data[0]=c;
    axis[1].data[0]=0.0;
    axis[2].data[0]=s;
    axis[0].data[1]=0.0;
    axis[1].data[1]=1.0;
    axis[2].data[1]=0.0;
    axis[0].data[2]=-s;
    axis[1].data[2]=0.0;
    axis[2].data[2]=c;
}

void C3X3Matrix::buildZRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0].data[0]=c;
    axis[1].data[0]=-s;
    axis[2].data[0]=0.0;
    axis[0].data[1]=s;
    axis[1].data[1]=c;
    axis[2].data[1]=0.0;
    axis[0].data[2]=0.0;
    axis[1].data[2]=0.0;
    axis[2].data[2]=1.0;
}

void C3X3Matrix::normalize()
{ // The Z axis is the reference
    if (axis[2].normalize()==0.0)
    {
        axis[0]=C3Vector::unitXVector;
        axis[1]=C3Vector::unitYVector;
        axis[2]=C3Vector::unitZVector;
    }
    else
    {
        axis[1]=axis[2]^axis[0];
        if (axis[1].normalize()==0.0)
        { // axis[0] and axis[2] are aligned: use a deterministic fallback axis
            if (fabs(axis[2].data[0])<simReal(0.9))
                axis[1]=axis[2]^C3Vector::unitXVector;
            else
                axis[1]=axis[2]^C3Vector::unitYVector;
            axis[1].normalize();
        }
        axis[0]=(axis[1]^axis[2]).getNormalized();
    }
}

C3Vector C3X3Matrix::getNormalVector() const
{ // returns the normal vector to the plane described by axis[0],axis[1],axis[2]
    C3Vector v0(axis[0]-axis[1]);
    C3Vector v1(axis[1]-axis[2]);
    return((v0^v1).getNormalized());
}

simReal& C3X3Matrix::operator() (size_t i,size_t j)
{
    return(axis[j].data[i]);
}

const simReal& C3X3Matrix::operator() (size_t i,size_t j) const
{
    return(axis[j].data[i]);
}

void C3X3Matrix::clear()
{
    axis[0].data[0]=0.0;
    axis[0].data[1]=0.0;
    axis[0].data[2]=0.0;
    axis[1].data[0]=0.0;
    axis[1].data[1]=0.0;
    axis[1].data[2]=0.0;
    axis[2].data[0]=0.0;
    axis[2].data[1]=0.0;
    axis[2].data[2]=0.0;
}

void C3X3Matrix::setIdentity()
{
    axis[0].data[0]=1.0;
    axis[0].data[1]=0.0;
    axis[0].data[2]=0.0;
    axis[1].data[0]=0.0;
    axis[1].data[1]=1.0;
    axis[1].data[2]=0.0;
    axis[2].data[0]=0.0;
    axis[2].data[1]=0.0;
    axis[2].data[2]=1.0;
}

void C3X3Matrix::transpose()
{
    (*this)=getTranspose();
}

void C3X3Matrix::setData(const simReal v[9])
{
    axis[0].data[0]=v[0];
    axis[1].data[0]=v[1];
    axis[2].data[0]=v[2];
    axis[0].data[1]=v[3];
    axis[1].data[1]=v[4];
    axis[2].data[1]=v[5];
    axis[0].data[2]=v[6];
    axis[1].data[2]=v[7];
    axis[2].data[2]=v[8];
}

void C3X3Matrix::getData(simReal v[9]) const
{
    v[0]=axis[0].data[0];
    v[1]=axis[1].data[0];
    v[2]=axis[2].data[0];
    v[3]=axis[0].data[1];
    v[4]=axis[1].data[1];
    v[5]=axis[2].data[1];
    v[6]=axis[0].data[2];
    v[7]=axis[1].data[2];
    v[8]=axis[2].data[2];
}

bool C3X3Matrix::isValid() const
{
    for (int i=0;i<3;i++)
    {
        if (!axis[i].isValid())
            return(false);
    }
    return(true);
}

C3X3Matrix C3X3Matrix::getTranspose() const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0];
    retM.axis[1].data[0]=axis[0].data[1];
    retM.axis[2].data[0]=axis[0].data[2];
    retM.axis[0].data[1]=axis[1].data[0];
    retM.axis[1].data[1]=axis[1].data[1];
    retM.axis[2].data[1]=axis[1].data[2];
    retM.axis[0].data[2]=axis[2].data[0];
    retM.axis[1].data[2]=axis[2].data[1];
    retM.axis[2].data[2]=axis[2].data[2];
    return(retM);
}

C3X3Matrix C3X3Matrix::operator* (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]*m.axis[0].data[0]+axis[1].data[0]*m.axis[0].data[1]+axis[2].data[0]*m.axis[0].data[2];
    retM.axis[1].data[0]=axis[0].data[0]*m.axis[1].data[0]+axis[1].data[0]*m.axis[1].data[1]+axis[2].data[0]*m.axis[1].data[2];
    retM.axis[2].data[0]=axis[0].data[0]*m.axis[2].data[0]+axis[1].data[0]*m.axis[2].data[1]+axis[2].data[0]*m.axis[2].data[2];
    retM.axis[0].data[1]=axis[0].data[1]*m.axis[0].data[0]+axis[1].data[1]*m.axis[0].data[1]+axis[2].data[1]*m.axis[0].data[2];
    retM.axis[1].data[1]=axis[0].data[1]*m.axis[1].data[0]+axis[1].data[1]*m.axis[1].data[1]+axis[2].data[1]*m.axis[1].data[2];
    retM.axis[2].data[1]=axis[0].data[1]*m.axis[2].data[0]+axis[1].data[1]*m.axis[2].data[1]+axis[2].data[1]*m.axis[2].data[2];
    retM.axis[0].data[2]=axis[0].data[2]*m.axis[0].data[0]+axis[1].data[2]*m.axis[0].data[1]+axis[2].data[2]*m.axis[0].data[2];
    retM.axis[1].data[2]=axis[0].data[2]*m.axis[1].data[0]+axis[1].data[2]*m.axis[1].data[1]+axis[2].data[2]*m.axis[1].data[2];
    retM.axis[2].data[2]=axis[0].data[2]*m.axis[2].data[0]+axis[1].data[2]*m.axis[2].data[1]+axis[2].data[2]*m.axis[2].data[2];
    return(retM);
}

C3X3Matrix C3X3Matrix::operator+ (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]+m.axis[0].data[0];
    retM.axis[1].data[0]=axis[1].data[0]+m.axis[1].data[0];
    retM.axis[2].data[0]=axis[2].data[0]+m.axis[2].data[0];
    retM.axis[0].data[1]=axis[0].data[1]+m.axis[0].data[1];
    retM.axis[1].data[1]=axis[1].data[1]+m.axis[1].data[1];
    retM.axis[2].data[1]=axis[2].data[1]+m.axis[2].data[1];
    retM.axis[0].data[2]=axis[0].data[2]+m.axis[0].data[2];
    retM.axis[1].data[2]=axis[1].data[2]+m.axis[1].data[2];
    retM.axis[2].data[2]=axis[2].data[2]+m.axis[2].data[2];
    return(retM);
}

C3X3Matrix C3X3Matrix::operator- (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]-m.axis[0].data[0];
    retM.axis[1].data[0]=axis[1].data[0]-m.axis[1].data[0];
    retM.axis[2].data[0]=axis[2].data[0]-m.axis[2].data[0];
    retM.axis[0].data[1]=axis[0].data[1]-m.axis[0].data[1];
    retM.axis[1].data[1]=axis[1].data[1]-m.axis[1].data[1];
    retM.axis[2].data[1]=axis[2].data[1]-m.axis[2].data[1];
    retM.axis[0].data[2]=axis[0].data[2]-m.axis[0].data[2];
    retM.axis[1].data[2]=axis[1].data[2]-m.axis[1].data[2];
    retM.axis[2].data[2]=axis[2].data[2]-m.axis[2].data[2];
    return(retM);
}

C3X3Matrix C3X3Matrix::operator* (simReal f) const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]*f;
    retM.axis[1].data[0]=axis[1].data[0]*f;
    retM.axis[2].data[0]=axis[2].data[0]*f;
    retM.axis[0].data[1]=axis[0].data[1]*f;
    retM.axis[1].data[1]=axis[1].data[1]*f;
    retM.axis[2].data[1]=axis[2].data[1]*f;
    retM.axis[0].data[2]=axis[0].data[2]*f;
    retM.axis[1].data[2]=axis[1].data[2]*f;
    retM.axis[2].data[2]=axis[2].data[2]*f;
    return(retM);
}

C3X3Matrix C3X3Matrix::operator/ (simReal f) const
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]/f;
    retM.axis[1].data[0]=axis[1].data[0]/f;
    retM.axis[2].data[0]=axis[2].data[0]/f;
    retM.axis[0].data[1]=axis[0].data[1]/f;
    retM.axis[1].data[1]=axis[1].data[1]/f;
    retM.axis[2].data[1]=axis[2].data[1]/f;
    retM.axis[0].data[2]=axis[0].data[2]/f;
    retM.axis[1].data[2]=axis[1].data[2]/f;
    retM.axis[2].data[2]=axis[2].data[2]/f;
    return(retM);
}
void C3X3Matrix::operator*= (const C3X3Matrix& m)
{
    C3X3Matrix retM;
    retM.axis[0].data[0]=axis[0].data[0]*m.axis[0].data[0]+axis[1].data[0]*m.axis[0].data[1]+axis[2].data[0]*m.axis[0].data[2];
    retM.axis[1].data[0]=axis[0].data[0]*m.axis[1].data[0]+axis[1].data[0]*m.axis[1].data[1]+axis[2].data[0]*m.axis[1].data[2];
    retM.axis[2].data[0]=axis[0].data[0]*m.axis[2].data[0]+axis[1].data[0]*m.axis[2].data[1]+axis[2].data[0]*m.axis[2].data[2];
    retM.axis[0].data[1]=axis[0].data[1]*m.axis[0].data[0]+axis[1].data[1]*m.axis[0].data[1]+axis[2].data[1]*m.axis[0].data[2];
    retM.axis[1].data[1]=axis[0].data[1]*m.axis[1].data[0]+axis[1].data[1]*m.axis[1].data[1]+axis[2].data[1]*m.axis[1].data[2];
    retM.axis[2].data[1]=axis[0].data[1]*m.axis[2].data[0]+axis[1].data[1]*m.axis[2].data[1]+axis[2].data[1]*m.axis[2].data[2];
    retM.axis[0].data[2]=axis[0].data[2]*m.axis[0].data[0]+axis[1].data[2]*m.axis[0].data[1]+axis[2].data[2]*m.axis[0].data[2];
    retM.axis[1].data[2]=axis[0].data[2]*m.axis[1].data[0]+axis[1].data[2]*m.axis[1].data[1]+axis[2].data[2]*m.axis[1].data[2];
    retM.axis[2].data[2]=axis[0].data[2]*m.axis[2].data[0]+axis[1].data[2]*m.axis[2].data[1]+axis[2].data[2]*m.axis[2].data[2];
    (*this)=retM;
}

void C3X3Matrix::operator+= (const C3X3Matrix& m)
{
    axis[0].data[0]+=m.axis[0].data[0];
    axis[1].data[0]+=m.axis[1].data[0];
    axis[2].data[0]+=m.axis[2].data[0];
    axis[0].data[1]+=m.axis[0].data[1];
    axis[1].data[1]+=m.axis[1].data[1];
    axis[2].data[1]+=m.axis[2].data[1];
    axis[0].data[2]+=m.axis[0].data[2];
    axis[1].data[2]+=m.axis[1].data[2];
    axis[2].data[2]+=m.axis[2].data[2];
}

void C3X3Matrix::operator-= (const C3X3Matrix& m)
{
    axis[0].data[0]-=m.axis[0].data[0];
    axis[1].data[0]-=m.axis[1].data[0];
    axis[2].data[0]-=m.axis[2].data[0];
    axis[0].data[1]-=m.axis[0].data[1];
    axis[1].data[1]-=m.axis[1].data[1];
    axis[2].data[1]-=m.axis[2].data[1];
    axis[0].data[2]-=m.axis[0].data[2];
    axis[1].data[2]-=m.axis[1].data[2];
    axis[2].data[2]-=m.axis[2].data[2];
}

void C3X3Matrix::operator*= (simReal f)
{
    axis[0].data[0]*=f;
    axis[1].data[0]*=f;
    axis[2].data[0]*=f;
    axis[0].data[1]*=f;
    axis[1].data[1]*=f;
    axis[2].data[1]*=f;
    axis[0].data[2]*=f;
    axis[1].data[2]*=f;
    axis[2].data[2]*=f;
}

void C3X3Matrix::operator/= (simReal f)
{
    axis[0].data[0]/=f;
    axis[1].data[0]/=f;
    axis[2].data[0]/=f;
    axis[0].data[1]/=f;
    axis[1].data[1]/=f;
    axis[2].data[1]/=f;
    axis[0].data[2]/=f;
    axis[1].data[2]/=f;
    axis[2].data[2]/=f;
}

C3Vector C3X3Matrix::operator* (const C3Vector& v) const
{
    C3Vector retV;
    retV.data[0]=axis[0].data[0]*v.data[0]+axis[1].data[0]*v.data[1]+axis[2].data[0]*v.data[2];
    retV.data[1]=axis[0].data[1]*v.data[0]+axis[1].data[1]*v.data[1]+axis[2].data[1]*v.data[2];
    retV.data[2]=axis[0].data[2]*v.data[0]+axis[1].data[2]*v.data[1]+axis[2].data[2]*v.data[2];
    return(retV);
}

C3X3Matrix& C3X3Matrix::operator= (const C3X3Matrix& m)
{
    axis[0].data[0]=m.axis[0].data[0];
    axis[1].data[0]=m.axis[1].data[0];
    axis[2].data[0]=m.axis[2].data[0];
    axis[0].data[1]=m.axis[0].data[1];
    axis[1].data[1]=m.axis[1].data[1];
    axis[2].data[1]=m.axis[2].data[1];
    axis[0].data[2]=m.axis[0].data[2];
    axis[1].data[2]=m.axis[1].data[2];
    axis[2].data[2]=m.axis[2].data[2];
    return(*this);
}

bool C3X3Matrix::operator!= (const C3X3Matrix& m)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (axis[j].data[i] != m.axis[j].data[i])
                return true;
        }
    }
    return false;
}


void C3X3Matrix::setAxes(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis)
{
    axis[0]=xAxis;
    axis[1]=yAxis;
    axis[2]=zAxis;
}
