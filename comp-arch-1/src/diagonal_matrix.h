#ifndef __DMatrix__
#define __DMatrix__
//------------------------------------------------------------------------------
// diagonal_matrix.h - содержит описание нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// диагональная матрица

struct DMatrix {
    int dimensionality; // размерность матрицы
    double elements[MAX_DIMENSIONALITY_SIZE]; // элементы на диагонали
};

// Ввод диагональной матрицы из файла
void In(DMatrix &d_matrix, std::ifstream &ifst);

// Случайный ввод диагональной матрицы
void InRnd(DMatrix &d_matrix);

// Вывод диагональной матрицы в форматируемый поток
void Out(DMatrix &d_matrix, std::ofstream &ofst);

// Вычисление средного арифиметического диагональной матрицы
double ArithmeticMean(DMatrix &d_matrix);

#endif //__DMatrix__
