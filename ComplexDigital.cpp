
#include <iostream>
#include <cmath>

#include "ComplexDigital.h"


ComplexDigital::ComplexDigital(double a, double b) : re(a), im(b) {}
ComplexDigital::ComplexDigital(double a) : re(a), im(0) {}
ComplexDigital::ComplexDigital() : re(0), im(0) {}


ComplexDigital ComplexDigital::operator+(const ComplexDigital& a) const
{
  return {a.re + re, a.im + im};
}

ComplexDigital ComplexDigital::operator+(const double& a) const
{
  return {re + a, im};
}

ComplexDigital operator+(const double& a, const ComplexDigital& b)
{
  return {a + b.re, b.im};
}


ComplexDigital ComplexDigital::operator*(const ComplexDigital& a) const
{
  return {a.re * re - a.im * im, a.re * im + re};
}

ComplexDigital ComplexDigital::operator*(const double& a) const
{
  return {re * a, a * im};
}

ComplexDigital operator*(const double& a, const ComplexDigital& b)
{
  return {b.re * a, b.im * a};
}


ComplexDigital ComplexDigital::operator-() const
{
  return {-re, -im};
}


ComplexDigital ComplexDigital::operator-(const ComplexDigital& a) const
{
  return {-*this + a};
}

ComplexDigital ComplexDigital::operator-(const double& a) const
{
  return {*this + -a };
}

ComplexDigital operator-(const double& a, const ComplexDigital& b)
{
  return {a + -b};
}


ComplexDigital ComplexDigital::operator/(const ComplexDigital& a) const
{
  double temp = (std::pow(a.re, 2) + std::pow(a.im, 2));
  return {(re * a.re + im * a.im) / temp,
          (im * a.re - re * a.im) / temp};
}

ComplexDigital ComplexDigital::operator/(const double& a) const
{
  return {re / a, im / a};
}

ComplexDigital operator/(const double& a, const ComplexDigital& b)
{
  double temp =  (std::pow(b.re, 2) + std::pow(b.im, 2));
  return {a * b.re / temp,
          a * -b.im / temp};
}


std::ostream& operator<<(std::ostream& out, const ComplexDigital& a)
{
  out << "(" << a.re << ", " << a.im << "*i)";
  return out;
}

std::istream& operator>>(std::istream& in, ComplexDigital& a)
{
  in >> a.re >> a.im;
  return in;
}


bool ComplexDigital::operator==(const ComplexDigital& a) const
{
  return a.re == re && a.im == im;
}

bool ComplexDigital::operator!=(const ComplexDigital& a) const
{
  return !(a == *this);
}


void ExponentialForm(const ComplexDigital& a)
{
  double z = std::pow(std::pow(a.re, 2) + std::pow(a.im, 2), 0.5);
  double x = a.im / z;
  std::cout << z << "*e^(i*" << std::asin(x) << ")" << std::endl;
}

ComplexDigital::~ComplexDigital() = default;
