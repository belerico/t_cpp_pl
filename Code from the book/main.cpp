#include "Complex.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    Complex c1{2, 1};
    Complex c2{3, 4};
    cout << "The complex conjugate of " << c1 << " is " << c1.conjugate() << "\n";
    cout << "The sum of " << c1 << " and " << c2 << " is " << (c1 + c2) << "\n";
    cout << "The division of " << c1 << " and " << c2 << " is " << (c1 / c2) << "\n";
    cout << "The abs of " << c1 << " is " << c1.abs() << "\n";

    double d[] = {1,2,3,4};
    Vector v1{d, 5};
    Vector v2{1,2,3,4,5,6};
    Vector v3 = v1;
    v3[0] = 10;
    cout << "v1 is equal to " << v1 << endl;
    cout << "v2 is equal to " << v2 << endl;
    cout << "v3 is equal to " << v3 << endl;
}