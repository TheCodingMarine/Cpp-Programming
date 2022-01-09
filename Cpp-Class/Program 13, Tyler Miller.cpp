#include <iostream>
#include <fstream>
/*Program that rights wind speed and temperature data to arrays and then takes the averages of those values.
Based upon code from "Jumping into C++" by Alex Allain and example files composed by Jill Courte.
Written by Tyler Miller, 26 July 2019.*/

using namespace std;

const int DATA_POSITIONS = 30;
double average(int sum, int num);
int totalWindSpeed = 0;
int totalTemp = 0;

int main(int argc, char *argv[])
{
	int temp[DATA_POSITIONS];
	int windSpeed[DATA_POSITIONS];
	int day[DATA_POSITIONS];

	ifstream infile("weatherdata_2.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "The file could not be opened." << endl;
		cin.get();
		return -1;
	}
	int index = 0;
	while (infile >> day[index] && infile >> windSpeed[index] && infile >> temp[index])
	{
		index++;
	}
	for (index = 0; index < DATA_POSITIONS; index++)
	{
		totalWindSpeed += windSpeed[index];
		totalTemp += temp[index];
	}

	double averageWindSpeed = average(totalWindSpeed, DATA_POSITIONS);
	double averageTemp = average(totalTemp, DATA_POSITIONS);

	printf("The average windspeed is %.2f\n", averageWindSpeed);
	printf("The average  temperature is %.2f\n", averageTemp);

	cin.ignore();
	cin.get();
	return 0;


}
double average(int sum, int num)
{
	return sum / num;
}