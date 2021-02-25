// from https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
// For understanding static member
// No matter the number of objects of a class containing a static member,
// there is only one static member, so static members are shared among all
// classes containg them.

#include <iostream>

using namespace std;

class Box {
public:
  static int objectCount;

  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout <<"Constructor called." << endl;
    length = l;
    breadth = b;
    height = h;
    
    // Increase every time the object is created
    objectCount++;
  }
  double Volume() {
    return length * breadth *height;
  }
  static int getCount() {
    return objectCount;
  }
  
private:
  double length;   // Length of a box
  double breadth;  // Breadth of a box
  double height;   // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
  // print total number of objects before creating object
  cout << "Initial Stage Count: " << Box::getCount() << endl;
  
  Box Box1(3.3, 1.2, 1.5); // Declare box1
  Box Box2(8.5, 6.0, 2.0); // Declare box2

  // Print total number of objects after creating object.
  cout << "Total objects: " << Box::getCount() << endl;

  return 0;

}
