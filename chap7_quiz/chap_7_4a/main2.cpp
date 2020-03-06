#include <iostream>
#include <string>

struct Employee
{
  std::string name;
  int age;
};


// use const since employee must not be changed, use & reference for better
// performance
void printEmployeeName(const Employee &employee) 
{
  std::cout << employee.name << '\n';
}
  
int main()
{

  return 0;
}
