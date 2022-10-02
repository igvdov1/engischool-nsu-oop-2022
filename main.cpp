#include <iostream>
#include <cmath>
#include "ComplexDigital.h"

int main() {
    double a = 5;
    double d = 6;
    double i = 5;
    double k = 5;
    ComplexDigital z(a, k);
    ComplexDigital p(d);
    ComplexDigital t = z - i;
    ComplexDigital g = t + p;

    if(t != p){
        std::cout << z << std::endl;
    }
    std::cout << t << std::endl;
    std::cout << g << std::endl;
    std::cout << z * g << std::endl;
}
