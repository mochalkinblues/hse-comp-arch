//------------------------------------------------------------------------------
// diagonal_matrix.cpp - содержит функции диагональной матрицы
//------------------------------------------------------------------------------

#include "diagonal_matrix.h"

//--------------------------------------------
// Ввод элементов диагональной матрицы из потока
void In(DMatrix &d_matrix, std::ifstream &ifst) {
    ifst >> d_matrix.dimensionality;
    int size = d_matrix.dimensionality;

    for (int i = 0; i < size; ++i) {
        ifst >> d_matrix.elements[i];
    }
}

//------------------------------------------------------
// Случайный ввод элементов диагональной матрицы из потока
void InRnd(DMatrix &d_matrix) {
    d_matrix.dimensionality = Random();
    int size = d_matrix.dimensionality;

    for (int i = 0; i < size; ++i) {
        d_matrix.elements[i] = Random();
    }
}

//---------------------------------------------
// Вывод элементов диагональной матрицы из потока
void Out(DMatrix &d_matrix, std::ofstream &ofst) {
    int size = d_matrix.dimensionality;
    int col = 0;
    int row = 0;
    int curr = 0;
    ofst << "Diagonal matrix:\n"
         << "Dimensionality: " << d_matrix.dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean(d_matrix) << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col == row) {
            ofst << d_matrix.elements[curr++] << " ";
        } else {
            ofst << 0 << " ";
        }

        ++col;

        if (col == size) {
            ofst << "\n";
        }
    }
}

//--------------------------------------------
// Вычисление среднего арифметического диагональнойы матрицы
double ArithmeticMean(DMatrix &d_matrix) {
    int size = d_matrix.dimensionality;
    double sum = 0;
    for (int i = 0; i < size * size; ++i) {

        sum += d_matrix.elements[i];
    }

    return sum / size;
}
