#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

// Higher order function by function pointer
void do_twice(void (*doing)()) {
  doing();
  doing();
}

// 1rst order function
void do_something() {
  std::cout << "Something" << std::endl;
}

// Higher order function by template
template <typename FN>
void temp(const FN& fun) {
  fun();
}

// main
int main() {
  do_something();
  do_twice(do_something);
  do_twice([](){std::cout << "Something else" << std::endl;});
  temp([](){std::cout << "Template" << std::endl;});

  // lambda functor
  auto sum = [](double A, double B) -> int { return A + B; };
  std::cout << sum(1.4, 2.7) << std::endl;

  // lambda functor with capture
  double pi = 3.1416;
  auto func = [pi] () {
		std::cout << "The value of pi is " << pi << std::endl;
	      };
  func();

  // functor explicitly written
  std::function<double(double, double)> sum2
    = [] (double A, double B) { return A + B; };
  std::cout << sum2(4.6, 5.9) << std::endl;

  // Higher order function example transform (map)
  std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Before transformation: " << std::endl;
  std::for_each(v.begin(), v.end(),
		[] (const int &x) {std::cout << x << " "; });
  std::cout << std::endl;
  std::transform(v.begin(), v.end(), v.begin(),
		 [] (int n) {return n + (n*2); }
		 );
  std::cout << "After transformation:" << std::endl;
  std::for_each(v.begin(), v.end(),
		[] (const int &x) {std::cout << x << " "; });
  std::cout << std::endl;

  // example filter
  std::remove_if (v.begin(), v.end(),
		  [] (int n) { return n%2 != 0; }
		  );
  std::cout << "Filtering: " << std::endl;
  std::for_each(v.begin(), v.end(),
		[] (const int &x) {std::cout << x << " "; });
  std::cout << std::endl;
  // Got some strange behaviour when removing. v.end() shoud change?
  
  
  // example filter into new vector
  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v1;
  std::copy_if (v.begin(), v.end(),
		std::back_inserter(v1),
		[] (int n) {return n%2 != 0; }
		);

  std::cout << "Filter and copy: " << std::endl;
  std::for_each(v1.begin(), v1.end(),
		[] (const int &x) {std::cout << x << " "; });
  std::cout << std::endl;
  
  return 0;
}
