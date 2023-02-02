#include "3X3Matrix.h"
#include "4Vector.h"
#include "MyMath.h"

C3X3Matrix::C3X3Matrix()
{

}

C3X3Matrix::C3X3Matrix(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis)
{
    (*this).axis[0]=xAxis;
    (*this).axis[1]=yAxis;
    (*this).axis[2]=zAxis;
}

C3X3Matrix::C3X3Matrix(const C4Vector& q)
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
    axis[0](0)=C*E;
    axis[1](0)=-C*F;
    axis[2](0)=D;
    axis[0](1)=BD*E+A*F;
    axis[1](1)=-BD*F+A*E;
    axis[2](1)=-B*C;
    axis[0](2)=-AD*E+B*F;
    axis[1](2)=AD*F+B*E;
    axis[2](2)=A*C;
}

void C3X3Matrix::setEulerAngles(const C3Vector& v)
{ // v(0), v(1), v(2) are in radian!
    setEulerAngles(v(0),v(1),v(2));
}

C3Vector C3X3Matrix::getEulerAngles() const
{ // Angles are in radians!! // THERE IS ANOTHER SUCH ROUTINE IN C4X4MATRIX
    C3Vector retV;
    simReal m02=axis[2](0);
    if (m02>1.0)
        m02=1.0;   // Just in case
    if (m02<-1.0)
        m02=-1.0;  // Just in case
    
    retV(1)=CMath::robustAsin(m02);
    if (m02<0.0)
        m02=-m02;
    if (m02<simReal(0.999995))
    {   // No gimbal lock
        retV(0)=atan2(-axis[2](1),axis[2](2));
        retV(2)=atan2(-axis[1](0),axis[0](0));
    }
    else
    {   // Gimbal lock has occured
        retV(0)=0.0;
        retV(2)=atan2(axis[0](1),axis[1](1));
    }
    return(retV);
}

C4Vector C3X3Matrix::getQuaternion() const
{   
    C4Vector retV;
    simReal trace=axis[0](0)+axis[1](1)+axis[2](2);
    if (trace>=0.0)    // trace>0.00000001)
    {
        simReal s=sqrt(trace+1.0)*2.0;
        retV(1)=(axis[1](2)-axis[2](1))/s;
        retV(2)=(axis[2](0)-axis[0](2))/s;
        retV(3)=(axis[0](1)-axis[1](0))/s;
        retV(0)=simReal(0.25)*s;
    }
    else
    {
        if ((axis[0](0)>=axis[1](1))&&(axis[0](0)>=axis[2](2)))
        {
            simReal s=sqrt(1.0+axis[0](0)-axis[1](1)-axis[2](2))*2.0;
            retV(1)=simReal(0.25)*s;
            retV(2)=(axis[0](1)+axis[1](0))/s;
            retV(3)=(axis[2](0)+axis[0](2))/s;
            retV(0)=(axis[1](2)-axis[2](1))/s;
        }
        else
        {
            if ((axis[1](1)>=axis[0](0))&&(axis[1](1)>=axis[2](2)))
            {
                simReal s=sqrt(1.0+axis[1](1)-axis[0](0)-axis[2](2))*2.0;
                retV(1)=(axis[0](1)+axis[1](0))/s;
                retV(2)=simReal(0.25)*s;
                retV(3)=(axis[1](2)+axis[2](1))/s;
                retV(0)=(axis[2](0)-axis[0](2))/s;
            }
            else
            {
                simReal s=sqrt(1.0+axis[2](2)-axis[0](0)-axis[1](1))*2.0;
                retV(1)=(axis[2](0)+axis[0](2))/s;
                retV(2)=(axis[1](2)+axis[2](1))/s;
                retV(3)=simReal(0.25)*s;
                retV(0)=(axis[0](1)-axis[1](0))/s;
            }
        }
    }
    retV.normalize(); // Really needed?
    return(retV);
}

