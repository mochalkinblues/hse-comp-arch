//------------------------------------------------------------------------------
// diagonal_matrix.cpp - содержит функции диагональной матрицы
//------------------------------------------------------------------------------

#include "diagonal_matrix.h"

//--------------------------------------------
// Ввод элементов диагональной матрицы из потока
void DMatrix::In(std::ifstream &ifst) {
    ifst >> dimensionality;
    int size = dimensionality;

    for (int i = 0; i < size; ++i) {
        ifst >> elements[i];
    }
}

//------------------------------------------------------
// Случайный ввод элементов диагональной матрицы из потока
void DMatrix::InRnd() {
    dimensionality = Random();
    int size = dimensionality;

    for (int i = 0; i < size; ++i) {
        elements[i] = Random();
    }
}

//---------------------------------------------
// Вывод элементов диагональной матрицы из потока
void DMatrix::Out(std::ofstream &ofst) {
    int size = dimensionality;
    int col = 0;
    int row = 0;
    int curr = 0;
    ofst << "Diagonal matrix:\n"
         << "Dimensionality: " << dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean() << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        if (col == row) {
            ofst << elements[curr++] << " ";
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
double DMatrix::ArithmeticMean() {
    double size = dimensionality;
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += elements[i];
    }

    return sum / size;
}


