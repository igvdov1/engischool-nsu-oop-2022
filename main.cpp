#include <iostream>
#include "vector.h"
#include <vector>

int main()
{
  std::vector<double> a = {1, 2, 3};
  std::vector<double> b = {1, 4 ,5};
  Vector g(a);
  Vector f(b);
  std::cout << (g*f) << std::endl;
  Vector M(3);
  M = a;
  std::cout << M[2] << std::endl;
  Vector H(2);
  H = b;
  std::cout << M * H << std::endl;
  Vector I(6);
  I = M * 5;
  std::cout << I << std::endl;
  M -= H;
  if (M != H)
  {
    std::cout << "they are not equal" << std::endl;
  }
  M = H;
  std::cout << "Vector" << std::endl;
  std::cout << M << std::endl;
  M[1] = 15;
  std::cout << M << std::endl;
  if (M == H)
  {
    std::cout << "they are equal" << std::endl;
  }
  std::cout << M << std::endl;
  std::cout << H << std::endl;

  return 0;
}
