#include "Complex.h"
#include "Vector.h"
#include "LessThan.h"
#include "RangeCheckVec.h"
#include <iostream>
#include <string>
using namespace std;

void rec_print() { cout << endl; }

template <typename T, typename... Tail>
void rec_print(T head, Tail... tail)
{
    cout << head << " ";
    rec_print(tail...);
}

int main()
{
    Complex c1{2, 1};
    Complex c2{3, 4};
    cout << "The complex conjugate of " << c1 << " is " << c1.conjugate() << "\n";
    cout << "The sum of " << c1 << " and " << c2 << " is " << (c1 + c2) << "\n";
    cout << "The division of " << c1 << " and " << c2 << " is " << (c1 / c2) << "\n";
    cout << "The abs of " << c1 << " is " << c1.abs() << "\n";

    double d[] = {1, 2, 3, 4};
    Vector<double> v1{d, 5};
    Vector<double> v2{1, 2, 3, 4, 5, 6};
    Vector<double> v3 = v2;
    Vector<double> v4 = v3 + v2;
    RangeCheckVec<string> v5{"The boom bap is coming back", " with an axe to mumble rap"};
    cout << "v1 is equal to " << v1 << endl;
    cout << "v2 is equal to " << v2 << endl;
    cout << "v3 is equal to " << v3 << endl;
    cout << "v4 = v2 + v3 is equal to " << v4 << endl;
    cout << "Number of values less than 3: " << count(v4, LessThan<float>{3}) << endl;
    cout << "Number of values less than 3: " << count(v4, [&](int i) { return i < 3; }) << endl; // [&x] capture only x by ref, [x] capture x and copy it, [&] captuire all local names by ref, [=] capture all local by value
    cout << "The recursive print of {1,2,3,Hola} is ";
    rec_print(1, 2, 3, "Hola");
    cout << "v5 is equal to [";
    for (auto &x : v5)
        cout << x << ",";
    cout << "]" << endl;
    try
    {
        v5[v5.size()];
    }
    catch (out_of_range)
    {
        cout << "Ooops, out of range mothafucka!\n";
    }
}