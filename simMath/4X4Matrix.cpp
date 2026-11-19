#include "4X4Matrix.h"
#include "mXnMatrix.h"

C4X4Matrix::C4X4Matrix()
{
}

C4X4Matrix::C4X4Matrix(const C3X3Matrix& m,const C3Vector& x)
{
    M=m;
    X=x;
}

C4X4Matrix::C4X4Matrix(const CPose& transf)
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
{ // The matrix has to be 4x4 (or 3x4), row-major. Otherwise this matrix is reset to identity.
    if ((m.rows<3)||(m.cols<4))
    {
        setIdentity();
        return(*this);
    }
    const size_t s=m.cols;
    M.axis[0].data[0]=m.data[0*s+0];
    M.axis[0].data[1]=m.data[1*s+0];
    M.axis[0].data[2]=m.data[2*s+0];
    M.axis[1].data[0]=m.data[0*s+1];
    M.axis[1].data[1]=m.data[1*s+1];
    M.axis[1].data[2]=m.data[2*s+1];
    M.axis[2].data[0]=m.data[0*s+2];
    M.axis[2].data[1]=m.data[1*s+2];
    M.axis[2].data[2]=m.data[2*s+2];
    X.data[0]=m.data[0*s+3];
    X.data[1]=m.data[1*s+3];
    X.data[2]=m.data[2*s+3];
    return(*this);
}

CPose C4X4Matrix::getTransformation() const
{
    return(CPose(M.getQuaternion(),X));
}


void C4X4Matrix::buildInterpolation(const C4X4Matrix& fromThis,const C4X4Matrix& toThat,simReal t)
{   // Builds the interpolation (based on t) from 'fromThis' to 'toThat'
    CPose out;
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
    X.data[0]=x;
    X.data[1]=y;
    X.data[2]=z;
}

void C4X4Matrix::translate(simReal x,simReal y,simReal z)
{
    X.data[0]+=x;
    X.data[1]+=y;
    X.data[2]+=z;
}

void C4X4Matrix::inverse()
{ // Fast inverse, valid only for rigid transformations (M has to be orthonormal)
    // Speed optimized version:
    simReal tmp=M.axis[0].data[1];
    M.axis[0].data[1]=M.axis[1].data[0];
    M.axis[1].data[0]=tmp;;
    tmp=M.axis[0].data[2];
    M.axis[0].data[2]=M.axis[2].data[0];
    M.axis[2].data[0]=tmp;;
    tmp=M.axis[1].data[2];
    M.axis[1].data[2]=M.axis[2].data[1];
    M.axis[2].data[1]=tmp;;
    simReal v[3]={-X.data[0],-X.data[1],-X.data[2]};
    X.data[0]=M.axis[0].data[0]*v[0]+M.axis[1].data[0]*v[1]+M.axis[2].data[0]*v[2];
    X.data[1]=M.axis[0].data[1]*v[0]+M.axis[1].data[1]*v[1]+M.axis[2].data[1]*v[2];
    X.data[2]=M.axis[0].data[2]*v[0]+M.axis[1].data[2]*v[1]+M.axis[2].data[2]*v[2];
    // Normal version:
    //  (*this)=getInverse();
}
void C4X4Matrix::getData(simReal* m) const
{
    for (size_t i=0;i<3;i++)
    {
        m[4*i+0]=M.axis[0].data[i];
        m[4*i+1]=M.axis[1].data[i];
        m[4*i+2]=M.axis[2].data[i];
        m[4*i+3]=X.data[i];
    }
}

