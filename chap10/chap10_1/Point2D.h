#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D{
 private:
  int m_y;
  int m_x;

 public:
  Point2D();
  Point2D(int x, int y);

  friend std::ostream& operator<<(std::ostream& out, const Point2D &point);

  void setPoint(int x, int y);
};

#endif
