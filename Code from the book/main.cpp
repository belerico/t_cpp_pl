#include "Complex.h"
#include <iostream>

int main()
{
    Complex c1{2, 1};
    Complex c2{3, 4};
    std::cout << "The complex conjugate of " << c1 << " is " << c1.conjugate() << "\n";
    std::cout << "The sum of " << c1 << " and " << c2 << " is " << (c1 + c2) << "\n";
    std::cout << "The division of " << c1 << " and " << c2 << " is " << (c1 / c2) << "\n";
    std::cout << "The abs of " << c1 << " is " << c1.abs() << "\n";
}