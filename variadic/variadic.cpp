#include <functional>
#include <iostream>
#include <cstdio>

void print() {
  std::cout << "Empty function!" << "\n";
}

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
  std::cout << var1 << "\n";

  print(var2...);
}

int main() {

  print("Hello", 1, 2, 3, "the end!");
  
  return 0;
}
