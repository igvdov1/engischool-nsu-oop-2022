#include <iostream>
#include "ComplexDigital.h"

int main()
{
  double a = 5, d = 6;
  ComplexDigital z(a, a);
  ComplexDigital p(d);
  ComplexDigital t = z - a;
  ComplexDigital g = t + p;

  if (t != p)
  {
    std::cout << "They are not equal" << std::endl;
  }
  if (t == p)
  {
    std::cout<<"They are equal" << std::endl;
  }
  std::cout << z * g<< std::endl;

  std::cout << z / g << std::endl;
  std::cout << z + g << std::endl;
  std::cout << t << std::endl;
  ExponentialForm(t);
  return 0;
}
