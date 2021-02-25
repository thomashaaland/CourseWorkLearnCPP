#include <iostream>

int main()
{
  int i = 5;
  while (i > 0)
    {
      int j = 5;
      int k = i;
      while (j > 0)
	{
	  if (k-- > 1)
	  {
	    std::cout << "  ";
	  }
	  else
	    {
	      std::cout << j << " ";
	    }
	  j--;
	}
      std::cout << '\n';
      i--; 
    }
  return 0;
}
