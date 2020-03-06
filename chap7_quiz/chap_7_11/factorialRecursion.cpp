#include <iostream>

int factorial(int n)
{
  if (n == 0) return 1;
  return factorial(n-1)*n;
}

int main()
{
  for (int n = 0; n < 10; ++n)
    std::cout << factorial(n) << ' ';
  std::cout << '\n';
  return 0;
}
