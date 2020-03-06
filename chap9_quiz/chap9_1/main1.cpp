#include <iostream>

class Fraction
{
private:
  int m_numerator;
  int m_denominator;

  int gcd(int a, int b) {
    return (b==0) ? (a > 0 ? a : -a) : gcd(b, a % b);
  }
  
public:
  Fraction(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator)
  {}

  
  
  void print()
  {
    int rest = gcd(m_numerator, m_denominator);
    int denominator = m_denominator / rest;

    std::cout << m_numerator/rest << "/" << m_denominator/rest << '\n';
  }

  friend Fraction operator+(Fraction f1, Fraction f2)
  {
    if (f1.m_denominator == f2.m_denominator)
      {
	return Fraction(f1.m_numerator + f2.m_numerator, f1.m_denominator);
      }
    else
      {
	return Fraction(f1.m_numerator*f2.m_denominator
			+ f2.m_numerator*f1.m_denominator,
			f1.m_denominator * f2.m_denominator);
      }
  }

  friend Fraction operator+(Fraction f1, int num)
  {
    return Fraction(f1.m_numerator + num * f1.m_denominator, f1.m_denominator);
  }

  friend Fraction operator+(int num, Fraction f1)
  {
    return Fraction(f1.m_numerator + num * f1.m_denominator, f1.m_denominator);
  }

  friend Fraction operator*(Fraction f1, Fraction f2)
  {
    return Fraction(f1.m_numerator * f2.m_numerator,
		    f1.m_denominator * f2.m_denominator);
  }

  friend Fraction operator*(Fraction f1, int num)
  {
    return Fraction(f1.m_numerator*num, f1.m_denominator);
  }

  friend Fraction operator*(int num, Fraction f1)
  {
    return Fraction(f1.m_numerator*num, f1.m_denominator);
  }
};

int main()
{
  Fraction f1(2, 5);
  f1.print();

  Fraction f2(3,8);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 2;
  f4.print();

  Fraction f5 = 2 * f2;
  f5.print();

  Fraction f6 = Fraction(1,2) * Fraction(2,3) * Fraction(3,4);
  f6.print();
  
  return 0;
}
