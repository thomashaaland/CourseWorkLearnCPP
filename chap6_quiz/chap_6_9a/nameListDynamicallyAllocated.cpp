#include <iostream>
#include <string>

int main()
{
  std::cout << "How many names do you wish to enter: ";
  int numNames;
  std::cin >> numNames;

  std::string *names = new std::string[numNames];

  for (int i = 0; i < numNames; ++i)
    {
      std::cout << "Enter name #" << i+1 << ": ";
      std::string name;
      std::cin >> name;
      names[i] = name;
    }

  std::cout << "The names you entered are: \n";
  for (int i = 0; i < numNames; ++i)
    {
      std::cout << names[i] << " ";
    }
  std::cout << '\n';

  std::cout << "Here is your sorted list:\n";

  // Bubblesort:

  for (int sort = 0; sort < numNames - 1; ++sort)
    {
      for (int bubbleIndex = 0; bubbleIndex < numNames - sort - 1; ++bubbleIndex)
	{
	  int letter = 0;
	  if (names[bubbleIndex][letter] == names[bubbleIndex + 1][letter]) ++letter;
	  else if (names[bubbleIndex][letter] > names[bubbleIndex + 1][letter])
	    {
	      std::swap(names[bubbleIndex], names[bubbleIndex + 1]);
	    }
	}
    }

  std::cout << "The sorted names are: \n";
  for (int i = 0; i < numNames; ++i)
    {
      std::cout << names[i] << " ";
    }
  std::cout << '\n';
  
  delete[] names;
  names = nullptr;
  
  return 0;
}
