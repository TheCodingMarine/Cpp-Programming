#include <iostream>
#include <vector>
#include <string>
/*Code to input several variables and kick them to different vectors.
Based off of code learned from "Jumping into C++" by Alex Allain and example files produced by Jill Courte.
Written by Tyler Miller, 30 July 2019.*/

using namespace std;

vector<string> name;
vector<double> cost;
vector<double> radius;
vector<double> height;
void pushBack(string a, double b, double c, double d);
int quit = 1;

int main()
{
	double mCost;
	double mRadius;
	double mHeight;
	string machineName;
	do
	{ 
		cout << "Please enter the name, cost, radius, and height for a part: ";
		cin >> machineName >> mCost >> mRadius >> mHeight;
		pushBack(machineName, mCost, mRadius, mHeight);
		cout << "Are there more parts to enter? Enter 1 for yes: ";
		cin >> quit;
		if (quit != 1)
		{
			break;
		}
	} while (quit == 1);

	cin.ignore();
	cin.get();
	return 0;
}
void pushBack(string a, double b, double c, double d)
{
	name.push_back(a);
	cost.push_back(b);
	radius.push_back(c);
	height.push_back(d);
}
