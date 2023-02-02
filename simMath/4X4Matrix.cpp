#include "4X4Matrix.h"
#include "MMatrix.h"

C4X4Matrix::C4X4Matrix()
{
}

C4X4Matrix::C4X4Matrix(const C3X3Matrix& m,const C3Vector& x)
{
    M=m;
    X=x;
}

C4X4Matrix::C4X4Matrix(const C7Vector& transf)
{
    M=transf.Q.getMatrix();
    X=transf.X;
}

C4X4Matrix::C4X4Matrix(const C4X4Matrix& m)
{
    (*this)=m;
}

C4X4Matrix::C4X4Matrix(const CMatrix& m)
{
    (*this)=m;
}

C4X4Matrix::C4X4Matrix(const C3Vector& x,const C3Vector& y,const C3Vector& z,const C3Vector& pos)
{
    M.setAxes(x,y,z);
    X=pos;
}

C4X4Matrix::~C4X4Matrix()
{
}

void C4X4Matrix::setIdentity()
{
    M.setIdentity();
    X.clear();
}

C4X4Matrix C4X4Matrix::operator* (const CMatrix& m) const
{
    C4X4Matrix retM((*this)*C4X4Matrix(m));
    return(retM);
}

C4X4Matrix& C4X4Matrix::operator= (const CMatrix& m)
{
    M.axis[0](0)=m.data[0];
    M.axis[0](1)=m.data[4];
    M.axis[0](2)=m.data[8];
    M.axis[1](0)=m.data[1];
    M.axis[1](1)=m.data[5];
    M.axis[1](2)=m.data[9];
    M.axis[2](0)=m.data[2];
    M.axis[2](1)=m.data[6];
    M.axis[2](2)=m.data[10];
    X(0)=m.data[3];
    X(1)=m.data[7];
    X(2)=m.data[11];
    return(*this);
}

C7Vector C4X4Matrix::getTransformation() const
{
    return(C7Vector(M.getQuaternion(),X));
}


void C4X4Matrix::buildInterpolation(const C4X4Matrix& fromThis,const C4X4Matrix& toThat,simReal t)
{   // Builds the interpolation (based on t) from 'fromThis' to 'toThat'
    C7Vector out;
    out.buildInterpolation(fromThis.getTransformation(),toThat.getTransformation(),t);
    (*this)=out;
}

void C4X4Matrix::rotateAroundX(simReal angle)
{
    C4X4Matrix rot;
    rot.setIdentity();
    rot.M.buildXRotation(angle);
    (*this)=rot*(*this);
}

void C4X4Matrix::rotateAroundY(simReal angle)
{
    C4X4Matrix rot;
    rot.setIdentity();
    rot.M.buildYRotation(angle);
    (*this)=rot*(*this);
}

void C4X4Matrix::rotateAroundZ(simReal angle)
{
    C4X4Matrix rot;
    rot.setIdentity();
    rot.M.buildZRotation(angle);
    (*this)=rot*(*this);
}

void C4X4Matrix::buildXRotation(simReal angle)
{
    setIdentity();
    M.buildXRotation(angle);
}

void C4X4Matrix::buildYRotation(simReal angle)
{
    setIdentity();
    M.buildYRotation(angle);
}

void C4X4Matrix::buildZRotation(simReal angle)
{
    setIdentity();
    M.buildZRotation(angle);
}

void C4X4Matrix::buildTranslation(simReal x,simReal y,simReal z)
{
    setIdentity();
    X(0)=x;
    X(1)=y;
    X(2)=z;
}

void C4X4Matrix::translate(simReal x,simReal y,simReal z)
{
    X(0)+=x;
    X(1)+=y;
    X(2)+=z;
}

