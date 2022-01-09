/*
Starting code for Program 7 Part 1.
Functions introduction, getGuess, and testGuess need to be completed.
Range of numbers to guess needs to be set.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void introduction(int high, int low);
int getGuess(int x);
bool testGuess(int guess, int numberToGuess);



int main(int argc, char *argv[])
{
	int high = 0;
	int low = 0;

	int numberToGuess;
	bool stillPlaying = true;
	bool winner = false;

	int guess;

	// generate a random number between low and high value
	numberToGuess = rand() % (high - low + 1) + low;

	//tell the user about the game
	introduction(high, low);
	guess = getGuess();

	winner = testGuess(guess, numberToGuess);


	cout << "Thanks for playing!" << endl;


	cin.ignore();
	cin.get();

}


//Tells the user the ruules of the game
void introduction(int high, int low)
{
	high = 10;
	low = 1;
	cout << "I am thinking of a number between 1 and 10." << endl;
}

int userguess;
int getGuess(int x)
{
	"Please enter a number between 1 and 10: "; 
	cin >> userguess;
	
	return 0;
}

// returns true if guess is correct
//if guess is not correct, outputs a high or low message and returns false
bool testGuess(int guess, int numberToGuess)
{
	return false;
}