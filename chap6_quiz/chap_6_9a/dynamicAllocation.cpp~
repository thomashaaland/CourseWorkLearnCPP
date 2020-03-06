// Dynamically assign memory for an array

#include <iostream>

int main()
{
  std::cout << "Enter a positive integer: ";
  int length;
  std::cin >> length;

  int *array = new int[length];

  std::cout << "New memory allocated for an array of length " << length << '\n';

  array[0] = 5;

  std::cout << "The memory adress of variable length is " << &length << '\n';
  std::cout << "The memory adress of the pointer is " << array << '\n';

  delete[] array;
  array = nullptr;
  
  return 0;
}
