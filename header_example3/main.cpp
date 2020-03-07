#include <iostream>
#include "constants.h"

int main()
{
  std::cout << "Enter a radius: ";
  int radius{};
  std::cin >> radius;

  double circumference = 2 * radius * constants::pi;
  std::cout << "The circumference is: " << circumference << '\n';
}