void C3X3Matrix::buildInterpolation(const C3X3Matrix& fromThis,const C3X3Matrix& toThat,simReal t)
{   // Builds the interpolation (based on t) from 'fromThis' to 'toThat'
    C4Vector out;
    out.buildInterpolation(fromThis.getQuaternion(),toThat.getQuaternion(),t);
    (*this)=out;
}

void C3X3Matrix::buildXRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0](0)=1.0;
    axis[1](0)=0.0;
    axis[2](0)=0.0;
    axis[0](1)=0.0;
    axis[1](1)=c;
    axis[2](1)=-s;
    axis[0](2)=0.0;
    axis[1](2)=s;
    axis[2](2)=c;
}

void C3X3Matrix::buildYRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0](0)=c;
    axis[1](0)=0.0;
    axis[2](0)=s;
    axis[0](1)=0.0;
    axis[1](1)=1.0;
    axis[2](1)=0.0;
    axis[0](2)=-s;
    axis[1](2)=0.0;
    axis[2](2)=c;
}

void C3X3Matrix::buildZRotation(simReal angle)
{
    simReal c=cos(angle);
    simReal s=sin(angle);
    axis[0](0)=c;
    axis[1](0)=-s;
    axis[2](0)=0.0;
    axis[0](1)=s;
    axis[1](1)=c;
    axis[2](1)=0.0;
    axis[0](2)=0.0;
    axis[1](2)=0.0;
    axis[2](2)=1.0;
}

C3Vector C3X3Matrix::getNormalVector() const
{ // returns the normal vector to the plane described by axis[0],axis[1],axis[2]
    C3Vector v0(axis[0]-axis[1]);
    C3Vector v1(axis[1]-axis[2]);
    return((v0^v1).getNormalized());
}

simReal& C3X3Matrix::operator() (size_t i,size_t j)
{
    return(axis[j](i));
}

const simReal& C3X3Matrix::operator() (size_t i,size_t j) const
{
    return(axis[j](i));
}

void C3X3Matrix::clear()
{
    axis[0](0)=0.0;
    axis[0](1)=0.0;
    axis[0](2)=0.0;
    axis[1](0)=0.0;
    axis[1](1)=0.0;
    axis[1](2)=0.0;
    axis[2](0)=0.0;
    axis[2](1)=0.0;
    axis[2](2)=0.0;
}

void C3X3Matrix::setIdentity()
{
    axis[0](0)=1.0;
    axis[0](1)=0.0;
    axis[0](2)=0.0;
    axis[1](0)=0.0;
    axis[1](1)=1.0;
    axis[1](2)=0.0;
    axis[2](0)=0.0;
    axis[2](1)=0.0;
    axis[2](2)=1.0;
}

void C3X3Matrix::transpose()
{
    (*this)=getTranspose();
}

void C3X3Matrix::setData(const simReal v[9])
{
    axis[0](0)=v[0];
    axis[1](0)=v[1];
    axis[2](0)=v[2];
    axis[0](1)=v[3];
    axis[1](1)=v[4];
    axis[2](1)=v[5];
    axis[0](2)=v[6];
    axis[1](2)=v[7];
    axis[2](2)=v[8];
}

void C3X3Matrix::getData(simReal v[9]) const
{
    v[0]=axis[0](0);
    v[1]=axis[1](0);
    v[2]=axis[2](0);
    v[3]=axis[0](1);
    v[4]=axis[1](1);
    v[5]=axis[2](1);
    v[6]=axis[0](2);
    v[7]=axis[1](2);
    v[8]=axis[2](2);
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
    retM(0,0)=axis[0](0);
    retM(0,1)=axis[0](1);
    retM(0,2)=axis[0](2);
    retM(1,0)=axis[1](0);
    retM(1,1)=axis[1](1);
    retM(1,2)=axis[1](2);
    retM(2,0)=axis[2](0);
    retM(2,1)=axis[2](1);
    retM(2,2)=axis[2](2);
    return(retM);
}

