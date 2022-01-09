/* Magic 8-ball starting code.
Author:  deepak Dawar for CSE 153, Summer 2019
Modified by Tyler Miller, 21 July 2019.
*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string getAnswer(string m8Ball[], int nAnswers);
const int M8BALL_REPLY = 8;

int main()
{
	string m8Ball[M8BALL_REPLY]; /*Had issues with getAnswer not reading the string while the string was written in the same style as the array of strings reference.
								 Switched up and wrote the code to reflect the array syntax in the ArrayExamples.cpp. Function started returning correctly in locals while 
								 debugging.*/

	m8Ball[0] = "Do not count on it.";
	m8Ball[1] = "It is certain.";
	m8Ball[2] = "Ask again later.";
	m8Ball[3] = "Very doubtful.";
	m8Ball[4] = "Most likely.";
	m8Ball[5] = "Better not tell you now.";
	m8Ball[6] = "No.";
	m8Ball[7] = "Yes.";

	string question;
	while (question != "x")
	{
		srand((unsigned int)time(NULL));
		cout << "Welcome user, please ask your question (or press 'x' exit): ";
		getline(cin, question); /*Had a moment and forgot how to call a function while writing the code. Used the videos to realize that I only needed to call my variables.
								Confident this would not have been an issue if writing the code from scratch.*/
		cout << getAnswer(m8Ball, M8BALL_REPLY) << endl; /*had issues with the output printing a random series of numbers or letters and numbers.
														 while using the debugger and locals window. I saw that I could get the return correct from the function
														 and the best was to print the return was to simultaneously call and output the function.*/
		
	}
	return 0;
}

string getAnswer(string m8Ball[], int nAnswers)
{
	int index = rand() % nAnswers;
	return m8Ball[index];
}
