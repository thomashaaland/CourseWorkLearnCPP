#include "Person.h"

Person::Person(std::string name, int age)
    : m_name(name), m_age(age)
{
}

std::string Person::getName() const { return m_name; }
int Person::getAge() const { return m_age; }  
