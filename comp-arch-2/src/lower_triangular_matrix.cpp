//------------------------------------------------------------------------------
// lower_triangular_matrix.cpp - содержит функции нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include "lower_triangular_matrix.h"

//--------------------------------------------
// Ввод элементов нижнетреугольной матрицы из потока
void LTMatrix::In(std::ifstream &ifst) {
    ifst >> dimensionality;
    int size = dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col <= row) {
            ifst >> elements[i];
        } else {
            elements[i] = 0;
        }

        ++col;
    }
}

//------------------------------------------------------
// Случайный ввод элементов нижнетреугольной матрицы из потока
void LTMatrix::InRnd() {
    dimensionality = Random();
    int size = dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col <= row) {
            elements[i] = Random();
        } else {
            elements[i] = 0;
        }

        ++col;
    }
}

//---------------------------------------------
// Вывод элементов нижнетреугольной матрицы из потока
void LTMatrix::Out(std::ofstream &ofst) {
    int size = dimensionality;
    int col = 0;
    ofst << "Lower triangular matrix:\n"
         << "Dimensionality: " << dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean() << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;

        ofst << elements[i] << " ";

        ++col;

        if (col == size) {
            ofst << "\n";
        }
    }
}

//--------------------------------------------
// Вычисление среднего арифметического нижнетреугольной матрицы
double LTMatrix::ArithmeticMean() {
    int size = dimensionality;
    int count = size * size;
    double sum = 0;
    int col = 0;

    for (int i = 0; i < size * size; ++i) {
        col = i % size;

        sum += elements[i];

        ++col;
    }

    return sum / count;
}
