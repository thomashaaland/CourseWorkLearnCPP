#include <iostream>
#include <string>

int main()
{
  const int numNames= 8;
  std::string names[numNames] = { "Alex",
				  "Betty",
				  "Caroline",
				  "Dave",
				  "Emily",
				  "Fred",
				  "Greg",
				  "Holly" };

  std::cout << "Enter a name: ";
  std::string name;
  std::cin >> name;

  bool nameFound = false;
  for (const auto &checkedName : names)
    {
      if (name == checkedName)
	{
	  nameFound = true;
	  break;
	}
    }
  if (nameFound) std::cout << name << " was found.\n"; 
  else std::cout << name << " was not found.\n"; 

  
  return 0;
}
