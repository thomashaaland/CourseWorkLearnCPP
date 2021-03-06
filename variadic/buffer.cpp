#include <cstdio>

int main() {
  char buffer [7];

  int n;
  
  n = sprintf(buffer, "Hello\n");
  printf("%s", buffer);
  
  return 0;
}
