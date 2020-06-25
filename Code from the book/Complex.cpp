#include <iostream>
#include <math.h>
#include "Complex.h"
using namespace std;

Complex::Complex(double r, double i) : re{r}, im{i} {}
Complex::Complex(double r) : re{r}, im{0} {}
Complex::Complex() : re{0}, im{0} {}

double Complex::real() const { return re; }
void Complex::real(double r) { re = r; }
double Complex::imag() const { return im; }
void Complex::imag(double i) { im = i; }
Complex Complex::conjugate() { return Complex(re, -im); }
double Complex::abs() { return sqrt(pow(re, 2) + pow(im, 2)); }

Complex &Complex::operator+=(Complex z)
{
    re += z.re;
    im += z.im;
    return *this;
}

Complex &Complex::operator-=(Complex z)
{
    re -= z.re;
    im -= z.im;
    return *this;
}

Complex &Complex::operator*=(Complex z)
{
    re = re * z.re - im * z.im;
    im = re + z.im + im * z.re;
    return *this;
}

Complex &Complex::operator/=(Complex z)
{
    double denom = pow(z.real(), 2) + pow(z.imag(), 2);
    double re_div = (re * z.real() + im * z.imag()) / denom;
    double im_div = (im * z.real() - re * z.imag()) / denom;
    re = re_div;
    im = im_div;
    return *this;
}

Complex operator+(Complex v, Complex u) { return v += u; }
Complex operator-(Complex v, Complex u) { return v -= u; }
Complex operator-(Complex v) { return {-v.real(), -v.imag()}; }
Complex operator*(Complex v, Complex u) { return v *= u; }
Complex operator/(Complex v, Complex u) { return v /= u; }
ostream &operator<<(ostream &strm, const Complex &c)
{
    return strm << c.re << " + " << c.im << "i";
}