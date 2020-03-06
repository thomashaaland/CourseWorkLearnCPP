// Overloading Operator()

#include <iostream>
#include <cassert>
#include <string>

class Mystring
{
private:
  std::string m_string;

public:
  Mystring(const std::string string="")
    :m_string(string)
  {
  }
  
  std::string operator() (int start, int length)
  {
    assert(start + length <= m_string.length() && "Mystring::operator(int, int): Substring is out of range");

    std::string ret;
    for (int count = 0; count < length; ++count)
      ret += m_string[start + count];
    
    return ret;
  }
};

int main()
{
  Mystring string("Hello, world!");
  std::cout << string(7, 5);
  
  return 0;

}
