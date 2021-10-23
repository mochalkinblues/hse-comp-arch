//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void container::Init() {
    len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void container::Clear() {
    for (int i = 0; i < len; ++i) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void container::In(std::ifstream &ifst) {
    while(!ifst.eof()) {
        Matrix *mx = Matrix::StaticIn(ifst);
        if (mx != nullptr) {
            this->cont[len] = mx;
            ++len;
        } else {
            break;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void container::InRnd(int size) {
    while (len < size) {
        cont[len] = Matrix::StaticInRnd();
        ++len;
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; ++i) {
        ofst << i << ": ";
        cont[i]->Out(ofst);
        ofst << "\n";
    }
}


//------------------------------------------------------------------------------
// Метод, меняющий местами элементы
void container::swap(int left, int right) {
    auto temp = cont[left];
    cont[left] = cont[right];
    cont[right] = temp;
}

//------------------------------------------------------------------------------
// Реализация Quick Sort
void container::QuickSort(int left, int right) {
    int i = left;
    int j = right;
    auto pivot = cont[(i + j) / 2]->ArithmeticMean();

    while (i <= j) {
        while (cont[i]->ArithmeticMean() > pivot) {
            ++i;
        }
        while(cont[j]->ArithmeticMean() < pivot) {
            j--;
        }

        if (i <= j) {
            swap(i, j);
            ++i;
            --j;
        }

        if (j > left) {
            QuickSort(left, j);
        }

        if (i < right) {
            QuickSort(i, right);
        }
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию с помощью разделения
void container::Sort() {
    QuickSort(0, len - 1);
}
