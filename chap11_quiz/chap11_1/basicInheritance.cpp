#include <iostream>
#include <string>
#include "Person.h"
#include "BaseballPlayer.h"

int main()
{
  // Create a baseballPlayer object
  BaseballPlayer pedro("Pedro Cerrano", 32, 0.342, 42);

  std::cout << pedro.getName() << '\n';
  std::cout << pedro.getAge() << '\n';
  std::cout << pedro.getHomeRuns() << '\n';
  
  return 0;
}
