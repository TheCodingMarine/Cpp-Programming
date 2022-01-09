/* Magic 8-ball starting code. Modified to use vectors.
Author:  Deepak Dawar for CSE 153, Summer 2019
Modified by Tyler Miller, 29 July 2019.
*/
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
vector<string> m8Ball;
string getAnswer();

int main()
{
	m8Ball.push_back("Do not count on it.");
	m8Ball.push_back("It is certain.");
	m8Ball.push_back("Ask again later.");
	m8Ball.push_back("Very doubtful.");
	m8Ball.push_back("Most likely.");
	m8Ball.push_back("Better not tell you now.");
	m8Ball.push_back("No.");
	m8Ball.push_back("Yes.");

	string question;
	while (question != "x")
	{
		srand((unsigned int)time(NULL));
		cout << "Welcome user, please ask your question (or press 'x' exit): ";
		getline(cin, question);
		cout << getAnswer() << endl;
	}
	
	return 0;
}
string getAnswer()
{
	int index = rand() % m8Ball.size();
	return m8Ball[index];
}

