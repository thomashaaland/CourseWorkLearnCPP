#include <iostream>

int getInteger()
{
  int x;
  std::cout << "Enter an integer: ";
  std::cin >> x;
  return x;
}

char getOperation()
{
  char op;

  do
    {
      std::cout << "Enter '+, -, * or /': ";
      std::cin >> op;
    }
  while (op!='+' && op!= '-' && op!= '*' && op!= '/');

  return op;
}

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  return x / y;
}

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
  char op;
  arithmeticFcn fcn;
};

static const arithmeticStruct arithmeticArray[] {
  { '+', add },
  { '-', subtract },
  { '*', multiply },
  { '/', divide }
};

arithmeticFcn getArithmeticFunction(char operation)
{
  for (const auto &function : arithmeticArray)
    {
      if (function.op == operation) return function.fcn;
    }

  return add;
}

int main()
{
  int x = getInteger();
  char op = getOperation();
  int y = getInteger();
  arithmeticFcn arithmetic = getArithmeticFunction(op);
  int result = arithmetic(x,y);

  std::cout << x << op << y << '=' << result << '\n';

  return 0;
}
