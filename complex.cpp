#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

Complex::Complex(double _re, double _im)
{
	re = _re;
	im = _im;
}

Complex::Complex(double _re)
{
	re = _re;
	im = 0;
}

Complex::Complex()
{
	re = 0;
	im = 0;
}

double Complex::Re() const
{
	return re;
}

double Complex::Im() const
{
	return im;
}

double Complex::R() const
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

ostream& operator<<(ostream& out, const Complex& ex)
{
	out << "(" << ex.re << ", " << ex.im << ")";
	return out;
}

istream& operator>>(istream& in, Complex& ex)
{
	in >> ex.re >> ex.im;
	return in;
}

Complex Complex::operator+(Complex& ex)
{
	return Complex(re + ex.Re(), im + ex.Im());
}

Complex Complex::operator+(const int& ex) const
{
	return Complex(re + ex, im / ex);
}

Complex Complex::operator+=(Complex& ex)
{
	re += ex.Re();
	im += ex.Im();

	return *this;
}

Complex Complex::operator-(Complex& ex)
{
	return Complex(re - ex.Re(), im - ex.Im());
}

Complex Complex::operator-=(Complex& ex)
{
	re -= ex.Re();
	im -= ex.Im();

	return *this;
}

Complex Complex::operator*(Complex& ex)
{
	return Complex(re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re());
}

Complex Complex::operator*(const int& ex)
{
	return Complex(re * ex, im * ex);
}

Complex Complex::operator*=(Complex& ex)
{
	double _re = re;

	re = re * ex.Re() - im * ex.Im();
	im = _re * ex.Im() + im * ex.Re();

	return *this;
}

Complex Complex::operator/(Complex& ex)
{
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	return Complex((re * ex.Re() + im * ex.Im()) / r, (im * ex.Re() - re * ex.Im()) / r);
}

Complex Complex::operator/(const int& ex) const
{
	return Complex(re / ex, im / ex);
}

Complex Complex::operator/=(Complex& ex)
{
	double _re = re;
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	re = (re * ex.Re() + im * ex.Im()) / r;
	im = (im * ex.Re() - _re * ex.Im()) / r;

	return *this;
}

Complex Complex::operator-() const
{
	return Complex(-re, -im);
}

Complex exp(const Complex& z)
{
	return Complex(std::exp(z.Re()) * cos(z.Im()), std::exp(z.Re()) * sin(z.Im()));
}

Complex cosh(const Complex& z)
{
	return ((exp(z) + exp(-z)) / 2);
}

Complex sinh(const Complex& z)
{
	return ((exp(z) - exp(-z)) / 2);
}
