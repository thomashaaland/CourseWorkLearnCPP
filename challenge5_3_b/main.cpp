#include <iostream>
#include <string>
#include <cstdlib>

enum class Animal
  {
    pig,
    chicken,
    goat,
    cat,
    dog,
    ostrich,
  };

std::string getAnimalName(Animal animal)
{
  switch (animal)
    {
    case Animal::pig:
      return "pig";
    case Animal::chicken:
      return "chicken";
    case Animal::goat:
      return "goat";
    case Animal::cat:
      return "cat";
    case Animal::dog:
      return "dog";
    case Animal::ostrich:
      return "ostrich";
    default:
      std::cout << "Not an animal name\n";
      exit(0);
    }
}

void printNumberOfLegs(Animal animal)
{
  std::cout << "A " << getAnimalName(animal) << " has ";
  
  switch (animal)
    {
    case Animal::ostrich:
    case Animal::chicken:
      std::cout << "2";
      break;
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:
    case Animal::pig:
      std::cout << "4";
      break;
    }
  std::cout << " legs.\n";
}

int main()
{
  printNumberOfLegs(Animal::cat);
  printNumberOfLegs(Animal::chicken);
  
  return 0;
}
