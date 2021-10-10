//------------------------------------------------------------------------------
// lower_triangular_matrix.cpp - содержит функции нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include "lower_triangular_matrix.h"

//--------------------------------------------
// Ввод элементов нижнетреугольной матрицы из потока
void In(LTMatrix &lt_matrix, std::ifstream &ifst) {
    ifst >> lt_matrix.dimensionality;
    int size = lt_matrix.dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col <= row) {
            ifst >> lt_matrix.elements[i];
        } else {
            lt_matrix.elements[i] = 0;
        }

        ++col;
    }
}

//------------------------------------------------------
// Случайный ввод элементов нижнетреугольной матрицы из потока
void InRnd(LTMatrix &lt_matrix) {
    lt_matrix.dimensionality = Random();
    int size = lt_matrix.dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col <= row) {
            lt_matrix.elements[i] = Random();
        } else {
            lt_matrix.elements[i] = 0;
        }

        ++col;
    }
}

//---------------------------------------------
// Вывод элементов нижнетреугольной матрицы из потока
void Out(LTMatrix &lt_matrix, std::ofstream &ofst) {
    int size = lt_matrix.dimensionality;
    int col = 0;
    ofst << "Lower triangular matrix:\n"
         << "Dimensionality: " << lt_matrix.dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean(lt_matrix) << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;

        ofst << lt_matrix.elements[i] << " ";

        ++col;

        if (col == size) {
            ofst << "\n";
        }
    }
}

//--------------------------------------------
// Вычисление среднего арифметического нижнетреугольной матрицы
double ArithmeticMean(LTMatrix &lt_matrix) {
    int size = lt_matrix.dimensionality;
    int count = size * size;
    double sum = 0;
    int col = 0;

    for (int i = 0; i < size * size; ++i) {
        col = i % size;

        sum += lt_matrix.elements[i];

        ++col;
    }

    return sum / count;
}
