#include <iostream>

template<typename ... T>
auto sum(T ... t)
{
  typename std::common_type<T...>::type result{};
  (void)std::initializer_list<int>{ (result += t, 0)... };
  return result;
}

template<typename ... T>
auto sum2(T ... t)
{
  return ( t + ... );
}

int main()
{
  std::cout << sum(1,2,3.0,4.5) << '\n';
  std::cout << sum2(1,2,3.0,4.5) << '\n';
}
