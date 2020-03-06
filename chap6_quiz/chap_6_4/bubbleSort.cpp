#include <iostream>
#include <algorithm>

int main()
{
  const int length(9);
  int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  int didSwap = 0;
  int iterations = 0;
  
  for (int sort = 0; sort < length-1; ++sort)
    {
      didSwap = length - sort - 1;
      for (int bubbleIndex = 0; bubbleIndex < length - sort - 1; ++bubbleIndex)
	{
	  if (array[bubbleIndex] > array[bubbleIndex + 1])
	    {
	      std::swap(array[bubbleIndex], array[bubbleIndex + 1]);
	    }
	  else { --didSwap; }
	}
      ++iterations;
      if (!didSwap) break;
    }

  
  for (int index = 0; index < length; ++index)
    {
      std::cout << array[index] << ' ';
    }
  std::cout << '\n';
  std::cout << iterations << '\n';
  
  return 0;
}
