#include <iostream>

int sumInt(int x)
{
  if (x < 10)
    return x;
  else
    return sumInt(x / 10) + x % 10;
}

int main()
{
  std::cout << sumInt(93427) << '\n';
  return 0;
}
