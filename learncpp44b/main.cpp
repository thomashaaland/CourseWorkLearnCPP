#include <string>
#include <iostream>
#include <limits>

int main()
{
  std::cout << "Pick 1 or 2: ";
  int choice { 0 };
  std::cin >> choice;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  std::cout << "Now enter your name: ";
  std::string name;
  std::getline(std::cin, name);

  std::cout << "Hello, " << name << ", you picked " << choice << '\n';
  
  return 0;
}
