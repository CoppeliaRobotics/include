#include "MMatrix.h"
#include "mathDefines.h"

CMatrix::CMatrix()
{
    rows=0;
    cols=0;
}

CMatrix::CMatrix(size_t nRows,size_t nCols)
{
    data.resize(nRows*nCols);
    rows=nRows;
    cols=nCols;
}

CMatrix::CMatrix(const C3X3Matrix& m)
{
    data.resize(9);
    rows=3;
    cols=3;
    (*this)=m;
}

CMatrix::CMatrix(const C4X4Matrix& m)
{
    data.resize(16);
    rows=4;
    cols=4;
    (*this)=m;
}

CMatrix::CMatrix(const CMatrix& m)
{
    rows=m.rows;
    cols=m.cols;
    data.assign(m.data.begin(),m.data.end());
}
 
CMatrix::~CMatrix()
{
}

void CMatrix::resize(size_t nRows,size_t nCols,simReal def)
{ // old data is kept
    CMatrix a(nRows,nCols);
    for (size_t i=0;i<nRows*nCols;i++)
        a.data[i]=def;
    for (size_t i=0;i<rows;i++)
    {
        if (i<nRows)
        {
            for (size_t j=0;j<cols;j++)
            {
                if (j<nCols)
                    a(i,j)=(*this)(i,j);
            }
        }
    }
    data.assign(a.data.begin(),a.data.end());
    rows=nRows;
    cols=nCols;
}

void CMatrix::set(const CMatrix& m)
{
    data.assign(m.data.begin(),m.data.end());
    rows=m.rows;
    cols=m.cols;
}

void CMatrix::clear()
{
    for (size_t i=0;i<(cols*rows);i++)
        data[i]=0.0;
}

void CMatrix::setIdentity()
{
    for (size_t i=0;i<rows;i++)
    {
        for (size_t j=0;j<cols;j++)
        {
            if (i!=j)
                (*this)(i,j)=0.0;
            else
                (*this)(i,j)=1.0;
        }
    }
}

CMatrix CMatrix::operator* (const C3X3Matrix& m) const
{
    CMatrix retM(rows,3);
    for (size_t i=0;i<rows;i++)
    {
        for (size_t j=0;j<3;j++)
        {
            retM(i,j)=0.0;
            for (size_t k=0;k<3;k++)
                retM(i,j)+=( (*this)(i,k)*m.axis[j](k) );
        }
    }
    return(retM);
}

CMatrix CMatrix::operator* (const C4X4Matrix& m) const
{
    CMatrix retM(rows,4);
    for (size_t i=0;i<rows;i++)
    {
        for (size_t j=0;j<3;j++)
        {
            retM(i,j)=0.0;
            for (size_t k=0;k<3;k++)
                retM(i,j)+=( (*this)(i,k)*m.M.axis[j](k) );
        }
        retM(i,3)=(*this)(i,3);
        for (size_t k=0;k<3;k++)
            retM(i,3)+=( (*this)(i,k)*m.X(k) );
    }
    return(retM);
}

CMatrix CMatrix::operator* (const CMatrix& m) const
{
    CMatrix retM(rows,m.cols);
    for (size_t i=0;i<rows;i++)
    {
        for (size_t j=0;j<m.cols;j++)
        {
            retM(i,j)=0.0;
            for (size_t k=0;k<cols;k++)
                retM(i,j)+=( (*this)(i,k)*m(k,j) );
        }
    }
    return(retM);
}

CMatrix CMatrix::operator+ (const CMatrix& m) const
{
    CMatrix retM(rows,cols);
    for (size_t i=0;i<(rows*cols);i++)
        retM.data[i]=data[i]+m.data[i];
    return(retM);
}

CMatrix CMatrix::operator- (const CMatrix& m) const
{
    CMatrix retM(rows,cols);
    for (size_t i=0;i<(rows*cols);i++)
        retM.data[i]=data[i]-m.data[i];
    return(retM);
}

CMatrix CMatrix::operator* (simReal d) const
{
    CMatrix retM(rows,cols);
    for (size_t i=0;i<(rows*cols);i++)
        retM.data[i]=data[i]*d;
    return(retM);
}

CMatrix CMatrix::operator/ (simReal d) const
{
    CMatrix retM(rows,cols);
    for (size_t i=0;i<(rows*cols);i++)
        retM.data[i]=data[i]/d;
    return(retM);
}

void CMatrix::operator*= (const CMatrix& m)
{
    (*this)=(*this)*m;
}

void CMatrix::operator+= (const CMatrix& m)
{
    for (size_t i=0;i<(rows*cols);i++)
        data[i]+=m.data[i];
}

void CMatrix::operator-= (const CMatrix& m)
{
    for (size_t i=0;i<(rows*cols);i++)
        data[i]-=m.data[i];
}

void CMatrix::operator*= (simReal d)
{
    for (size_t i=0;i<(rows*cols);i++)
        data[i]*=d;
}

