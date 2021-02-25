#include <iostream>

int main()
{
  std::cout << "Enter an integer: ";
  int number1;
  std::cin >> number1;

  std::cout << "Enter a larger integer: ";
  int number2;
  std::cin >> number2;

  if (number2 < number1)
    {
      std::cout << "Swapping the values\n";
      int temp;
      temp = number1;
      number1 = number2;
      number2 = temp;
    }

  std::cout << "The smaller value is " << number1 << std::endl;
  std::cout << "The larger value is " << number2 << std::endl;

    
  

  
  return 0;
}
