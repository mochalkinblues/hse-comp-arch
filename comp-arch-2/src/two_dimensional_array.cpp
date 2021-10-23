//------------------------------------------------------------------------------
// two_dimensional_array.cpp - содержит функции обработки двумерного массива
//------------------------------------------------------------------------------

#include "two_dimensional_array.h"

//--------------------------------------------
// Ввод элементов двумерного массива из потока
void TDArray::In(std::ifstream &ifst) {
    ifst >> this->dimensionality;
    int size = dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        ifst >> elements[row][col];

        ++col;
    }
}

//------------------------------------------------------
// Случайный ввод элементов двумерного массива из потока
void TDArray::InRnd() {
    dimensionality = Random();
    int size = dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        elements[row][col] = Random();

        ++col;
    }
}

//---------------------------------------------
// Вывод элементов двумерного массива из потока
void TDArray::Out(std::ofstream &ofst) {
    int size = dimensionality;
    int col = 0;
    int row = 0;
    ofst << "Two dimensional array:\n"
         << "Dimensionality: " << dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean() << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        ofst << elements[row][col] << " ";

        ++col;

        if (col == size) {
            ofst << "\n";
        }
    }
}

//--------------------------------------------
// Вычисление среднего арифметического массива
double TDArray::ArithmeticMean() {
    int size = dimensionality;
    int count = size * size;
    double sum = 0;
    int col = 0;
    int row = 0;

    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        sum += elements[row][col];

        ++col;
    }

    return sum / count;
}
