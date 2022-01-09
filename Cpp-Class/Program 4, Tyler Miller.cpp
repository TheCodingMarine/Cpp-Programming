#include <iostream>
#include <string>
#include <math.h>

/*Example program to show three different types of loops.
Created by Jill Courte for CSE 153, spring 2015
Modified by Tyler Miller, 07 July 2019*/

using namespace std;

int main() {
	int num;
	int sum = 0;
	int j;

	cout << "Please enter the number of vehicles: " << endl;
	cin >> j;


	//using a while loop
	int i = 1;

	while (i <= j)
	{
		cout << "Enter number of miles for vehicle " << i << ": ";
		cin >> num;
		sum += num;

		i++;
	}

	double ave = sum / j;
	cout << "The average of the entered numbers is " << ave << endl;

	cin.ignore();
	cin.get();
	return 0;
}