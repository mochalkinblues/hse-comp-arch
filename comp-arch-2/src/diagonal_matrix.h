#ifndef __DMatrix__
#define __DMatrix__
//------------------------------------------------------------------------------
// diagonal_matrix.h - содержит описание нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"
#include "matrix.h"

//------------------------------------------------------------------------------
// диагональная матрица

class DMatrix : public Matrix {
public:
    virtual void In(std::ifstream &ifst);
    virtual void InRnd();
    virtual void Out(std::ofstream &ofst);
    virtual double ArithmeticMean();
private:
    double elements[MAX_DIMENSIONALITY_SIZE]; // элементы на диагонали
};


#endif //__DMatrix__
