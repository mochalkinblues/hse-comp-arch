//------------------------------------------------------------------------------
// matrix.cpp - содержит процедуры связанные с обработкой обобщенной матрицы
// и создания произвольной матрицы
//------------------------------------------------------------------------------

#include "matrix.h"
#include "two_dimensional_array.h"
#include "diagonal_matrix.h"
#include "lower_triangular_matrix.h"

Matrix* Matrix::StaticIn(std::ifstream &ifst) {
    Matrix *mx = nullptr;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            mx = new TDArray;
            break;
        case 2:
            mx = new LTMatrix;
            break;
        case 3:
            mx = new DMatrix;
            break;
    }
    mx->In(ifst);

    return mx;
}

// Случайный ввод обобщенной фигуры
Matrix *Matrix::StaticInRnd() {
    Matrix *mx;
    int k = Random() % 3;
    switch(k) {
        case 1:
            mx = new TDArray;
            return mx;
        case 2:
            mx = new LTMatrix;
            return mx;
        case 3:
            mx = new DMatrix;
            return mx;
    }
}

