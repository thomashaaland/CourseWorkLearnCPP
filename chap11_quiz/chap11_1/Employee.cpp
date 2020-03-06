#include "Employee.h"

void Employee::printNameAndSalary() const
{
  std::cout << m_name << ": " << m_hourlySalary << '\n';
}
