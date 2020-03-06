#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()

class IntArray
{
 private:
  int m_length;
  int *m_data;

 public:
 IntArray():
  m_length(0), m_data(nullptr)
  {
  }

 IntArray(int length):
  m_length(length)
  {
    assert(length >= 0);

    if (length > 0)
      m_data = new int[length];
    else
      m_data = nullptr;
  }

  ~IntArray()
    {
      delete[] m_data;
    }

  void erase()
  {
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
  }

  int& operator[](int index)
  {
    assert(index >= 0 && index < m_length);
    return m_data[index];
  }

  int getLength() { return m_length; }

  // reallocate resizes the array, but destroys all elements in it
  void reallocate(int newLength)
  {
    // Delete any existing elements
    erase();

    // If new array will be empty, return here
    if (newLength <= 0)
      return;

    // Allocate new elements
    m_data = new int[newLength];
    m_length = newLength;
  }

  // resize resizes the array and keeps elements in it
  void resize(int newLength)
  {
    // if the array is already the right length, we are done
    if (newLength == m_length)
      return;

    // if new array will be empty:
    if (newLength <= 0)
      {
	erase();
	return;
      }

    // Newlength can be assumed to be 1 or greater from here on
    int *data = new int[newLength];

    if (m_length > 0)
      {
	int elementsToCopy = (newLength > m_length) ? m_length : newLength;

	for (int index = 0; index < elementsToCopy; ++index)
	  data[index] = m_data[index];
	
      }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
  }

  void insertBefore(int value, int index)
  {
    // Sanity check our index value
    assert(index >= 0 && index <= m_length);

    // First create a new array one element larger than the old array
    int *data = new int[m_length+1];

    // Copy all of the elements up to the index
    for (int before=0; before < index; ++before)
      data[before] = m_data[before];

    // insert our new element into the new array
    data [index] = value;

    // Copy all of the values after the inserted element
    for (int after=index; after < m_length; ++after)
      data[after+1] = m_data[after];

    // Finally, delete the old array, and use the new array instead
    delete[] m_data;
    m_data = data;
    ++m_length;
  }

  void remove(int index)
  {
    // sanity check our index value
    assert(index >= 0 && index < m_length);

    // if this is the last element in the array, set the array to empty and bail out
    if (m_length == 1)
      {
	erase();
	return;
      }

    // first create a new array one element smaller than the old array
    int *data = new int[m_length-1];

    // copy all of the elements up to the index
    for (int before=0; before < index; ++before)
      data[before] = m_data[before];

    // copy all the values after the removed element
    for (int before=0; before < index; ++before)
      data[before] = m_data[before];

    // copy all of the values after the removed element
    for (int after = index + 1; after < m_length; ++after)
      data[after -1] = m_data[after];

    //Finally, delete the old array and use the new array instead
    delete[] m_data;
    m_data = data;
    --m_length;

  }

  void insertAtBeginning(int value) { insertBefore(value, 0); }
  void insertAtEnd(int value) { insertBefore(value, m_length); }
    
  
};

#endif
