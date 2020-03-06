#include <iostream>
#include <cassert>

class IntArray
{
private:
  int *m_array = nullptr;
  int m_length = 0;

public:
  IntArray(int length):
    m_length(length)
  {
    assert(length > 0 && "IntArray length should be a positive integer");

    m_array = new int[m_length] {0};
  }

  IntArray(const IntArray &array):
    m_length(array.m_length)
  {
    m_array = new int[m_length];

    for (int count = 0; count < array.m_length; ++count)
      m_array[count] = array.m_array[count];
  }

  ~IntArray()
  {
    delete[] m_array;
  }

  friend std::ostream& operator<<(std::ostream &out, const IntArray &array)
  {
    for (int i = 0; i < array.m_length; ++i)
      {
	out << array.m_array[i] << " ";
      }
    return out;
  }
  
  int& operator[](int index)
  {
    assert(index>=0);
    assert(index < m_length);
    return m_array[index];
  }

  IntArray& operator= (const IntArray &array)
  {
    if (this == &array)
      return *this;

    delete[] m_array;

    m_length = array.m_length;

    m_array = new int[m_length];

    for (int count = 0; count < array.m_length; ++count)
      m_array[count] = array.m_array[count];

    return *this;
  }

};

IntArray fillArray()
{
  IntArray a(5);
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main()
{
  IntArray a = fillArray();
  std::cout << a << '\n';
  
  return 0;
}
