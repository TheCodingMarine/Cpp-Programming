#include <iostream>
#include <iomanip>
#include <cmath>

/*Program 8-2 drawing on concepts that we have learned thus far in the course, and "Jumping into C++" by Alex Allain. 
Completed by Tyler Miller, 15 July 2019.*/

using namespace std;

double widthAtTemperature(double x, double y) {
	double z = x + (y - 70) * pow(10, -4);
	return z;
}

int main() {

	double userWidth; // intial width to be entered
	double widthTolerance; // tolerance for measurement

	cout << "Please enter the width (cm) of your aluminum bar at 70 degrees Farenheit: ";
	cin >> userWidth;
	cout << "Please input the width tolerance to check against: ";
	cin >> widthTolerance;

	double newWidth; // final width to be output after calculations
	int temperature; // variable set aside to be assigned temperatures between 60-85
	int tempMin = 60; // bottom of temperature range to be ran in the loop
	int tempMax = 85; // top of temperature range to be ran in the loop
	double widthToleranceMin = userWidth - widthTolerance; // this and the following formula setting the upper and lower bounds of the users allowable tolerance
	double widthToleranceMax = userWidth + widthTolerance;

	cout << "Temperature" << setw(16) << "Width" << endl; // this line, as well as line 33, set the headers for the table.
	cout << "<degrees F>" << setw(16) << "<cm>" << endl;
	for (temperature = tempMin; temperature <= tempMax; temperature++) 
	{
		newWidth = widthAtTemperature(userWidth, temperature); // function call inside the loop, calling for calculations at each integer from 60-85
		widthAtTemperature(userWidth, temperature); 
		if (widthToleranceMin <= newWidth && newWidth <= widthToleranceMax) // adding special markers for widths within tolerance
		{
			cout << setw(5) << temperature << setw(23) << newWidth << "**" << endl;
		}
		else // generic output for all other measurements that do not 
		{
			cout << setw(5) << temperature << setw(23) << newWidth << endl;
		}
	}
	cout << "(** marks temperatures still within tolerance)" << endl; // final note informing the user of the significance of the double asterisk
	

	cin.ignore();
	cin.get();
	return 0;

}


