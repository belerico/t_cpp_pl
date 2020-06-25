#include <iostream>

class Complex
{
private:
    double re, im;

public:
    Complex(double r, double i);
    Complex(double r);
    Complex();

    double real() const;
    void real(double r);
    double imag() const;
    void imag(double i);
    Complex conjugate();
    double abs();

    Complex &operator+=(Complex z);
    Complex &operator-=(Complex z);
    Complex &operator*=(Complex z);
    Complex &operator/=(Complex z);

    friend Complex operator+(Complex v, Complex u);
    friend Complex operator-(Complex v, Complex u);
    friend Complex operator-(Complex v);
    friend Complex operator*(Complex v, Complex u);
    friend Complex operator/(Complex v, Complex u);
    friend std::ostream &operator<<(std::ostream &strm, const Complex &c);
};