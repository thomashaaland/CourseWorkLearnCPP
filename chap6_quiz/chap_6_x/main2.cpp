#include <iostream>
#include <string>
#include <utility>

struct Student
{
  std::string firstName;
  int grade;
};

void sortNames(Student *students, int length)
{
  for (int startIndex = 0; startIndex < length; ++startIndex)
    {
      int largestIndex = startIndex;
      for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
	{
	  if (students[currentIndex].grade > students[largestIndex].grade)
	      largestIndex = currentIndex;
	}
      std::swap(students[startIndex], students[largestIndex]);
    }
}

int main()
{
  std::cout << "How many student do you want to insert: ";
  int numStudents;
  std::cin >> numStudents;

  Student *students = new Student[numStudents];

  for (int i = 0; i < numStudents; ++i)
    {
      std::cout << "Enter name for student #" << i+1 << ": ";
      std::cin >> students[i].firstName;
      std::cout << "Enter grade for student #" << i+1 << ": ";
      std::cin >> students[i].grade;
    }

  sortNames(students, numStudents);
  
  for (int i=0; i < numStudents; ++i)
    {
      std::cout << students[i].firstName << " " << students[i].grade << '\n';
    }

  delete[] students;

  
  
  return 0;
}
