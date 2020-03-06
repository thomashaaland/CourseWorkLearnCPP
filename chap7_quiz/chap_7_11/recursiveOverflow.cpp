#include <iostream>

void countUp(int n)
{
  std::cout << "Count: " << n << '\n';
  if (n < 10) countUp(++n);
}

int main()
{
  countUp(0);
  return 0;
}
