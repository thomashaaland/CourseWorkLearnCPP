#include <iostream>

namespace AnimalNames
{
  enum AnimalNames
    {
      CHICKEN,
      DOG,
      CAT,
      ELEPHANT,
      DUCK,
      SNAKE,
      MAXELEMENT
    };
}

int main()
{
  int animalLegs[AnimalNames::MAXELEMENT] {2, 4, 4, 4, 2, 0};

  std::cout << animalLegs[AnimalNames::ELEPHANT] << '\n';
  
  return 0;
}
