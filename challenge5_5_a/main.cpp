#include <iostream>

int main()
{
  int i = static_cast<int>('a');
  int j = 1;
  while(i < static_cast<int>('z')+1)
    {
      std::cout << static_cast<char>(i) << "=" << i << " ";
      i++;
      if (j%5 == 0) std::cout << '\n';
      j++;
    }
  std::cout << '\n';
  return 0;
}
