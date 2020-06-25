#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(int s)
{
    if (s < 0)
        throw length_error{"Vector size must be a non negative number"};
    elem = new double[s];
    sz = s;
}

Vector::Vector(double *d, int s)
{
    if (s < 0)
        throw length_error{"Vector size must be a non negative number"};
    elem = new double[s];
    sz = s;
    for (int i = 0; i < s; ++i)
        elem[i] = d[i];
}

Vector::Vector(initializer_list<double> lst)
{
    elem = new double[lst.size()];
    sz = static_cast<int>(lst.size());
    copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(const Vector &v) : elem{new double[v.sz]}, sz{v.sz}
{
    for (int i = 0; i < sz; ++i)
        elem[i] = v.elem[i];
}

Vector::~Vector()
{
    delete[] elem;
}

// Vector read(istream &is)
// {
//     Vector v{};
//     for (double d; is >> d;)
//         v.push_back(d);
//     return v;
// }

double &Vector::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Index out of range"};
    return elem[i];
}

Vector &Vector::operator=(const Vector &v)
{
    double *p = new double[v.sz];
    for (int i = 0; i < v.sz; ++i)
        p[i] = v.elem[i];
    delete[] elem;
    elem = p;
    sz = v.sz;
    return *this;
}

int Vector::size() const
{
    return sz;
}

ostream &operator<<(ostream &strm, Vector &v)
{
    strm << '[';
    for (int i = 0; i < v.size(); ++i)
        strm << v[i] << ", ";
    strm << ']';
    return strm;
}
