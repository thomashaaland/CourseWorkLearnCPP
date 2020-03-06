#include <iostream>

enum Items
  {
    HEALTH_POTIONS,
    TORCHES,
    ARROWS,
    MAX_ITEMS
  };

int countTotalItems(int (&array)[3])
{
  int length = sizeof(array)/sizeof(array[0]);
  int items;
  for (int i = 0; i < length; ++i)
    {
      items += array[i];
    }
  return items;
}

int main()
{
  int itemsHeld[3] {};

  itemsHeld[HEALTH_POTIONS] = 2;
  itemsHeld[TORCHES] = 5;
  itemsHeld[ARROWS] = 10;

  int numItems = countTotalItems(itemsHeld);
  std::cout << "You hold " << numItems << " items.\n";
  
  return 0;
}
