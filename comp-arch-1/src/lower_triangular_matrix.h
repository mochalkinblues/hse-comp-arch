#ifndef __LTMatrix__
#define __LTMatrix__
//------------------------------------------------------------------------------
// lower_triangular_matrix.h - содержит описание нижнетреугольной матрицы
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "constant.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// нижнетреугольная матрица

struct LTMatrix {
    int dimensionality; // размерность матрицы
    double elements[MAX_DIMENSIONALITY_SIZE * MAX_DIMENSIONALITY_SIZE];
};

// Ввод нижнетреугольной матрицы из файла
void In(LTMatrix &lt_matrix, std::ifstream &ifst);

// Случайный ввод нижнетреугольной матрицы
void InRnd(LTMatrix &lt_matrix);

// Вывод нижнетреугольной матрицы в форматируемый поток
void Out(LTMatrix &lt_matrix, std::ofstream &ofst);

// Вычисление средного арифиметического нижнетреугольной матрицы
double ArithmeticMean(LTMatrix &lt_matrix);

#endif //__LTMatrix__
