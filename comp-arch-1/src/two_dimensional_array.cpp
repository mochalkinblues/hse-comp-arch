//------------------------------------------------------------------------------
// two_dimensional_array.cpp - содержит функции обработки двумерного массива
//------------------------------------------------------------------------------

#include "two_dimensional_array.h"

//--------------------------------------------
// Ввод элементов двумерного массива из потока
void In(TDArray &td_array, std::ifstream &ifst) {
    ifst >> td_array.dimensionality;
    int size = td_array.dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        ifst >> td_array.elements[row][col];

        ++col;
    }
}

//------------------------------------------------------
// Случайный ввод элементов двумерного массива из потока
void InRnd(TDArray &td_array) {
    td_array.dimensionality = Random();
    int size = td_array.dimensionality;
    int col = 0;
    int row = 0;
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        td_array.elements[row][col] = Random();

        ++col;
    }
}

//---------------------------------------------
// Вывод элементов двумерного массива из потока
void Out(TDArray &td_array, std::ofstream &ofst) {
    int size = td_array.dimensionality;
    int col = 0;
    int row = 0;
    ofst << "Two dimensional array:\n"
         << "Dimensionality: " << td_array.dimensionality << "\n"
         << "Arithmetic mean: " << ArithmeticMean(td_array) << "\n"
         << "Elements: \n";
    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        ofst << td_array.elements[row][col] << " ";

        ++col;

        if (col == size) {
            ofst << "\n";
        }
    }
}

//--------------------------------------------
// Вычисление среднего арифметического массива
double ArithmeticMean(TDArray &td_array) {
    int size = td_array.dimensionality;
    int count = size * size;
    double sum = 0;
    int col = 0;
    int row = 0;

    for (int i = 0; i < size * size; ++i) {
        col = i % size;
        row = i / size;

        sum += td_array.elements[row][col];

        ++col;
    }

    return sum / count;
}
