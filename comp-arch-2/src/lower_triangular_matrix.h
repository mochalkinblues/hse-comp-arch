#ifndef __LTMatrix__
#define __LTMatrix__
//------------------------------------------------------------------------------
// lower_triangular_matrix.h - содержит описание нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"
#include "matrix.h"

//------------------------------------------------------------------------------
// нижнетреугольная матрица

class LTMatrix : public Matrix {
public:
    virtual void In(std::ifstream &ifst);
    virtual void InRnd();
    virtual void Out(std::ofstream &ofst);
    virtual double ArithmeticMean();
private:
    double elements[MAX_DIMENSIONALITY_SIZE * MAX_DIMENSIONALITY_SIZE];
};


#endif //__LTMatrix__