void C4X4Matrix::inverse()
{
    // Speed optimized version:
    simReal tmp=M.axis[0](1);
    M.axis[0](1)=M.axis[1](0);
    M.axis[1](0)=tmp;;
    tmp=M.axis[0](2);
    M.axis[0](2)=M.axis[2](0);
    M.axis[2](0)=tmp;;
    tmp=M.axis[1](2);
    M.axis[1](2)=M.axis[2](1);
    M.axis[2](1)=tmp;;
    simReal v[3]={-X(0),-X(1),-X(2)};
    X(0)=M.axis[0](0)*v[0]+M.axis[1](0)*v[1]+M.axis[2](0)*v[2];
    X(1)=M.axis[0](1)*v[0]+M.axis[1](1)*v[1]+M.axis[2](1)*v[2];
    X(2)=M.axis[0](2)*v[0]+M.axis[1](2)*v[1]+M.axis[2](2)*v[2];
    // Normal version:
    //  (*this)=getInverse();
}
void C4X4Matrix::getData(simReal* m) const
{
    for (size_t i=0;i<3;i++)
    {
        m[4*i+0]=M.axis[0](i);
        m[4*i+1]=M.axis[1](i);
        m[4*i+2]=M.axis[2](i);
        m[4*i+3]=X(i);
    }
}

void C4X4Matrix::setData(const simReal* m)
{
    for (size_t i=0;i<3;i++)
    {
        M.axis[0](i)=m[4*i+0];
        M.axis[1](i)=m[4*i+1];
        M.axis[2](i)=m[4*i+2];
        X(i)=m[4*i+3];
    }
}

bool C4X4Matrix::isValid() const
{
    if (!M.isValid())
        return(false);
    if (!X.isValid())
        return(false);
    return(true);
}

C4X4Matrix C4X4Matrix::getInverse() const
{
    C4X4Matrix retM(*this);
    retM.inverse();
    return(retM);
}

void C4X4Matrix::setMultResult(const C4X4Matrix& m1,const C4X4Matrix& m2)
{ // Use this routine to avoid temporary variables
    M.axis[0](0)=m1.M.axis[0](0)*m2.M.axis[0](0)+m1.M.axis[1](0)*m2.M.axis[0](1)+m1.M.axis[2](0)*m2.M.axis[0](2);
    M.axis[0](1)=m1.M.axis[0](1)*m2.M.axis[0](0)+m1.M.axis[1](1)*m2.M.axis[0](1)+m1.M.axis[2](1)*m2.M.axis[0](2);
    M.axis[0](2)=m1.M.axis[0](2)*m2.M.axis[0](0)+m1.M.axis[1](2)*m2.M.axis[0](1)+m1.M.axis[2](2)*m2.M.axis[0](2);
    M.axis[1](0)=m1.M.axis[0](0)*m2.M.axis[1](0)+m1.M.axis[1](0)*m2.M.axis[1](1)+m1.M.axis[2](0)*m2.M.axis[1](2);
    M.axis[1](1)=m1.M.axis[0](1)*m2.M.axis[1](0)+m1.M.axis[1](1)*m2.M.axis[1](1)+m1.M.axis[2](1)*m2.M.axis[1](2);
    M.axis[1](2)=m1.M.axis[0](2)*m2.M.axis[1](0)+m1.M.axis[1](2)*m2.M.axis[1](1)+m1.M.axis[2](2)*m2.M.axis[1](2);
    M.axis[2](0)=m1.M.axis[0](0)*m2.M.axis[2](0)+m1.M.axis[1](0)*m2.M.axis[2](1)+m1.M.axis[2](0)*m2.M.axis[2](2);
    M.axis[2](1)=m1.M.axis[0](1)*m2.M.axis[2](0)+m1.M.axis[1](1)*m2.M.axis[2](1)+m1.M.axis[2](1)*m2.M.axis[2](2);
    M.axis[2](2)=m1.M.axis[0](2)*m2.M.axis[2](0)+m1.M.axis[1](2)*m2.M.axis[2](1)+m1.M.axis[2](2)*m2.M.axis[2](2);
    X(0)=m1.M.axis[0](0)*m2.X(0)+m1.M.axis[1](0)*m2.X(1)+m1.M.axis[2](0)*m2.X(2)+m1.X(0);
    X(1)=m1.M.axis[0](1)*m2.X(0)+m1.M.axis[1](1)*m2.X(1)+m1.M.axis[2](1)*m2.X(2)+m1.X(1);
    X(2)=m1.M.axis[0](2)*m2.X(0)+m1.M.axis[1](2)*m2.X(1)+m1.M.axis[2](2)*m2.X(2)+m1.X(2);
}