C3X3Matrix C3X3Matrix::operator* (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)*m(0,0)+axis[1](0)*m(1,0)+axis[2](0)*m(2,0);
    retM(0,1)=axis[0](0)*m(0,1)+axis[1](0)*m(1,1)+axis[2](0)*m(2,1);
    retM(0,2)=axis[0](0)*m(0,2)+axis[1](0)*m(1,2)+axis[2](0)*m(2,2);
    retM(1,0)=axis[0](1)*m(0,0)+axis[1](1)*m(1,0)+axis[2](1)*m(2,0);
    retM(1,1)=axis[0](1)*m(0,1)+axis[1](1)*m(1,1)+axis[2](1)*m(2,1);
    retM(1,2)=axis[0](1)*m(0,2)+axis[1](1)*m(1,2)+axis[2](1)*m(2,2);
    retM(2,0)=axis[0](2)*m(0,0)+axis[1](2)*m(1,0)+axis[2](2)*m(2,0);
    retM(2,1)=axis[0](2)*m(0,1)+axis[1](2)*m(1,1)+axis[2](2)*m(2,1);
    retM(2,2)=axis[0](2)*m(0,2)+axis[1](2)*m(1,2)+axis[2](2)*m(2,2);
    return(retM);
}

C3X3Matrix C3X3Matrix::operator+ (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)+m(0,0);
    retM(0,1)=axis[1](0)+m(0,1);
    retM(0,2)=axis[2](0)+m(0,2);
    retM(1,0)=axis[0](1)+m(1,0);
    retM(1,1)=axis[1](1)+m(1,1);
    retM(1,2)=axis[2](1)+m(1,2);
    retM(2,0)=axis[0](2)+m(2,0);
    retM(2,1)=axis[1](2)+m(2,1);
    retM(2,2)=axis[2](2)+m(2,2);
    return(retM);
}

C3X3Matrix C3X3Matrix::operator- (const C3X3Matrix& m) const
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)-m(0,0);
    retM(0,1)=axis[1](0)-m(0,1);
    retM(0,2)=axis[2](0)-m(0,2);
    retM(1,0)=axis[0](1)-m(1,0);
    retM(1,1)=axis[1](1)-m(1,1);
    retM(1,2)=axis[2](1)-m(1,2);
    retM(2,0)=axis[0](2)-m(2,0);
    retM(2,1)=axis[1](2)-m(2,1);
    retM(2,2)=axis[2](2)-m(2,2);
    return(retM);
}

C3X3Matrix C3X3Matrix::operator* (simReal f) const
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)*f;
    retM(0,1)=axis[1](0)*f;
    retM(0,2)=axis[2](0)*f;
    retM(1,0)=axis[0](1)*f;
    retM(1,1)=axis[1](1)*f;
    retM(1,2)=axis[2](1)*f;
    retM(2,0)=axis[0](2)*f;
    retM(2,1)=axis[1](2)*f;
    retM(2,2)=axis[2](2)*f;
    return(retM);
}

