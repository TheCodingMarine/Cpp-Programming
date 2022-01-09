#include <iostream>
#include <vector>
#include <string>
#include <cmath>

/*Code to input several variables and kick them to different vectors.
Based off of code learned from "Jumping into C++" by Alex Allain and example files produced by Jill Courte.
Written by Tyler Miller, 30 July 2019.*/

using namespace std;

vector<string> name;
vector<double> cost;
vector<double> radius;
vector<double> height;

string machineName;
int quit = 1;
int quantityToProduce;
double costToProduce;
double mCost;
double mRadius;
double mHeight;

void pushBack();
void outputMenu();
double productionCalc(double x, double y, double z);
int partToCalc;

int main()
{
	do
	{
		cout << "Please enter the name, cost, radius, and height for a part: ";
		cin >> machineName >> mCost >> mRadius >> mHeight;
		pushBack();
		cout << "Are there more parts to enter? Enter 1 for yes: ";
		cin >> quit;
		if (quit != 1)
		{
			break;
		}
	} while (quit == 1);
	

	while(partToCalc != name.size())
	{
		cout << "Options" << endl;
		outputMenu();
		cout << '\n';
		cout << "Please select an option: ";
		cin >> partToCalc;
		if (partToCalc == name.size())
		{
			break;
		}
		cout << "Please enter the quantity you wish to produce: ";
		cin >> quantityToProduce;
		int index = partToCalc;
		costToProduce = productionCalc(height[index], radius[index], cost[index]);
		cout << "The cost of " << quantityToProduce << " " << name[index] << "is: " << costToProduce << endl;

		cin.ignore();
		cin.get();
	} 

	cin.ignore();
	cin.get();
	return 0;
}
void pushBack()
{
	name.push_back(machineName);
	cost.push_back(mCost);
	radius.push_back(mRadius);
	height.push_back(mHeight);
}
void outputMenu()
{
	int i;
	int q = name.size();
	for(i = 0; i < name.size(); i++)
	cout << "<" << i << "> " << name[i] << " (" << cost[i] << ", " << radius[i] << ", " << height[i] << ")" << endl;
	cout << "<" << q << "> Quit.";
}
double productionCalc(double h,	double r, double c)// height, radius, and cost
{

	const double pi = 3.1415926535897;
	double m = c*(pi*(r))*((2*(h))+r);
	return m * quantityToProduce;
}
