#include <iostream>

int main()
{
  int scores[] = { 84, 92, 76, 81, 56 };
  const int numStudents = sizeof(scores)/sizeof(scores[0]);
  
  int maxIndex = 0;
  for (int student = 0; student < numStudents; ++student)
    {
      if (scores[student] > scores[maxIndex])
	{
	  maxIndex = student;
	}
    }

  std::cout << "The best score was " << scores[maxIndex] << '\n';

  return 0;
}
