// Illigal operation, just because

#include <iostream>

int main()
{

  int a = 1;
  char c = 'A';

  std::cout << &a << '\n';
  std::cout << &c << '\n';
  
  return 0;
}

// the memory adress of c is treated as a char untill \0 is encountered
