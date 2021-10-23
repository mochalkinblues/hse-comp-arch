#ifndef __TDArray__
#define __TDArray__

//------------------------------------------------------------------------------
// two_dimensional_array.h - содержит описание обычного двумерного массива
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"
#include "matrix.h"

//------------------------------------------------------------------------------
// двумерный массив
class TDArray : public Matrix {
public:
    virtual void In(std::ifstream &ifst);
    virtual void InRnd();
    virtual void Out(std::ofstream &ofst);
    virtual double ArithmeticMean();
private:
    double elements[MAX_DIMENSIONALITY_SIZE][MAX_DIMENSIONALITY_SIZE]; // элементы
};

#endif //__TDArray__
