#ifndef __TDArray__
#define __TDArray__

//------------------------------------------------------------------------------
// two_dimensional_array.h - содержит описание обычного двумерного массива
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// двумерный массив
struct TDArray {
    int dimensionality; // размерность массива
    double elements[MAX_DIMENSIONALITY_SIZE][MAX_DIMENSIONALITY_SIZE]; // элементы
};

// Ввод двумерного массива из файла
void In(TDArray &td_array, std::ifstream &ifst);

// Случайный ввод двумерного массива
void InRnd(TDArray &td_array);

// Вывод двумерного массива в форматируемый поток
void Out(TDArray &td_array, std::ofstream &ofst);

// Вычисление среднего арифметического двумерного массива
double ArithmeticMean(TDArray &td_array);

#endif //__TDArray__
