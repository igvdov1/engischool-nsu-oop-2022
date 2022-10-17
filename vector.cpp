
#include "vector.h"


Vector::Vector()
{
  V = new std::vector<double>;
  len = 0;

}

Vector::Vector(const int& a)
{
  V = new std::vector<double>(a);
  len = a;
}

Vector::Vector(const std::vector<double>& a)
{
  V = new std::vector<double>(a);
  len = std::size(a);
}



Vector Vector::operator+(const Vector& a) const
{
  std::vector<double> temp(len);
  unsigned int minlen = std::min(len, a.len);
  for (unsigned int i = 0; i < minlen; i++)
  {
    temp[i] = a[i] + (*this)[i];
  }
  for (unsigned int i = minlen; i < std::max(len, a.len); i++)
  {
    if (a.len == minlen)
    {
      temp[i] = (*this)[i];
    } else
    {
      temp[i] = a[i];
    }
  }
  return {temp};
}

Vector& Vector::operator+=(const Vector& a)
{
  *this = *this + a;
  return {*this};
}


Vector Vector::operator-(const Vector& a) const
{
  std::vector<double> temp(len);
  unsigned int minlen = std::min(len, a.len);
  for (unsigned int i = 0; i < minlen; i++)
  {
    temp[i] = (*this)[i] - a[i];
  }
  for (unsigned int i = minlen; i < std::max(len, a.len); i++)
  {
    if (a.len == minlen)
    {
      temp[i] = (*this)[i];
    } else
    {
      temp[i] = -a[i];
    }
  }
  return {temp};
}

Vector& Vector::operator-=(const Vector& a)
{
  *this = *this - a;
  return *this;
}


Vector Vector::operator*(const double& a) const
{
  std::vector<double> temp(len);
  for (unsigned int i = 0; i < len; i++)
  {
    temp[i] = (*this)[i] * a;
  }
  return {temp};
}

double Vector::operator*(const Vector& a) const
{
  double sum = 0;
  if (a.len == len)
  {
    for (unsigned int i = 0; i < len; i++)
    {
      sum += (*this)[i] * a[i];
    }
  }
  return sum;
}

Vector& Vector::operator*=(const double& a)
{
  *this = *this * a;
  return *this;
}

double& Vector::operator[](const unsigned int&a) const
{

  return (*V)[a];
}



Vector& Vector::operator=(const std::vector<double>& a)
{
  len = a.size();
  *V = a;
  return *this;
}


Vector& Vector::operator=(const Vector& a)
{
  len = a.len;
  V = new std::vector<double>(a.len);
  *V = *(a.V);
  return *this;
}


bool Vector::operator==(const Vector& a) const
{

  if (len != a.len)
  {
    return false;
  }
  for (unsigned int i = 0; i < len; i++)
  {
    if (a.V[i] != V[i])
    {
      return false;
    }
  }
  return true;
}

bool Vector::operator!=(const Vector& a) const
{
  return !(a == *this);
}


std::ostream& operator<<(std::ostream& out, Vector& a)
{
  for (unsigned int i = 0; i < a.len; i++)
  {
    out << a[i] << " ";
  }
  return out;
}

std::istream& operator>>(std::istream& in, Vector& a)
{
  in >> a.len;
  for (unsigned int i = 0; i < a.len; i++)
  {
    in >> a[i];
  }
  return in;
}

Vector::~Vector()
{
  delete &V;
  len = 0;
}

