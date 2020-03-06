#include <iostream>

void printBit(unsigned int n)
{
  if (n / 2 > 0) printBit(n/2);
  if (n % 2 == 0) std::cout << 0;
  else std::cout << 1;
}

int main()
{
  for (int i = 0; i < 16; ++i)
    {
      std::cout << " " << i << ": ";
      printBit(i);
    }
  std::cout << '\n';

  printBit(-15);
    

  return 0;
}
