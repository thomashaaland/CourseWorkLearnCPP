#include <iostream>

void foo(int *&p)
{
}

int main()
{
  int *p;
  foo(p);

  std::cout << *p << '\n';
  return 0;
}
