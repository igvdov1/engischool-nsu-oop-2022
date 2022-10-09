
#pragma once

#include <iostream>
#include <vector>


class Vector
{

public:
  Vector();
  explicit Vector(const int& a);
  Vector(const std::vector<double>& a);

  Vector operator+(const Vector& a) const;
  Vector operator+=(const Vector& a);

  Vector operator-(const Vector& a) const;
  Vector operator-=(const Vector& a);

  Vector operator*(const double& a) const;
  double operator*(const Vector& a) const;

  Vector operator*=(const double& a);
  double operator[](const unsigned int& a);

  Vector& operator=(const std::vector<double>& a);
  Vector& operator=(const Vector& a);

  bool operator==(const Vector& a) const;
  bool operator!=(const Vector& a) const;

  friend std::ostream& operator<<(std::ostream&, Vector& a);
  friend std::istream& operator>>(std::istream&, Vector& a);

private:
  std::vector<double> V;
  unsigned int len;
};