C3X3Matrix C3X3Matrix::operator/ (simReal f) const
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)/f;
    retM(0,1)=axis[1](0)/f;
    retM(0,2)=axis[2](0)/f;
    retM(1,0)=axis[0](1)/f;
    retM(1,1)=axis[1](1)/f;
    retM(1,2)=axis[2](1)/f;
    retM(2,0)=axis[0](2)/f;
    retM(2,1)=axis[1](2)/f;
    retM(2,2)=axis[2](2)/f;
    return(retM);
}
void C3X3Matrix::operator*= (const C3X3Matrix& m)
{
    C3X3Matrix retM;
    retM(0,0)=axis[0](0)*m(0,0)+axis[1](0)*m(1,0)+axis[2](0)*m(2,0);
    retM(0,1)=axis[0](0)*m(0,1)+axis[1](0)*m(1,1)+axis[2](0)*m(2,1);
    retM(0,2)=axis[0](0)*m(0,2)+axis[1](0)*m(1,2)+axis[2](0)*m(2,2);
    retM(1,0)=axis[0](1)*m(0,0)+axis[1](1)*m(1,0)+axis[2](1)*m(2,0);
    retM(1,1)=axis[0](1)*m(0,1)+axis[1](1)*m(1,1)+axis[2](1)*m(2,1);
    retM(1,2)=axis[0](1)*m(0,2)+axis[1](1)*m(1,2)+axis[2](1)*m(2,2);
    retM(2,0)=axis[0](2)*m(0,0)+axis[1](2)*m(1,0)+axis[2](2)*m(2,0);
    retM(2,1)=axis[0](2)*m(0,1)+axis[1](2)*m(1,1)+axis[2](2)*m(2,1);
    retM(2,2)=axis[0](2)*m(0,2)+axis[1](2)*m(1,2)+axis[2](2)*m(2,2);
    (*this)=retM;
}

void C3X3Matrix::operator+= (const C3X3Matrix& m)
{
    axis[0](0)+=m(0,0);
    axis[1](0)+=m(0,1);
    axis[2](0)+=m(0,2);
    axis[0](1)+=m(1,0);
    axis[1](1)+=m(1,1);
    axis[2](1)+=m(1,2);
    axis[0](2)+=m(2,0);
    axis[1](2)+=m(2,1);
    axis[2](2)+=m(2,2);
}

void C3X3Matrix::operator-= (const C3X3Matrix& m)
{
    axis[0](0)-=m(0,0);
    axis[1](0)-=m(0,1);
    axis[2](0)-=m(0,2);
    axis[0](1)-=m(1,0);
    axis[1](1)-=m(1,1);
    axis[2](1)-=m(1,2);
    axis[0](2)-=m(2,0);
    axis[1](2)-=m(2,1);
    axis[2](2)-=m(2,2);
}

void C3X3Matrix::operator*= (simReal f)
{
    axis[0](0)*=f;
    axis[1](0)*=f;
    axis[2](0)*=f;
    axis[0](1)*=f;
    axis[1](1)*=f;
    axis[2](1)*=f;
    axis[0](2)*=f;
    axis[1](2)*=f;
    axis[2](2)*=f;
}

void C3X3Matrix::operator/= (simReal f)
{
    axis[0](0)/=f;
    axis[1](0)/=f;
    axis[2](0)/=f;
    axis[0](1)/=f;
    axis[1](1)/=f;
    axis[2](1)/=f;
    axis[0](2)/=f;
    axis[1](2)/=f;
    axis[2](2)/=f;
}

C3Vector C3X3Matrix::operator* (const C3Vector& v) const
{
    C3Vector retV;
    retV(0)=axis[0](0)*v(0)+axis[1](0)*v(1)+axis[2](0)*v(2);
    retV(1)=axis[0](1)*v(0)+axis[1](1)*v(1)+axis[2](1)*v(2);
    retV(2)=axis[0](2)*v(0)+axis[1](2)*v(1)+axis[2](2)*v(2);
    return(retV);
}

C3X3Matrix& C3X3Matrix::operator= (const C3X3Matrix& m)
{
    axis[0](0)=m(0,0);
    axis[1](0)=m(0,1);
    axis[2](0)=m(0,2);
    axis[0](1)=m(1,0);
    axis[1](1)=m(1,1);
    axis[2](1)=m(1,2);
    axis[0](2)=m(2,0);
    axis[1](2)=m(2,1);
    axis[2](2)=m(2,2);
    return(*this);
}

void C3X3Matrix::setAxes(const C3Vector& xAxis,const C3Vector& yAxis,const C3Vector& zAxis)
{
    axis[0]=xAxis;
    axis[1]=yAxis;
    axis[2]=zAxis;
}
