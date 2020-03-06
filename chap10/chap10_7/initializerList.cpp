#include <iostream>
#include <cassert>
#include <initializer_list>

class IntArray
{
private:
  int m_length;
  int *m_data;

public:
  IntArray(int length):
    m_length(length)
  {
    m_data = new int[length];
  }

  IntArray(const std::initializer_list<int> &list):
    IntArray(static_cast<int>(list.size()))
  {
    int count = 0;
    for (auto &element : list )
      {
	m_data[count] = element;
	++count;
      }
  }

  IntArray(const IntArray&) = delete;
  IntArray& operator=(const IntArray& list) = delete;

  IntArray& operator=(const std::initializer_list<int> &list)
  {
    int length{ static_cast<int>(list.size()) };
    if (length != m_length)
      {
	delete[] m_data;
	m_length = length;
	m_data = new int[length];
      }

    int count = 0;
    for (auto element : list)
      {
	m_data[count] = element;
	++count;
      }

    return *this;
  }

  ~IntArray()
  {
    delete[] m_data;
  }

  int operator[](int index)
  {
    assert(index >= 0 && index < m_length);
    return m_data[index];
  }

  int getLength() { return m_length; }
  
};

int main()
{
  IntArray array { 5, 4, 3, 2, 1 };
  for (int count=0; count < array.getLength(); ++count)
    std::cout << array[count] << ' ';
  std::cout << '\n';

  array = { 1, 3, 5, 7, 9, 11 };

  for (int count = 0; count < array.getLength(); ++count)
    std::cout << array[count] << ' ';
  std::cout << '\n';
  
  return 0;
}
