
#include <iostream>
#include <cmath>

#include "ComplexDigital.h"


ComplexDigital::ComplexDigital(double a, double b) : re(a), im(b) {}

ComplexDigital::ComplexDigital(double a) : re(a), im(0) {}

inline ComplexDigital::ComplexDigital() : re(0), im(0) {}


ComplexDigital ComplexDigital::operator+(const ComplexDigital &a) const
{
  return {a.re + this->re, a.im + this->im};
}

ComplexDigital ComplexDigital::operator+(const double &a) const
{
  return {this->re + a, this->im};
}

ComplexDigital operator+(const double &a, const ComplexDigital &b)
{
  return {a + b.re, b.im};
}


ComplexDigital ComplexDigital::operator*(const ComplexDigital &a) const
{
  return {a.re * this->re - a.im * this->im, a.re * this->im + a.im * this->re};
}

ComplexDigital ComplexDigital::operator*(const double &a) const
{
  return {this->re * a, a * this->im};
}

ComplexDigital operator*(const double &a, const ComplexDigital &b)
{
  return {b.re * a, b.im * a};
}


ComplexDigital ComplexDigital::operator-(const ComplexDigital &a) const
{
  return {*this * -1 + a};
}

ComplexDigital ComplexDigital::operator-(const double &a) const
{
  return {*this + a * -1};
}

ComplexDigital operator-(const double &a, const ComplexDigital &b)
{
  return {a + b * -1};
}


ComplexDigital ComplexDigital::operator/(const ComplexDigital &a) const
{
  return {(this->re * a.re + this->im * a.im) / (std::pow(a.re, 2) + std::pow(a.im, 2)),
          (this->im * a.re - this->re * a.im) / (std::pow(a.re, 2) + std::pow(a.im, 2))};
}

ComplexDigital ComplexDigital::operator/(const double &a) const
{
  return {this->re / a, this->im / a};
}

ComplexDigital operator/(const double &a, const ComplexDigital &b)
{
  return {a * (b.re) / (std::pow(b.re, 2) - std::pow(b.im, 2)),
          a * (b.im) / (std::pow(b.re, 2) - std::pow(b.im, 2))};
}


std::ostream &operator<<(std::ostream &out, const ComplexDigital &a)
{
  out << "(" << a.re << ", " << a.im << "*i)";
  return out;
}

std::istream &operator>>(std::istream &in, ComplexDigital &a)
{
  in >> a.re >> a.im;
  return in;
}


bool ComplexDigital::operator==(const ComplexDigital &a) const
{
  return a.re == this->re && a.im == this->im;
}

bool ComplexDigital::operator!=(const ComplexDigital &a) const
{
  return a.re != this->re || a.im != this->im;
}


void ExponentialForm(const ComplexDigital &a)
{
  double z = std::pow(std::pow(a.re, 2) + std::pow(a.im, 2), 0.5);
  double x = a.re / z;
  std::cout << z << "*e^(i*" << std::asin(x) << ")" << std::endl;
}


ComplexDigital::~ComplexDigital() = default;
