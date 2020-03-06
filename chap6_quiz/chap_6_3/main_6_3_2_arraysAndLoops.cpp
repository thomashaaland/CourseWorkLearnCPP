#include <iostream>

// predeclared functions
int userInput();

void printArray(int array[]);

// Main
int main()
{
  int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5 };

  int x = userInput();

  const int arrayLength = sizeof(array)/sizeof(array[0]);
  for (int i = 0; i < arrayLength; ++i)
    {
      std::cout << array[i] << ' ';
    }
  std::cout << '\n';

  for (int i = 0; i < arrayLength; ++i)
    {
      if (x == array[i])
	{
	  std::cout << "The index of the number you entered is: " << i << '\n';
	}
    }
  
  return 0;
}

// Functions

int userInput()
{
  int number;
  while (true)
    {
      std::cout << "Pick a number between 1 and 9: ";
      std::cin >> number;

      if (std::cin.fail())
	{
	  std::cin.clear();
	  std::cin.ignore(32767, '\n');
	}
      else if (number > 0 and number < 10)
	{
	  std::cin.ignore(32767, '\n');
	  return number;
	}
    }
}
   
