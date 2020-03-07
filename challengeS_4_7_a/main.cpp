#include <iostream>

struct Advertising
{
  int nShown;
  double clickFraction;
  double averageEarn;
};

void printTotalEarn(Advertising ad)
{
  std::cout << "The website has been shown " << ad.nShown << " times \n";
  std::cout << "The click fraction is " << ad.clickFraction << '\n';
  std::cout << "The average earning is " << ad.averageEarn << '\n';
  std::cout << "The total earning is " << ad.nShown * ad.clickFraction * ad.averageEarn << '\n';
}

int main()
{
  Advertising mySite;
  std::cout << "Enter number of times website have been shown: ";
  std::cin >> mySite.nShown;

  std::cout << "Enter the fraction of banners clicked: ";
  std::cin >> mySite.clickFraction;

  std::cout << "Enter the average earning per banner: ";
  std::cin >> mySite.averageEarn;

  printTotalEarn(mySite);

  
  return 0;
}
