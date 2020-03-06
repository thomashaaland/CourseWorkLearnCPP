#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

namespace MyRandom
{
  // initialize mersenne twister
  std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

// Forward declarations

int produceRandomNumber(int a, int b);
void hiLowSingleGame();
int checkGuess(int guess, int trueNumber);
int playAgain();
int userInput(int guesses);


// MAIN
int main()
{

  hiLowSingleGame();

  return 0;
}

// Forward declared functions

int produceRandomNumber(int a, int b)
{
  // Create a reuseable random number generator running between the numbers a and b
  std::uniform_int_distribution<> die(a,b);
  return die(MyRandom::mersenne);
}

int userInput(int guesses){
  int guess;
  while (true)
    {
      std::cout << "Guess #" << guesses << ": ";
      int guess;
      std::cin >> guess;

      if (std::cin.fail())
	{
	  std::cin.clear();
	  std::cin.ignore(32767, '\n');
	}
      else
	{
	  std::cin.ignore(32767, '\n');
	  return guess;
	}
    }
}

void hiLowSingleGame()
{
  // Introduce the game.
  std::cout << "Let' play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
  int trueNumber = produceRandomNumber(1, 100);

  for (int guesses = 0; guesses <= 7; ++guesses) {
    int guess = userInput(guesses);
    if (checkGuess(guess, trueNumber) == 0) {
      break;
    }
    if (guesses == 7) {
      std::cout << "Sorry, you lose. The correct number was " << trueNumber << ".\n";
      playAgain();
    }
  }
}

int checkGuess(int guess, int trueNumber)
{
  if (guess > trueNumber)
    {
      std::cout << "Your guess is too high.\n";
      return 1;
    }
  else if (guess == trueNumber)
    {
      std::cout << "Correct! You win!\n";
      playAgain();
      return 0;
    }
  else
    {
      std::cout << "Your guess is too low.\n";
      return 1;
    }
}


int playAgain()
{
  std::cout << "Would you like to play again (y/n)? ";
  char input;
  std::cin >> input;
  switch(input)
    {
    case 'y' :
      hiLowSingleGame();
      return 1;
    case 'n':
      std::cout << "Thank you for playing.\n";
      return 0;
    default:
      playAgain();
    }
}