C4X4Matrix C4X4Matrix::operator* (const C4X4Matrix& m) const
{   // Speed optimized version:
    C4X4Matrix retM;
    retM.M.axis[0](0)=M.axis[0](0)*m.M.axis[0](0)+M.axis[1](0)*m.M.axis[0](1)+M.axis[2](0)*m.M.axis[0](2);
    retM.M.axis[0](1)=M.axis[0](1)*m.M.axis[0](0)+M.axis[1](1)*m.M.axis[0](1)+M.axis[2](1)*m.M.axis[0](2);
    retM.M.axis[0](2)=M.axis[0](2)*m.M.axis[0](0)+M.axis[1](2)*m.M.axis[0](1)+M.axis[2](2)*m.M.axis[0](2);
    retM.M.axis[1](0)=M.axis[0](0)*m.M.axis[1](0)+M.axis[1](0)*m.M.axis[1](1)+M.axis[2](0)*m.M.axis[1](2);
    retM.M.axis[1](1)=M.axis[0](1)*m.M.axis[1](0)+M.axis[1](1)*m.M.axis[1](1)+M.axis[2](1)*m.M.axis[1](2);
    retM.M.axis[1](2)=M.axis[0](2)*m.M.axis[1](0)+M.axis[1](2)*m.M.axis[1](1)+M.axis[2](2)*m.M.axis[1](2);
    retM.M.axis[2](0)=M.axis[0](0)*m.M.axis[2](0)+M.axis[1](0)*m.M.axis[2](1)+M.axis[2](0)*m.M.axis[2](2);
    retM.M.axis[2](1)=M.axis[0](1)*m.M.axis[2](0)+M.axis[1](1)*m.M.axis[2](1)+M.axis[2](1)*m.M.axis[2](2);
    retM.M.axis[2](2)=M.axis[0](2)*m.M.axis[2](0)+M.axis[1](2)*m.M.axis[2](1)+M.axis[2](2)*m.M.axis[2](2);
    retM.X(0)=M.axis[0](0)*m.X(0)+M.axis[1](0)*m.X(1)+M.axis[2](0)*m.X(2)+X(0);
    retM.X(1)=M.axis[0](1)*m.X(0)+M.axis[1](1)*m.X(1)+M.axis[2](1)*m.X(2)+X(1);
    retM.X(2)=M.axis[0](2)*m.X(0)+M.axis[1](2)*m.X(1)+M.axis[2](2)*m.X(2)+X(2);
    return(retM);
    /*  // Normal version:
    C4X4Matrix retM;
    retM.M=M*m.M;
    retM.X=(M*m.X)+X;
    return(retM);
    //  */
}

C3Vector C4X4Matrix::operator* (const C3Vector& v) const
{
    // Speed optimized version:
    return(C3Vector(M.axis[0](0)*v(0)+M.axis[1](0)*v(1)+M.axis[2](0)*v(2)+X(0),
        M.axis[0](1)*v(0)+M.axis[1](1)*v(1)+M.axis[2](1)*v(2)+X(1),
        M.axis[0](2)*v(0)+M.axis[1](2)*v(1)+M.axis[2](2)*v(2)+X(2)));
    // Normal version:
    //  return(C3Vector((M*v)+X));
}

C4X4Matrix& C4X4Matrix::operator= (const C4X4Matrix& m)
{
    // Speed optimized version:
    M.axis[0](0)=m.M.axis[0](0);
    M.axis[0](1)=m.M.axis[0](1);
    M.axis[0](2)=m.M.axis[0](2);
    M.axis[1](0)=m.M.axis[1](0);
    M.axis[1](1)=m.M.axis[1](1);
    M.axis[1](2)=m.M.axis[1](2);
    M.axis[2](0)=m.M.axis[2](0);
    M.axis[2](1)=m.M.axis[2](1);
    M.axis[2](2)=m.M.axis[2](2);
    X(0)=m.X(0);
    X(1)=m.X(1);
    X(2)=m.X(2);
    return(*this);
    /*  // Normal version:
    M=m.M;
    X=m.X;
    return(*this);
    //  */
}

void C4X4Matrix::operator*= (const C4X4Matrix& m)
{
    C4X4Matrix retM((*this)*m);
    (*this)=retM;
}
