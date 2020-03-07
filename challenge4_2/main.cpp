#include <iostream>
#include "constants.h"

bool printHeight(double x_seconds, double start_height)
{
  double height { start_height - myConstants::gravity * 0.5 * x_seconds*x_seconds };

  if(height > 0)
    {
      std::cout <<  "At " << x_seconds << " seconds, the ball"
      " is at height: " << height << " meters\n";

      return true;
    }
  else
    {
      std::cout << "At " << x_seconds << " seconds, the ball is on the ground.\n";
      return false;
    }
}

double getHeight()
{
  std::cout << "Enter the height of the tower in meters: ";
  double height {};
  std::cin >> height;
  return height;
}

int main()
{
  double height = getHeight();

  int time = 0;
  
  while(printHeight(time, height))
    {
      time = ++time;
    }

  
  return 0;
}
