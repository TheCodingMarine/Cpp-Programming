#include <iostream>
#include <fstream>

/*Program reading from file. Calculates average winds speed and average temperature of values in file. 
Based on code from "Jumping into C++" by Alex Allain and examples created by Jill Courte.
Written by Tyler Miller, 26 July 2019.*/

using namespace std;

double average(int sum, int num);

int main()
{
	int day;
	int totalWindSpeed = 0;
	int windSpeed;
	int totalTemperature = 0;
	int temperature;

	ifstream infile("weatherdata_2.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "File could not be opened." << endl;
		cin.get();
		return -1;
	}

	bool dataRemains = true;
	int count = 0;
	while (dataRemains)
	{
		if (infile >> day && infile >> windSpeed && infile >> temperature)
		{
			totalWindSpeed += windSpeed;
			totalTemperature += temperature;
			count++;
		}
		else
		{
			dataRemains = false;
		}
	}

	infile.close();

	double averageWindSpeed = average(totalWindSpeed, count);
	double averageTemperature = average(totalTemperature, count);

	printf("%d, %.2f, %.2f", count, averageWindSpeed, averageTemperature);
	
	cin.ignore();
	cin.get();
	return 0;
}

double average(int sum, int num)
{
	return sum / num;
}