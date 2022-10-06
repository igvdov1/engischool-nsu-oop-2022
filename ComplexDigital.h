
#pragma once


class ComplexDigital
{

public:
  inline ComplexDigital();
  explicit ComplexDigital(double a);
  ComplexDigital(double a, double b);


  ComplexDigital operator+(const ComplexDigital& a) const;
  ComplexDigital operator+(const double& a) const;
  friend ComplexDigital operator+(const double& a, const ComplexDigital& b);


  ComplexDigital operator*(const ComplexDigital& a) const;
  ComplexDigital operator*(const double& a) const;
  friend ComplexDigital operator*(const double& a, const ComplexDigital& b);


  ComplexDigital operator-() const;
  ComplexDigital operator-(const ComplexDigital& a) const;
  ComplexDigital operator-(const double& a) const;
  friend ComplexDigital operator-(const double& a, const ComplexDigital& b);


  ComplexDigital operator/(const ComplexDigital& a) const;
  ComplexDigital operator/(const double& a) const;
  friend ComplexDigital operator/(const double& a, const ComplexDigital& b);


  ~ComplexDigital();


  bool operator==(const ComplexDigital& a) const;
  bool operator!=(const ComplexDigital& a) const;


  friend void ExponentialForm(const ComplexDigital& b);


  friend std::ostream& operator<<(std::ostream&, const ComplexDigital& a);
  friend std::istream& operator>>(std::istream&, ComplexDigital& a);


private:
  double re;
  double im;
};


