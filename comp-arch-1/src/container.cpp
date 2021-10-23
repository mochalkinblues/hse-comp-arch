//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; ++i) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        c.cont[c.len] = In(ifst);
        ++c.len;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while (c.len < size) {
        c.cont[c.len] = InRnd();
        ++c.len;
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements.\n";
    for (int i = 0; i < c.len; ++i) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
        ofst << "\n";
    }
}


//------------------------------------------------------------------------------
// Метод, меняющий местами элементы
void swap(container &c, int left, int right) {
    Matrix temp = *c.cont[left];
    *c.cont[left] = *c.cont[right];
    *c.cont[right] = temp;
}

//------------------------------------------------------------------------------
// Реализация Quick Sort
void QuickSort(container &c, int left, int right) {
    int i = left;
    int j = right;
    auto pivot = ArithmeticMean(*c.cont[(i + j) / 2]);

    while (i <= j) {
        while (ArithmeticMean(*c.cont[i]) > pivot) {
            ++i;
        }
        while(ArithmeticMean(*c.cont[j]) < pivot) {
            j--;
        }

        if (i <= j) {
            swap(c, i, j);
            ++i;
            --j;
        }

        if (j > left) {
            QuickSort(c, left, j);
        }

        if (i < right) {
            QuickSort(c, i, right);
        }
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию с помощью разделения
void Sort(container &c) {
    QuickSort(c, 0, c.len - 1);
}
