/*Program to deterine if a given pollutant emission is within allowable levels.
Author:  Deepak Dawar for CSE 153, Summer 2019
Modified by Tyler Miller, 17 July 2019
*/

#include <iostream>
#include <string>

const int FIRST_STAGE_MILEAGE = 50000;
const int SECOND_STAGE_MILEAGE = 100000;
const int CARBON_MONOXIDE = 1;
const int HYDROCARBONS = 2;
const int NITROGEN_OXIDES = 3;
const int NONMETHANE_HYDROCARBONS = 4;
const int QUIT = 0;
//Declare other related constants here

const double CARBON_MONOXIDE_ALLOWED1 = 3.4;
const double CARBON_MONOXIDE_ALLOWED2 = 4.2;
//Declare other related constants here

const double HYDROCARBON_ALLOWED1 = 0.31;
const double HYDROCARBON_ALLOWED2 = 0.39;
//Declare other related constant here

const double NITROGEN_OXIDE_ALLOWED1 = 0.4;
const double NITROGEN_OXIDE_ALLOWED2 = 0.5;
//Declare other related constant here

const double NONMETHANE_HYDROCARBON_ALLOWED1 = 0.25;
const double NONMETHANE_HYDROCARBON_ALLOWED2 = 0.31;
//Declare other related constant here


using namespace std;

//function prototype that will print the menu
void outputMenu();
double getAllowableLevel(const double x, const double y, int z);


int main(int argc, char *argv[])
{
	int pollutant;
	double gramsPerMile;
	int odometer;
	bool compliant;
	double allowableGramsPerMile;
	while (outputMenu != 0) // program keeps looping until user enters 0 to quit..
	{
		outputMenu();
		cout << "Enter pollutant number: ";
		cin >> pollutant;
		cout << "Enter grams emitted per mile: ";
		cin >> gramsPerMile;
		cout << "Enter odometer reading: ";
		cin >> odometer;
		cout << '\n';

		while (int i = odometer) // odometer input loop.
		{
			if (i < 0)
			{
				cout << "Mileage " << odometer << " must be within 0-100000 miles" << endl;
				cout << '\n';
				outputMenu();
				cout << "Enter pollutant number: ";
				cin >> pollutant;
				cout << "Enter grams emitted per mile: ";
				cin >> gramsPerMile;
				cout << "Enter odometer reading: ";
				cin >> odometer;
				cout << '\n';
			}
			else if (SECOND_STAGE_MILEAGE < i)
			{
				cout << "Mileage " << odometer << " must be within 0-100000 miles" << endl;
				cout << '\n';
				outputMenu();
				cout << "Enter pollutant number: ";
				cin >> pollutant;
				cout << "Enter grams emitted per mile: ";
				cin >> gramsPerMile;
				cout << "Enter odometer reading: ";
				cin >> odometer;
				cout << '\n';
			}
			else 
			{
				break;
			}
		}

		switch (pollutant)
		{
		case CARBON_MONOXIDE:
			allowableGramsPerMile = getAllowableLevel(CARBON_MONOXIDE_ALLOWED1, CARBON_MONOXIDE_ALLOWED2, odometer);
			break;
		case HYDROCARBONS:
			allowableGramsPerMile = getAllowableLevel(HYDROCARBON_ALLOWED1, HYDROCARBON_ALLOWED2, odometer);
			break;
		case NITROGEN_OXIDES:
			allowableGramsPerMile = getAllowableLevel(NITROGEN_OXIDE_ALLOWED1, NITROGEN_OXIDE_ALLOWED2, odometer);
			break;
		case NONMETHANE_HYDROCARBONS:
			allowableGramsPerMile = getAllowableLevel(NONMETHANE_HYDROCARBON_ALLOWED1, NONMETHANE_HYDROCARBON_ALLOWED2, odometer);
			break;


		}

		string compliance;

		compliant = gramsPerMile <= allowableGramsPerMile;
		if (compliant)
			compliance = "within";
		else
			compliance = "exceeds";

		cout << "Emissions " << compliance << " allowable level of " << allowableGramsPerMile << " grams/mile" << endl;
		cout << '\n';

		cin.ignore();
		cin.get();
	}
	

	cin.ignore();
	cin.get();
}


void outputMenu()
{
	cout << "(" << CARBON_MONOXIDE << ") Carbon monoxide" << endl;
	cout << "(" << HYDROCARBONS << ") Hydrocarbon" << endl;
	cout << "(" << NITROGEN_OXIDES << ") Nitrogen oxides" << endl;
	cout << "(" << NONMETHANE_HYDROCARBONS << ") Non-Methane Hydrocarbons" << endl;
	cout << "(" << QUIT << ") Quit" << endl;	
}

double getAllowableLevel(const double x,const double y, int odometer)
{
	if (odometer <= FIRST_STAGE_MILEAGE) // simple "if" statement saying if we are not in this range then we are in this range.
	{
		return x;
	}
	else
	{
		return y;
	}

}

