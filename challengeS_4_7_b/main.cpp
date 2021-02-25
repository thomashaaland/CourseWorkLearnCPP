#include <iostream>

struct Fraction
{
  int nominator;
  int denominator;
};

double fraction(Fraction frac)
{
  return static_cast<double>(frac.nominator) / frac.denominator;
}

int main()
{
  Fraction myNumber;
  
  std::cout << "Nominator: ";
  std::cin >> myNumber.nominator;

  std::cout << "Denominator: ";
  std::cin >> myNumber.denominator;

  std::cout << "The number is " << fraction(myNumber) << '\n';
  return 0;
}

  
