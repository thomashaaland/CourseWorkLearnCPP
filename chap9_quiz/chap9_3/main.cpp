#include <iostream>

class Fraction
{
private:
  int m_numerator;
  int m_denominator;

public:
  Fraction(int numerator=0, int denominator=1):
    m_numerator(numerator), m_denominator(denominator)
  {
    reduce();
  }

  static int gcd(int a, int b)
  {
    return b == 0 ? a : gcd(b, a % b);
  }
  
  void reduce()
  {
    int gcd = Fraction::gcd(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(const Fraction &f1, int value);
  friend Fraction operator*(int value, const Fraction &f1);

  friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
  friend std::istream& operator>> (std::istream &in, Fraction &fraction);
  
  void print()
  {
    std::cout << m_numerator << "/" << m_denominator << "\n";
  }
};

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
  out << fraction.m_numerator << "/" << fraction.m_denominator;
  return out;
}

std::istream& operator>> (std::istream &in, Fraction &fraction)
{
  char c;
  in >> fraction.m_numerator;
  in >> c;
  in >> fraction.m_denominator;

  fraction.reduce();

  return in;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
  return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
  return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
  return Fraction(f1.m_numerator * value, f1.m_denominator);
}


int main()
{

  Fraction f1;
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
  
  return 0;
}
