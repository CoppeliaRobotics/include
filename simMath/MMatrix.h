#pragma once

#include "mathDefines.h"
#include "3X3Matrix.h"
#include "4X4Matrix.h"
#include <vector>

class CMatrix  
{
public:
    CMatrix();
    CMatrix(size_t nRows,size_t nCols);
    CMatrix(const C3X3Matrix& m);
    CMatrix(const C4X4Matrix& m);
    CMatrix(const CMatrix& m);
    ~CMatrix();

    void resize(size_t nRows,size_t nCols,simReal def);
    void set(const CMatrix& m);
    bool inverse();
    void transpose();
    void clear();
    void setIdentity();
    simReal getAt(size_t row,size_t col) const;
    void setAt(size_t row,size_t col,simReal value);

    simReal& operator() (size_t row,size_t col);
    const simReal& operator() (size_t row,size_t col) const;

    void operator*= (const CMatrix& m);
    void operator*= (simReal d);
    void operator/= (simReal d);
    void operator+= (const CMatrix& m);
    void operator-= (const CMatrix& m);

    CMatrix& operator= (const C3X3Matrix& m);
    CMatrix& operator= (const C4X4Matrix& m);
    CMatrix& operator= (const CMatrix& m);
    CMatrix operator* (const C3X3Matrix& m) const;
    CMatrix operator* (const C4X4Matrix& m) const;
    CMatrix operator* (const CMatrix& m) const;
    CMatrix operator* (simReal d) const;
    CMatrix operator/ (simReal d) const;
    CMatrix operator+ (const CMatrix& m) const;
    CMatrix operator- (const CMatrix& m) const;

    size_t rows,cols;
    std::vector<simReal> data;
};


