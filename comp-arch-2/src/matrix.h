#ifndef __matrix__
#define __matrix__
#include <fstream>

class Matrix {
public:
    int dimensionality;
    virtual ~Matrix() {};
    static Matrix *StaticIn(std::ifstream &ifst);
    virtual void In(std::ifstream &ifst) = 0;
    static Matrix *StaticInRnd();
    virtual void InRnd() = 0;
    virtual void Out(std::ofstream &ofst) = 0;
    virtual double ArithmeticMean() = 0;
};


#endif //__matrix__
