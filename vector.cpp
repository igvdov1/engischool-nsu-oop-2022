
#include "vector.h"


Vector::Vector()
{
  V = nullptr;
  len = 0;

}

Vector::Vector(const int& a)
{
  V = new std::vector <double>(a);
  len = a;
}

Vector::Vector(const std::vector<double>& a)
{
  V = new std::vector <double>(a);
  len = std::size(a);
}

Vector Vector::operator+(const Vector& a) const
{
  std::vector<double> temp(len);
  if (a.len == len)
  {
    for (unsigned int i = 0; i < len; i++)
    {
      temp[i] = (*a.V)[i] + (*V)[i];
    }
  }
  return {temp};
}

Vector& Vector::operator+=(const Vector& a)
{
  for(unsigned int i = 0; i < len; i++)
  {
    (*V)[i] += (*a.V)[i];
  }
  return *this;
}


Vector Vector::operator-(const Vector& a) const
{
  std::vector<double> temp(len);
  if (a.len == len)
  {
    for (unsigned int i = 0; i < len; i++)
    {
      temp[i] = (*V)[i] - (*a.V)[i];
    }
  }
  return {temp};
}

Vector& Vector::operator-=(const Vector& a)
{
  for(unsigned int i = 0; i < len; i++)
  {
    (*V)[i] -= (*a.V)[i];
  }
  return *this;
}


Vector Vector::operator*(const double& a) const
{
  std::vector<double> temp(len);
  for (unsigned int i = 0; i < len; i++)
  {
    temp[i] = (*V)[i] * a;
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
      sum += (*V)[i] * (*a.V)[i];
    }
  }
  return sum;
}

Vector& Vector::operator*=(const double& a)
{
  for(unsigned int i = 0; i < len; i++)
  {
    (*V)[i] *= a;
  }
  return *this;
}


double& Vector::operator[](const unsigned int& a)
{

  return (*V)[a];
}


Vector& Vector::operator=(const std::vector<double>& a)
{
  len = a.size();
  *V = a;
  return *this;
}


Vector& Vector::operator=(const Vector& a) = default;


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
    in >> (*a.V)[i];
  }
  return in;
}

Vector::~Vector()
{
  delete [] V;
  len = 0;
}
