#include <math.h>
#include <iostream>

class Complex
{
public:
    Complex(double r, double i) : re{r}, im{i} {}
    Complex(double r) : re{r}, im{0} {}
    Complex() : re{0}, im{0} {}

    double real() const { return re; }
    void real(double r) { re = r; }
    double imag() const { return im; }
    void imag(double i) { im = i; }
    Complex conjugate() { return Complex(re, -im); }
    double abs() { return sqrt(pow(re, 2) + pow(im, 2)); }

    Complex &operator+=(Complex z)
    {
        re += z.re;
        im += z.im;
        return *this;
    }

    Complex &operator-=(Complex z)
    {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    Complex &operator*=(Complex z)
    {
        re = re * z.re - im * z.im;
        im = re + z.im + im * z.re;
        return *this;
    }

    Complex &operator/=(Complex z)
    {
        double denom = pow(z.real(), 2) + pow(z.imag(), 2);
        double re_div = (re * z.real() + im * z.imag()) / denom;
        double im_div = (im * z.real() - re * z.imag()) / denom;
        re = re_div;
        im = im_div;
        return *this;
    }

private:
    double re, im;
};

Complex operator+(Complex v, Complex u) { return v += u; }
Complex operator-(Complex v, Complex u) { return v -= u; }
Complex operator-(Complex v) { return {-v.real(), -v.imag()}; }
Complex operator*(Complex v, Complex u) { return v *= u; }
Complex operator/(Complex v, Complex u) { return v /= u; }

std::ostream &operator<<(std::ostream &strm, const Complex &c)
{
    return strm << c.real() << " + " << c.imag() << "i";
}

int main()
{
    Complex c1{2, 1};
    Complex c2{3, 4};
    std::cout << "The complex conjugate of " << c1 << " is " << c1.conjugate() << "\n";
    std::cout << "The sum of " << c1 << " and " << c2 << " is " << (c1 + c2) << "\n";
    std::cout << "The division of " << c1 << " and " << c2 << " is " << (c1 / c2) << "\n";
    std::cout << "The abs of " << c1 << " is " << c1.abs() << "\n";
}