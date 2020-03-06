#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"

class Supervisor: public Employee
{
 public:
  long m_overseesID[5];

  Supervisor()
    {
    }
};

#endif
