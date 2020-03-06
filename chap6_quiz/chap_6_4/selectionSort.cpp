#include <iostream>
#include <algorithm>

int main()
{
  const int arrayLength = 5;
  int array[arrayLength] { 30, 50, 20, 10, 40 };

  for (int startingIndex = 0; startingIndex < arrayLength - 1; ++startingIndex)
    {
      int highestIndex = startingIndex;
      for (int index = startingIndex; index < arrayLength; ++index)
	{
	  if (array[highestIndex] < array[index]) { highestIndex = index; }
	}
      std::swap(array[startingIndex], array[highestIndex]);
    }

  for (int index = 0; index < arrayLength; ++index)
    {
      std::cout << array[index] << ' ';
    }
  std::cout << '\n';

  
  return 0;
}
