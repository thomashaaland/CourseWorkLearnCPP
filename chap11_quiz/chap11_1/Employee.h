#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>

// Employee publicly inherits from Person
class Employee: public Person
{
 public:
  double m_hourlySalary;
  long m_employeeID;

  Employee(double hourlySalary = 0.0, long employeeID = 0)
    : m_hourlySalary(hourlySalary), m_employeeID(employeeID)
  {
  }

  void printNameAndSalary() const;
};

#endif
