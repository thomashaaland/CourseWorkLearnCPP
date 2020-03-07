#include <iostream>
#include <string>

int main()
{
  std::cout << "Enter your full name: ";
  std::string fullname;
  std::getline(std::cin, fullname);

  std::cout << "Enter your age: ";
  int age;
  std::cin >> age;

  double rate = static_cast<double>(age)/fullname.length();

  std::cout << "You've lived " << rate << " years for each letter in your name.\n";
  
  return 0;
}
