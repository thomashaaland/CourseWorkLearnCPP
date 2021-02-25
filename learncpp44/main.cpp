#include <iostream>
#include <typeinfo>

int main()
{
  double a(4);
  short b(5);
  std::cout << typeid(a+b).name() << " " << a + b << std::endl;

  return 0;
}
