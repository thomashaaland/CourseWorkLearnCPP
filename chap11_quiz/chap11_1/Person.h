#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
 private:
  std::string m_name;
  int m_age;
  
 public:
  Person(std::string name = "", int age = 0);
  
  std::string getName() const;
  int getAge() const;
};

#endif
