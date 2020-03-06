#include <iostream>

class Base
{
private:
  int m_id;

public:
  Base(int id = 0)
    : m_id(id)
  {
  }

  int getId() const { return m_id; }
};

class Derived: public Base
{
private:
  double m_cost;

public:
  Derived(double cost = 0.0, int id = 0)
    : m_cost(cost), Base(id)
  {
  }

  double getCost() const { return m_cost; }
};

int main()
{
  Derived derived(1.3, 5);
  std::cout << "Id: " << derived.getId() << '\n';
  std::cout << "Cost: " << derived.getCost() << '\n';
  
  return 0;
}
