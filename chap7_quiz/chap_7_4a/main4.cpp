#include <iostream>

// use const on all input since nothing is to be changed
// make sure the array is a pointer to an array
int getIndexOfLargestValue(const int *array, const int arraySize);

// need & to avoid returning a copy of the element at the adress
// but return the array element itself
const int& getElement(const int *array, const int index);

int main()
{

  return 0;
}
