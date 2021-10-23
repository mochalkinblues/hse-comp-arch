#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "matrix.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class container {
public:
    void Init();
    void In(std::ifstream &ifst);
    void InRnd(int size);
    void Out(std::ofstream &ofst);
    void Sort();
    void Clear();
private:
    void QuickSort(int left, int right);
    void swap(int left, int right);
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    Matrix *cont[max_len];
};


#endif //__container__

