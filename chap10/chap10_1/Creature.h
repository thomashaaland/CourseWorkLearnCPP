#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"

class Creature
{
 private:
  std::string m_name;
  Point2D m_location;

 public:
  Creature(const std::string &name, const Point2D &location);

  friend std::ostream& operator<<(std::ostream& out, const Creature &creature);

  void moveTo(int x, int y);
};
#endif
