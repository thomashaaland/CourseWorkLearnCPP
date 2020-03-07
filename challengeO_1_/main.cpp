#include <iostream>

// The function returns true if the number is even and false if
// the number is odd
bool isEven(int number)
{
  return number % 2 == 0;
}

int main()
{
  std::cout << "Please enter a number: ";
  int number;
  std::cin >> number;

  if(!isEven(number)) { std::cout << "The number is odd." << std::endl; }
  else { std::cout << "The number is even." << std::endl; }

  
  return 0;
}
