#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

/*Program that calculates the flight time and height of a proctile, then writes that information to a file in 1 second intervals from take-off to ground contact.
Based on code from "Jumping into C++" by Alex Allain and material covered in CSE 153 Summer 2019.
Written by Tyler Miller, 9AUG2019.*/

using namespace std;

void calcHeight(double speed);
double timeSquare(int time);

vector<int> flightTime;
vector<double> projectileHeight;

string filename;

int main()
{
	double velocity;

	cout << "Hello user, please input the velocity (in meters per second) that you would like to calculate: ";
	cin >> velocity;
	cin.ignore(); 
	cout << "Please name the file that the data shall be sent to: ";
	getline(cin, filename);
	filename += ".txt";

	ofstream outfile;
	outfile.open(filename.c_str(), ios::out);

	calcHeight(velocity);
	outfile << "Time"  && outfile << setw(10) << " Height" << '\n';
	int size = flightTime.size();
	for (unsigned int i = 0; i < flightTime.size(); i++)
	{
		outfile << flightTime[i] && outfile << setw(13) << projectileHeight[i] << '\n';
	}

	
}
double timeSquare(int time)
{
	double tsquare = pow(time, 2);
	return tsquare;
}
void calcHeight(double speed)
{
	double height;
	int time = 0;
	double g = pow(9.8, 2);
	do
	{
		height = ((speed * time) - ((.5 * g) * timeSquare(time)));
		if (0 <= height)
		{
			flightTime.push_back(time);
			projectileHeight.push_back(height);
			time++;
			continue;
		}
		else 
		{
			height = 0;
			flightTime.push_back(time);
			projectileHeight.push_back(height);
			break;
		}

	} while (0 <= height);
	
}