#include <iostream>
#include <array>
#include <random>
#include <ctime>

namespace MyRandom
{
  std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

int rollDice(int min, int max)
{
  std::uniform_int_distribution<> die(min, max);
  return die(MyRandom::mersenne);
}

enum CardRank
  {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
  };
enum CardSuit
  {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
  };

struct Card
{
  CardRank rank;
  CardSuit suit;
};

void printCard(const Card &card)
{
  switch (card.rank)
    {
    case RANK_2:     std::cout << '2'; break;
    case RANK_3:     std::cout << '3'; break;
    case RANK_4:     std::cout << '4'; break;
    case RANK_5:     std::cout << '5'; break;
    case RANK_6:     std::cout << '6'; break;
    case RANK_7:     std::cout << '7'; break;
    case RANK_8:     std::cout << '8'; break;
    case RANK_9:     std::cout << '9'; break;
    case RANK_10:    std::cout << 'T'; break;
    case RANK_JACK:  std::cout << 'J'; break;
    case RANK_QUEEN: std::cout << 'Q'; break;
    case RANK_KING:  std::cout << 'K'; break;
    case RANK_ACE:   std::cout << 'A'; break;
    }

  switch (card.suit)
    {
    case SUIT_CLUB:    std::cout << 'C'; break;
    case SUIT_DIAMOND: std::cout << 'D'; break;
    case SUIT_HEART:   std::cout << 'H'; break;
    case SUIT_SPADE:   std::cout << 'S'; break;
    }
}

void printDeck(const std::array<Card, 52> &deck)
{
  for (const auto &card : deck)
    {
      printCard(card);
      std::cout << ' ';
    }
  std::cout << '\n';
}

void swapCard(Card &a, Card &b)
{
  Card temp = a;
  a = b;
  b = temp;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
  using index_t = std::array<Card, 52>::size_type;
  
  index_t die;
  for (index_t card = 0; card < 52; ++card)
    {
      die = static_cast<index_t>(rollDice(0,52));
      swapCard(deck[card], deck[die]);
    }
}

int getCardValue(const Card &card)
{
  switch (card.rank)
    {
    case RANK_2:      return 2;    
    case RANK_3:      return 3;
    case RANK_4:      return 4;
    case RANK_5:      return 5;
    case RANK_6:      return 6;
    case RANK_7:      return 7;
    case RANK_8:      return 8;
    case RANK_9:      return 9; 
    case RANK_10:     return 10;
    case RANK_JACK:   return 10;
    case RANK_QUEEN:  return 10;
    case RANK_KING:   return 10;
    case RANK_ACE:    return 11;
    }
  
  return 0;
}

int main()
{

  // Creating and initializing deck
  std::array<Card, 52> deck;
  using index_t = std::array<Card, 52>::size_type;
  index_t card = 0;
  for (int suit = 0; suit < MAX_SUITS; ++suit)
    {
      for (int rank = 0; rank < MAX_RANKS; ++rank)
	{
	  deck[card].suit = static_cast<CardSuit>(suit);
	  deck[card].rank = static_cast<CardRank>(rank);
	  ++card;
	}
    }

  printDeck(deck);
  std::cout << getCardValue(deck[10]) << '\n';
  
  shuffleDeck(deck);
  printDeck(deck);
  
  return 0;
}
