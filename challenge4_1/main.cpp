#include <iostream>

int main()
{
  std::cout << "Enter a double value: ";
  double value1{};
  std::cin >> value1;

  std::cout << "Enter a double value: ";
  double value2{};
  std::cin >> value2;

  std::cout << "Enter one of the following: +, -, *, or /: ";
  char value3{};
  std::cin >> value3;
  switch(static_cast<int>(value3))
    {
    case static_cast<int>('+'):
      std::cout << value1 << '+' << value2 << '=' << value1 + value2 << '\n';
      break;
    case static_cast<int>('-'):
      std::cout << value1 << '-' << value2 << '=' << value1 - value2 << 'n';
      break;
    case static_cast<int>('*'):
      std::cout << value1 << '*' << value2 << '=' << value1 * value2 << '\n';
      break;
    case static_cast<int>('/'):
      std::cout << value1 << '/' << value2 << '=' << value1 / value2 << '\n';
      break;
    }
  
}
