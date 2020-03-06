#ifndef BASEBALLPLAYER_H
#define BASEBALLPLAYER_H
#include "Person.h"

class BaseballPlayer : public Person
{
 private:
  double m_battingAverage;
  int m_homeRuns;

 public:
 BaseballPlayer(std::string name = "", int age = 0,
		double battingAverage = 0.0, int homeRuns = 0)
   : Person(name, age),
    m_battingAverage(battingAverage), m_homeRuns(homeRuns)
  {
  }

  double getBattingAverage() { return m_battingAverage; }
  int getHomeRuns() { return m_homeRuns; }
};

#endif
