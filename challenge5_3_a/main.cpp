#include <iostream>
#include <cstdlib>

int calculate(int a, int b, char c)
{
  int d;
  switch (c)
    {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    case '%':
      return a % b;
    default:
      std::cout << "Error: " << c << " is not a valid operation.\n";
      exit(0);
    }
}

int main()
{
  int a;
  int b;
  char c;
  std::cout << "Enter a value: ";
  std::cin >> a;
  std::cout << "Enter a second value: ";
  std::cin >> b;
  std::cout << "Enter +, -, *, / or %: ";
  std::cin >> c;

  int d = calculate(a, b, c);

  std::cout << a << c << b << '=' << d << std::endl;
  return 0;
}