void CMatrix::operator/= (simReal d)
{
    for (size_t i=0;i<(rows*cols);i++)
        data[i]/=d;
}


CMatrix& CMatrix::operator= (const C3X3Matrix& m)
{
    for (size_t i=0;i<3;i++)
    {
        for (size_t j=0;j<3;j++)
            (*this)(i,j)=m.axis[j](i);
    }
    return(*this);
}

CMatrix& CMatrix::operator= (const C4X4Matrix& m)
{
    for (size_t i=0;i<3;i++)
    {
        for (size_t j=0;j<3;j++)
            (*this)(i,j)=m.M.axis[j](i);
        (*this)(i,3)=m.X(i);
    }
    (*this)(3,0)=0.0;
    (*this)(3,1)=0.0;
    (*this)(3,2)=0.0;
    (*this)(3,3)=1.0;
    return(*this);
}

CMatrix& CMatrix::operator= (const CMatrix& m)
{
    rows=m.rows;
    cols=m.cols;
    size_t t=rows*cols;
    data.resize(t);
    for (size_t i=0;i<t;i++)
        data[i]=m.data[i];
    return(*this);
}

void CMatrix::transpose()
{ // Write a faster routine later!  
    CMatrix n(cols,rows);
    for (size_t i=0;i<rows;i++)
    {
        for (size_t j=0;j<cols;j++)
            n(j,i)=(*this)(i,j);
    }
    rows=n.rows;
    cols=n.cols;
    (*this)=n;
}

bool CMatrix::inverse()
{
// Found the following routine on internet (numerical recipes) and modified it.
// Linear equation solution by Gauss-Jordan elimination:
    size_t irow=0;
    simReal big,dum,pivinv;
    size_t* indxc=new size_t[rows+1];
    size_t* indxr=new size_t[rows+1];
    size_t* ipiv=new size_t[rows+1];
    for (size_t j=1;j<=rows;j++)
        ipiv[j]=0;
    for (size_t i=1;i<=rows;i++)
    {
        size_t icol=0;
        bool icolSet=false;
        big=0.0;
        for (size_t j=1;j<=rows;j++)
        {
            if (ipiv[j]!=1)
            {
                for (size_t k=1;k<=rows;k++)
                {
                    if (ipiv[k]==0)
                    {
                        if (fabs((*this)(j-1,k-1))>=big)
                        {
                            big=fabs((*this)(j-1,k-1));
                            irow=j;
                            icol=k;
                            icolSet=true;
                        }
                    }
                    else if (ipiv[k]>1)
                    {   // The system cannot be solved
                        delete[] ipiv;
                        delete[] indxr;
                        delete[] indxc;
                        return(false);
                    }
                }
            }
        }
        if (!icolSet)
        { // There are probably nan numbers in the matrix!
            delete[] ipiv;
            delete[] indxr;
            delete[] indxc;
            return(false);
        }
        ++(ipiv[icol]);

        if (irow!=icol)
        {
            for (size_t l=1;l<=rows;l++)
            {
                simReal tmp=(*this)(irow-1,l-1);
                (*this)(irow-1,l-1)=(*this)(icol-1,l-1);
                (*this)(icol-1,l-1)=tmp;
            }
        }
        indxr[i]=irow;
        indxc[i]=icol;
        if ((*this)(icol-1,icol-1)==0.0)
        {   // The system cannot be solved
            delete[] ipiv;
            delete[] indxr;
            delete[] indxc;
            return(false);
        }
        pivinv=1.0/(*this)(icol-1,icol-1);
        (*this)(icol-1,icol-1)=1.0;
        for (size_t l=1;l<=rows;l++)
            (*this)(icol-1,l-1)*=pivinv;
        for (size_t ll=1;ll<=rows;ll++)
        {
            if (ll!=size_t(icol))
            {
                dum=(*this)(ll-1,size_t(icol-1));
                (*this)(ll-1,size_t(icol-1))=0.0;
                for (size_t l=1;l<=rows;l++)
                    (*this)(ll-1,l-1)-=(*this)(size_t(icol-1),l-1)*dum;
            }
        }
    }

    for (size_t l=rows;l>=1;l--)
    {
        if (indxr[l]!=indxc[l])
        {
            for (size_t k=1;k<=rows;k++)
            {
                simReal tmp=(*this)(k-1,indxr[l]-1);
                (*this)(k-1,indxr[l]-1)=(*this)(k-1,indxc[l]-1);
                (*this)(k-1,indxc[l]-1)=tmp;
            }
        }
    }
    delete[] ipiv;
    delete[] indxr;
    delete[] indxc;
    return(true);
}

simReal& CMatrix::operator() (size_t row,size_t col)
{
    return(data[row*cols+col]);
}

simReal CMatrix::getAt(size_t row,size_t col) const
{
    return(data[row*cols+col]);
}

void CMatrix::setAt(size_t row,size_t col,simReal value)
{
    data[row*cols+col]=value;
}

const simReal& CMatrix::operator() (size_t row,size_t col) const
{
    return(data[row*cols+col]);
}
