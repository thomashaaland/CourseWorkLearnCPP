#include <iostream>

int sumTo(const int param)
{
  int sum = 0;
  for (int i = 1; i < param+1; i++)
    {
      sum += i;
    }
  return sum;
}

int main()
{
  int value = sumTo(4);
  std::cout << value << '\n';
  return 0;
}
