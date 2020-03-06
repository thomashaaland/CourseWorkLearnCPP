#include <string>
#include <iostream>
#include <vector>

class Teacher
{
private:
  std::string m_name;

public:
  Teacher(std::string name)
    : m_name(name)
  {
  }

  std::string getName() { return m_name; }
};

class Department
{
private:
  std::vector<Teacher*> m_teacher;

public:
  Department()
  {
  }

  void add(Teacher *teacher)
  {
    m_teacher.push_back(teacher);
  }

  friend std::ostream& operator <<(std::ostream &out, const Department &dept)
  {
    out << "Department: ";
    for (const auto &element : dept.m_teacher)
      out << element->getName() << ' ';
    out << '\n';

    return out;
  }

};

int main()
{
  Teacher *t1 = new Teacher("Bob");
  Teacher *t2 = new Teacher("Frank");
  Teacher *t3 = new Teacher("Beth");

  {
    Department dept;
    dept.add(t1);
    dept.add(t2);
    dept.add(t3);

    std::cout << dept;
  }

  std::cout << t1->getName() << " still exists!\n";
  std::cout << t2->getName() << " still exists!\n";
  std::cout << t3->getName() << " still exists!\n";

  delete t1;
  delete t2;
  delete t3;
  
  return 0;
}
