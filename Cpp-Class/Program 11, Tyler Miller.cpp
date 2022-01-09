#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

/*Program 11 based on code that we have learned from lectures and "Jumping into C++" by Alex Allain.
Written by Tyler Miller, 23 July 2019*/

using namespace std;

//Funciton prototype.
void popFlowrate(double functionArray[], int size);
void printArrays(int arrayOne[], double arrayTwo[], int size);

// constant to use in both arrays, reflecting total input (atleast 10 elements).
const int ARRAY_SIZE = 15;
int startPop;

int main()
{
	int popArray[ARRAY_SIZE];
	double flowArray[ARRAY_SIZE];
	int arrayIndex;
	
	cout << "Welcome user, this program takes in a population value and generates a table of flow rates for populations in thousands." << endl;
	cout << "The table is generated for 15 values." << endl;
	cout << "Please enter the starting population value (1 = 1000, 10 = 10000): ";
	cin >> startPop;
	cout << '\n';

	// Declare and initialize the the first array.
	for (arrayIndex = 1; arrayIndex < ARRAY_SIZE; arrayIndex++) 
	{
		popArray[0] = startPop;
		popArray[arrayIndex] = startPop + arrayIndex;
	}

	//Declare and initialize second array, based on data in first array.
	popFlowrate(flowArray, ARRAY_SIZE);

	//Output both arrays in neat columns with headers.
	printArrays(popArray, flowArray, ARRAY_SIZE);

	cin.ignore();
	cin.get();
	return 0;

}

void popFlowrate(double functionArray[], int size)
{
	for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
	{
		functionArray[0] = startPop;
		functionArray[arrayIndex + startPop] = 3.86*(sqrt((arrayIndex +startPop)))*(1 - 0.01*(sqrt((arrayIndex + startPop))));
	}
}

void printArrays(int arrayOne[], double arrayTwo[], int size)
{
	cout << setw(15) << "Population" << setw(20) << "Flowrate" << endl;
	cout << setw(17) << "In thousands" << endl;
	for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
	{
		arrayOne[0] = startPop;
		cout << setw(11) << arrayOne[arrayIndex] << setw(23) << arrayTwo[arrayIndex + startPop] << endl;
	}
}


//Function.