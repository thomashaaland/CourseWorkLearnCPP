#include "Point2D.h"

// Default constructor
Point2D::Point2D()
  : m_x(0), m_y(0)
{
}

// Specific constructor
Point2D::Point2D(int x, int y)
  : m_x(x), m_y(y)
{
}

  // Access functions
void Point2D::setPoint(int x, int y)
{
  m_x = x;
  m_y = y;
}

std::ostream& operator<<(std::ostream& out, const Point2D &point)
{
  out << "(" << point.m_x << ", " << point.m_y << ")";
  return out;
}
