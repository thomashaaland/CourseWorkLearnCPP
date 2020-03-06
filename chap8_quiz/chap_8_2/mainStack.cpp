#include <iostream>
#include <cassert>

class Stack{
private:
  static const int s_maxLength{10};
  int array[s_maxLength];
  int length;
public:
  void reset()
  {
    length = 0;
  }

  bool push(int a)
  {
    if (length == 10) return false;
    
    array[length] = a;
    ++length;
    return true;
  }

  int pop()
  {
    assert(length > 0 && "Can not pop empty stack");
    return array[length--];
  }

  void print()
  {
    std::cout << "( ";
    for (int i = 0; i < length; ++i)
      std::cout << array[i] << " ";
    std::cout << ")\n";
  }
  
};

int main()
{
  Stack stack;
  stack.reset();

  stack.print();

  stack.push(5);
  stack.push(3);
  stack.push(8);
  stack.print();

  stack.pop();
  stack.print();

  stack.pop();
  stack.pop();

  stack.print();
  
  return 0;
}
