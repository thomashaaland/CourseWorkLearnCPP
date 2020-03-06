#include <iostream>

int fiboSum(int n)
{
  if (n == 0) return 0;
  if (n==1) return 1;
  return fiboSum(n-1) + fiboSum(n-2);
}

int main()
{
  for (int count=0; count < 20; ++count)
    std::cout << fiboSum(count) << " ";
  std::cout << '\n';
  return 0;
}
