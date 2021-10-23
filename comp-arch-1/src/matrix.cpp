//------------------------------------------------------------------------------
// matrix.cpp - содержит процедуры связанные с обработкой обобщенной матрицы
// и создания произвольной матрицы
//------------------------------------------------------------------------------

#include "matrix.h"

Matrix* In(std::ifstream &ifst) {
    Matrix *mx;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            mx = new Matrix;
            mx->k = Matrix::TDARRAY;
            In(mx->td_array, ifst);
            return mx;
        case 2:
            mx = new Matrix;
            mx->k = Matrix::LTMATRIX;
            In(mx->lt_matrix, ifst);
            return mx;
        case 3:
            mx = new Matrix;
            mx->k = Matrix::DMATRIX;
            In(mx->d_matrix, ifst);
            return mx;
        default:
            mx = new Matrix;
            mx->k = Matrix::INVALID_MATRIX_TYPE;
            char tmp[MAX_DIMENSIONALITY_SIZE];
            ifst >> tmp >> tmp;
            return mx;
    }
}

// Случайный ввод обобщенной фигуры
Matrix *InRnd() {
    Matrix *mx;
    int k = Random() % 3;
    switch(k) {
        case 1:
            mx = new Matrix;
            mx->k = Matrix::TDARRAY;
            InRnd(mx->td_array);
            return mx;
        case 2:
            mx = new Matrix;
            mx->k = Matrix::LTMATRIX;
            InRnd(mx->lt_matrix);
            return mx;
        case 3:
            mx = new Matrix;
            mx->k = Matrix::DMATRIX;
            InRnd(mx->d_matrix);
            return mx;
        default:
            mx = new Matrix;
            mx->k = Matrix::INVALID_MATRIX_TYPE;
            return mx;
    }
}

//------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(Matrix &mx, std::ofstream &ofst) {
    switch(mx.k) {
        case Matrix::TDARRAY:
            Out(mx.td_array, ofst);
            break;
        case Matrix::LTMATRIX:
            Out(mx.lt_matrix, ofst);
            break;
        case Matrix::DMATRIX:
            Out(mx.d_matrix, ofst);
            break;
        default:
            ofst << "Invalid matrix type!\n";
    }
}

//---------------------------------------------------
// Вычисление частного от деления числа гласных букв
// в названии растения на общую длину его названия
double ArithmeticMean(Matrix &mx) {
    switch(mx.k) {
        case Matrix::TDARRAY:
            return ArithmeticMean(mx.td_array);
        case Matrix::LTMATRIX:
            return ArithmeticMean(mx.lt_matrix);
        case Matrix::DMATRIX:
            return ArithmeticMean(mx.d_matrix);
        default:
            return 0.0;
    }
}