void C4X4Matrix::setData(const simReal* m)
{
    for (size_t i=0;i<3;i++)
    {
        M.axis[0].data[i]=m[4*i+0];
        M.axis[1].data[i]=m[4*i+1];
        M.axis[2].data[i]=m[4*i+2];
        X.data[i]=m[4*i+3];
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
    M.axis[0].data[0]=m1.M.axis[0].data[0]*m2.M.axis[0].data[0]+m1.M.axis[1].data[0]*m2.M.axis[0].data[1]+m1.M.axis[2].data[0]*m2.M.axis[0].data[2];
    M.axis[0].data[1]=m1.M.axis[0].data[1]*m2.M.axis[0].data[0]+m1.M.axis[1].data[1]*m2.M.axis[0].data[1]+m1.M.axis[2].data[1]*m2.M.axis[0].data[2];
    M.axis[0].data[2]=m1.M.axis[0].data[2]*m2.M.axis[0].data[0]+m1.M.axis[1].data[2]*m2.M.axis[0].data[1]+m1.M.axis[2].data[2]*m2.M.axis[0].data[2];
    M.axis[1].data[0]=m1.M.axis[0].data[0]*m2.M.axis[1].data[0]+m1.M.axis[1].data[0]*m2.M.axis[1].data[1]+m1.M.axis[2].data[0]*m2.M.axis[1].data[2];
    M.axis[1].data[1]=m1.M.axis[0].data[1]*m2.M.axis[1].data[0]+m1.M.axis[1].data[1]*m2.M.axis[1].data[1]+m1.M.axis[2].data[1]*m2.M.axis[1].data[2];
    M.axis[1].data[2]=m1.M.axis[0].data[2]*m2.M.axis[1].data[0]+m1.M.axis[1].data[2]*m2.M.axis[1].data[1]+m1.M.axis[2].data[2]*m2.M.axis[1].data[2];
    M.axis[2].data[0]=m1.M.axis[0].data[0]*m2.M.axis[2].data[0]+m1.M.axis[1].data[0]*m2.M.axis[2].data[1]+m1.M.axis[2].data[0]*m2.M.axis[2].data[2];
    M.axis[2].data[1]=m1.M.axis[0].data[1]*m2.M.axis[2].data[0]+m1.M.axis[1].data[1]*m2.M.axis[2].data[1]+m1.M.axis[2].data[1]*m2.M.axis[2].data[2];
    M.axis[2].data[2]=m1.M.axis[0].data[2]*m2.M.axis[2].data[0]+m1.M.axis[1].data[2]*m2.M.axis[2].data[1]+m1.M.axis[2].data[2]*m2.M.axis[2].data[2];
    X.data[0]=m1.M.axis[0].data[0]*m2.X.data[0]+m1.M.axis[1].data[0]*m2.X.data[1]+m1.M.axis[2].data[0]*m2.X.data[2]+m1.X.data[0];
    X.data[1]=m1.M.axis[0].data[1]*m2.X.data[0]+m1.M.axis[1].data[1]*m2.X.data[1]+m1.M.axis[2].data[1]*m2.X.data[2]+m1.X.data[1];
    X.data[2]=m1.M.axis[0].data[2]*m2.X.data[0]+m1.M.axis[1].data[2]*m2.X.data[1]+m1.M.axis[2].data[2]*m2.X.data[2]+m1.X.data[2];
}

C4X4Matrix C4X4Matrix::operator* (const C4X4Matrix& m) const
{   // Speed optimized version:
    C4X4Matrix retM;
    retM.M.axis[0].data[0]=M.axis[0].data[0]*m.M.axis[0].data[0]+M.axis[1].data[0]*m.M.axis[0].data[1]+M.axis[2].data[0]*m.M.axis[0].data[2];
    retM.M.axis[0].data[1]=M.axis[0].data[1]*m.M.axis[0].data[0]+M.axis[1].data[1]*m.M.axis[0].data[1]+M.axis[2].data[1]*m.M.axis[0].data[2];
    retM.M.axis[0].data[2]=M.axis[0].data[2]*m.M.axis[0].data[0]+M.axis[1].data[2]*m.M.axis[0].data[1]+M.axis[2].data[2]*m.M.axis[0].data[2];
    retM.M.axis[1].data[0]=M.axis[0].data[0]*m.M.axis[1].data[0]+M.axis[1].data[0]*m.M.axis[1].data[1]+M.axis[2].data[0]*m.M.axis[1].data[2];
    retM.M.axis[1].data[1]=M.axis[0].data[1]*m.M.axis[1].data[0]+M.axis[1].data[1]*m.M.axis[1].data[1]+M.axis[2].data[1]*m.M.axis[1].data[2];
    retM.M.axis[1].data[2]=M.axis[0].data[2]*m.M.axis[1].data[0]+M.axis[1].data[2]*m.M.axis[1].data[1]+M.axis[2].data[2]*m.M.axis[1].data[2];
    retM.M.axis[2].data[0]=M.axis[0].data[0]*m.M.axis[2].data[0]+M.axis[1].data[0]*m.M.axis[2].data[1]+M.axis[2].data[0]*m.M.axis[2].data[2];
    retM.M.axis[2].data[1]=M.axis[0].data[1]*m.M.axis[2].data[0]+M.axis[1].data[1]*m.M.axis[2].data[1]+M.axis[2].data[1]*m.M.axis[2].data[2];
    retM.M.axis[2].data[2]=M.axis[0].data[2]*m.M.axis[2].data[0]+M.axis[1].data[2]*m.M.axis[2].data[1]+M.axis[2].data[2]*m.M.axis[2].data[2];
    retM.X.data[0]=M.axis[0].data[0]*m.X.data[0]+M.axis[1].data[0]*m.X.data[1]+M.axis[2].data[0]*m.X.data[2]+X.data[0];
    retM.X.data[1]=M.axis[0].data[1]*m.X.data[0]+M.axis[1].data[1]*m.X.data[1]+M.axis[2].data[1]*m.X.data[2]+X.data[1];
    retM.X.data[2]=M.axis[0].data[2]*m.X.data[0]+M.axis[1].data[2]*m.X.data[1]+M.axis[2].data[2]*m.X.data[2]+X.data[2];
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
    return(C3Vector(M.axis[0].data[0]*v.data[0]+M.axis[1].data[0]*v.data[1]+M.axis[2].data[0]*v.data[2]+X.data[0],
        M.axis[0].data[1]*v.data[0]+M.axis[1].data[1]*v.data[1]+M.axis[2].data[1]*v.data[2]+X.data[1],
        M.axis[0].data[2]*v.data[0]+M.axis[1].data[2]*v.data[1]+M.axis[2].data[2]*v.data[2]+X.data[2]));
    // Normal version:
    //  return(C3Vector((M*v)+X));
}

C4X4Matrix& C4X4Matrix::operator= (const C4X4Matrix& m)
{
    // Speed optimized version:
    M.axis[0].data[0]=m.M.axis[0].data[0];
    M.axis[0].data[1]=m.M.axis[0].data[1];
    M.axis[0].data[2]=m.M.axis[0].data[2];
    M.axis[1].data[0]=m.M.axis[1].data[0];
    M.axis[1].data[1]=m.M.axis[1].data[1];
    M.axis[1].data[2]=m.M.axis[1].data[2];
    M.axis[2].data[0]=m.M.axis[2].data[0];
    M.axis[2].data[1]=m.M.axis[2].data[1];
    M.axis[2].data[2]=m.M.axis[2].data[2];
    X.data[0]=m.X.data[0];
    X.data[1]=m.X.data[1];
    X.data[2]=m.X.data[2];
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
