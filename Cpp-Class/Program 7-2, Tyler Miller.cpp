/*
Starting code for guessing game.

Functions introduction, getGuess, and testGuess need to be completed.
Range of numbers to guess needs to be set.
Code needs to be added to ask if user wants another game and loop control set accordingly.
Code needs to be added to track number of guesses.


*/

#include <iostream>
#include <string>
#include <ctime>



using namespace std;


void introduction(int high, int low);
int getGuess();
bool testGuess(int guess, int numberToGuess);
int winCount = 0;
int gamesPlayed = 0;
int counter = 0;
string replay, dreplay;



int main(int argc, char *argv[])
{
	int high = 10;
	int low = 1;

	int numberToGuess;
	bool stillPlaying = true;
	bool winner = false;

	int guess;

	while (stillPlaying)
	{
		srand(time(NULL));
		// generate a random number between low and high value
		numberToGuess = rand() % (high - low + 1) + low;

		//tell the user about the game
		introduction(high, low);

		while (!winner)
		{
			guess = getGuess();

			winner = testGuess(guess, numberToGuess);
			if (winner) {
				cout << "Congratulations, you won!!" << endl;
				winCount++;
				gamesPlayed++;
				counter++;
				cout << "Would you like to play again? Y for Yes and N for No: " << endl;
				cin >> replay;
				if (replay == "y") {
					winner = false;
					cin.ignore();
					cin.get();
				}
				else {
					stillPlaying = false;
					if (stillPlaying == false) {
						break;
					}
					cin.ignore();
					cin.get();
				}
			}
			else {
				counter++;
				gamesPlayed++;
				cout << "You have made " << counter << " guess(es)." << endl;
				cout << "Would you like to play again? Y for Yes and N for No: " << endl;
				cin >> replay;
				if (replay == "y") {
					winner = false;
					cin.ignore();
					cin.get();

				}
				else {
					stillPlaying = false;
					if (stillPlaying == false) {
						break;
					}
					cin.ignore();
					cin.get();
				}

			}
		}
	}

	cout << "You made " << counter << " guess(es)." << endl;
	cout << "Games played: " << gamesPlayed << endl;
	cout << "Games won: " << winCount << endl;
	cout << "Thanks for playing!" << endl;

	cin.ignore();
	cin.get();
	return 0;
}


//Tells the user the ruules of the game
void introduction(int high, int low)
{
	cout << "Hello User, I am thinking of a number between 1 and 10." << endl;
}


int getGuess()
{
	int x;
	cout << "Please enter a number between 1 and 10: ";
	cin >> x;

	return x;
}

// returns true if guess is correct
//if guess is not correct, outputs a high or low message and returns false
bool testGuess(int guess, int numberToGuess)
{
	if (guess < numberToGuess) {
		cout << "Sorry but your guess was lower than the number to guess." << endl;
	}
	else if (guess > numberToGuess) {
		cout << "Sorry but your guess was higher than the number to guess." << endl;
	}
	else {
		cout << "Congratulations, you have won!" << endl;
	}

	return false;
}