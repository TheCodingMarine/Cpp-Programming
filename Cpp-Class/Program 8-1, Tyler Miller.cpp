#include <iostream>
#include <iomanip>

using namespace std;

double widthAtTemperature (double x, double y) {
	double z = x + (y - 70) * 10;
	return z;
}

int main(){

	int numberMeasurements = 0;
	double userWidth;
	double temperature;

	cout << "Hello user, please enter the number of measurements that you would like to take: ";
	cin >> numberMeasurements;

	for (double measurementsTaken = 0; measurementsTaken < numberMeasurements; measurementsTaken++) 
	{
		cout << "Please enter the width of your aluminum bar at 70 degrees Farenheit: ";
		cin >> userWidth;
		cout << "Please enter the temperature to measure at: ";
		cin >> temperature;

		double newWidth = widthAtTemperature(userWidth, temperature);
		widthAtTemperature(userWidth, temperature);
		
		cout << "User width" << setw(16) << "Temperature" << setw(22) << "Calculated Width" << endl;
		cout << setw(7) << userWidth << setw(15) << temperature << setw(20) << newWidth << endl;
	}
	

	cin.ignore(); 
	cin.get();
	return 0;
	
}
