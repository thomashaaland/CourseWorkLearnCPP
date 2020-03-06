#include <iostream>

void charPrint(const char *tekst)
{
  while(*tekst != '\0')
    {
      std::cout << *tekst;
      ++tekst;
    }
  std::cout << '\n';
  
}

int main()
{
  const char *hello = "Hello World!";

  charPrint(hello);
  return 0;
}
