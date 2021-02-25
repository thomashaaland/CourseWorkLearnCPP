#include <iostream>
#include <string>

enum class MonsterType
  {
    Ogre,
    Dragon,
    Orc,
    Giant_spider,
    Slime,
  };

struct Monster
{
  MonsterType type;
  std::string name;
  int health;
};

std::string monsterType(Monster monster)
{
  std::string type;
  switch(monster.type)
    {
    case MonsterType::Ogre: type = "Ogre";
      break;
    case MonsterType::Dragon: type = "Dragon";
      break;
    case MonsterType::Orc: type = "Orc";
      break;
    case MonsterType::Giant_spider: type = "Giant spider";
      break;
    case MonsterType::Slime: type = "Slime";
      break;
    }
  return type;
}

void printMonster(Monster monster)
{
  std::cout << "This " << monsterType(monster) << " is named "
	    << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
  Monster Ogre = { MonsterType::Ogre, "Torg", 145 };
  Monster Slime = { MonsterType::Slime, "Blurp", 23 };

  printMonster(Ogre);
  printMonster(Slime);
  
  return 0;
}
