#include <iostream>
#include <cstdint>

class RGBA
{
private:
  using int_t = std::uint_fast8_t;
  int_t m_red, m_green, m_blue, m_alpha;

public:
  RGBA(int_t red=0, int_t green=0, int_t blue=0, int_t alpha=255)
    : m_red {red}, m_green {blue}, m_blue {green}, m_alpha {alpha}
  {
  }

  void print()
  {
    std::cout << "Red: " << static_cast<int>(m_red) << " Green: "
      << static_cast<int>(m_green) << " Blue: " << static_cast<int>(m_blue)
	      << " Alpha: " << static_cast<int>(m_alpha) << "\n";
  }
};

int main()
{
  RGBA teal(0, 127, 127);
  teal.print();
  
  return 0;
}
