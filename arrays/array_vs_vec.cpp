#include<iostream>
#include<chrono>
#include<vector>

void print(int n, int **arr) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int index(int n, int i, int j) {
  return n*i+j;
}

int main() {
  const int n = 1100;
  
  // 2d statically allocated array
  int array[n][n] = {};
  
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      array[i][j];
    }
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> fs = t2 - t1;
  std::cout << "Time to access a static array: \t\t" << std::chrono::duration_cast<std::chrono::milliseconds>(fs).count() << std::endl;
  
  // 1d dynamically allocated array accessed contigously
  int *darr;
  darr = new int[n*n];

  t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      darr[index(n, i, j)];
    }
  }
  t2 = std::chrono::high_resolution_clock::now();
  fs = t2 - t1;
  std::cout << "Time to access a dynamic array: \t" << std::chrono::duration_cast<std::chrono::milliseconds>(fs).count() << std::endl;


  // 2d vector
  std::vector<std::vector<int>> vec(n, std::vector<int>(n));
  t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vec.at(i).at(j);
    }
  }
  t2 = std::chrono::high_resolution_clock::now();
  fs = t2 - t1;
  std::cout << "Time to access a vector array: \t\t" << std::chrono::duration_cast<std::chrono::milliseconds>(fs).count() << std::endl;

  // 1d vector accessed contigously
  std::vector<int> vec2(n*n);
  t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vec2.at(index(n, i, j));
    }
  }
  t2 = std::chrono::high_resolution_clock::now();
  fs = t2 - t1;
  std::cout << "Time to access a 1d vector array: \t" << std::chrono::duration_cast<std::chrono::milliseconds>(fs).count() << std::endl;
  
  return 0;
}
