#include <iostream>
#include "constants.h"

int main()
{
  std::cout << "Enter some radius: ";
  double radius;
  std::cin >> radius;
  double circumference = 2 * radius * Constants::pi;
  std::cout << "The circumference is: " << circumference << std::endl;

  return 0;
}
