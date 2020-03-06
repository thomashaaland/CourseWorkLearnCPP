#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <string>

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

bool playBlackJack(const std::array<Card, 52> deck)
{
  int playerScore = 0;
  int playerAces = 0;
  int dealerScore = 0;
  int dealerAces = 0;
  const Card *cardPtr = &deck[0];


  // Implement score increment or something, keeping track of the aces doesnt work
  // Give two cards to player initially
  std::cout << "You got the cards ";
  printCard(*cardPtr);
  if (getCardValue(*cardPtr) == 11) playerAces += 1;
  playerScore += getCardValue(*(cardPtr++));
  std::cout << " and ";
  printCard(*cardPtr);
  std::cout << ".\n";
  if (getCardValue(*cardPtr) == 11) playerAces += 1;
  playerScore += getCardValue(*(cardPtr++));

  // Give dealer initial card
  std::cout << "The dealer got the card ";
  printCard(*cardPtr);
  std::cout << ".\n";
  if (getCardValue(*cardPtr) == 11) dealerAces += 1;
  dealerScore += getCardValue(*(cardPtr++));

  std::cout << "Your score is: " << playerScore << '\n';
  std::cout << "The dealer score is: " << dealerScore << '\n';
  while (playerScore < 21 and dealerScore < 22)
    {
      std::cout << "Your turn! \n";
      std::cout << "Do you want to pick a card?\n";
      std::string answer;
      std::cin >> answer;
      if (answer == "yes")
	{
	  std::cout << "You picked the card ";
	  printCard(*cardPtr);
	  std::cout << ".\n";
	  if (getCardValue(*cardPtr) == 11) playerAces += 1;
	  playerScore += getCardValue(*(cardPtr++));
	  if (playerScore > 22 and playerAces > 0)
	    {
	      playerScore -= 10;
	      playerAces -= 1;
	    }
	}
      std::cout << "Your score is: " << playerScore << '\n';
      if (dealerScore < 18)
	{
	  std::cout << "The dealer picks a card and gets ";
	  printCard(*cardPtr);
	  std::cout << ".\n";
	  if (getCardValue(*cardPtr) == 11) dealerAces += 1;
	  dealerScore += getCardValue(*(cardPtr++));
	  if (dealerScore > 22 and dealerAces > 0)
	    {
	      dealerScore -= 10;
	      dealerAces -= 1;
	    }
	}
      std::cout << "The dealer score is: " << dealerScore << '\n';
      if (dealerScore > 18 and playerScore > dealerScore)
	break;
    }
  if (playerScore == dealerScore)
    {
      std::cout << "It's a tie! The dealer and you got the same score!\n";
      return false;
    }
      
  if (playerScore > 21)
    {
      std::cout << "You loose! You busted.\n";
      return false;
    }
  else if (dealerScore > 21)
    {
      std::cout << "You win! The dealer busted!\n";
      return true;
    }
  else if (playerScore >= dealerScore)
    {
      std::cout << "You win! Your score is greater then the dealers!\n";
      return true;
    }
  else
    {
      std::cout << "You loose! The dealer got a better score than you!\n";
      return false;
    }
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

  //printDeck(deck);
  //std::cout << getCardValue(deck[10]) << '\n';
  
  shuffleDeck(deck);
  //printDeck(deck);
  playBlackJack(deck);
  
  
  return 0;
}
