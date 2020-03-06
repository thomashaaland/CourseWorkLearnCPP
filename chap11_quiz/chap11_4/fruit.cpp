#include <iostream>
#include <string>

class Fruit
{
private:
  std::string m_taste;
  std::string m_color;
public:
  Fruit(std::string taste, std::string color)
    : m_taste(taste), m_color(color)
  {
  }

  std::string getTaste() const { return m_taste; }
  std::string getColor() const { return m_color; }
  
};

class Apple: public Fruit
{
private:
  double m_diameter;

public:
  Apple(std::string taste, std::string color, double diameter)
    : Fruit(taste, color), m_diameter(diameter)
  {
  }

  double getDiameter() const { return m_diameter; }
};

std::ostream& operator<<(std::ostream& out, const Apple &apple)
{
  out << "Apple(" << apple.getTaste() << ", " << apple.getColor() << ", " << apple.getDiameter() << ")\n";
  return out;
}

class Banana: public Fruit
{
public:
  Banana(std::string taste, std::string color)
    : Fruit(taste, color)
  {
  }

};

std::ostream& operator<<(std::ostream& out, const Banana &banana)
{
  out << "Banana(" << banana.getTaste() << ", " << banana.getColor() << ")\n";
}

int main()
{
  const Apple a("Red delicious", "red", 4.2);
  std::cout << a;

  const Banana b("Cavendish", "yellow");
  std::cout << b;
  
  return 0;
}
