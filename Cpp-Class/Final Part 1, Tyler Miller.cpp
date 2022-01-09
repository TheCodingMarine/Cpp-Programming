#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

/*Final Program Assignment. This program reads in data from a file and sorts the data into categories based on specs for U.S. coins.
Written by Tyler Miller, 08AUG2019.
Based on "Jumping into C++" by Alex Allain, and material covered in CSE 153 Summer 2019.*/

struct Penny
{
	double width;
	double weight;
};

struct Nickel
{
	double width;
	double weight;
};

struct Dime
{
	double width;
	double weight;
};

struct Quarter
{
	double width;
	double weight;
};

struct Invalid
{
	double width;
	double weight;
};

Penny newPenny(double width, double weight);
Nickel newNickel(double width, double weight);
Dime newDime(double width, double weight);
Quarter newQuarter(double width, double weight);
Invalid newInvalid(double width, double weight);

const double PENNY_WIDTH = 19.05;
const double PENNY_WEIGHT = 2.5;
const double PENNY_VALUE = .01;
const double  NICKEL_WIDTH = 21.21;
const double NICKEL_WEIGHT = 5;
const double NICKEL_VALUE = .05;
const double DIME_WIDTH = 17.91;
const double DIME_WEIGHT = 2.268;
const double DIME_VALUE = .1;
const double QUARTER_WIDTH = 24.26;
const double QUARTER_WEIGHT = 5.67;
const double QUARTER_VALUE = .25;
const double COIN_TOLERANCE = .02;

using namespace std;

double coinWidthTolerance(double width, double tolerance);
double coinWidthMax(double width, double tolerance);
double coinWidthMin(double width, double tolerance);
double coinWeightTolerance(double width, double tolerance);
double coinWeightMax(double width, double tolerance);
double coinWeightMin(double width, double tolerance);
double coinsValue(int count, double value); //function to take the total amount of coins and the total value of coins.

int main()
{

	double pennyWidthMax = coinWidthMax(PENNY_WIDTH, COIN_TOLERANCE);
	double pennyWidthMin = coinWidthMin(PENNY_WIDTH, COIN_TOLERANCE);

	double pennyWeightMax = coinWeightMax(PENNY_WEIGHT, COIN_TOLERANCE);
	double pennyWeightMin = coinWeightMin(PENNY_WEIGHT, COIN_TOLERANCE);

	double nickelWidthMax = coinWidthMax(NICKEL_WIDTH, COIN_TOLERANCE);
	double nickelWidthMin = coinWidthMin(NICKEL_WIDTH, COIN_TOLERANCE);

	double nickelWeightMax = coinWeightMax(NICKEL_WEIGHT, COIN_TOLERANCE);
	double nickelWeightMin = coinWeightMin(NICKEL_WEIGHT, COIN_TOLERANCE);

	double dimeWidthMax = coinWidthMax(DIME_WIDTH, COIN_TOLERANCE);
	double dimeWidthMin = coinWidthMin(DIME_WIDTH, COIN_TOLERANCE);

	double dimeWeightMax = coinWeightMax(DIME_WEIGHT, COIN_TOLERANCE);
	double dimeWeightMin = coinWeightMin(DIME_WEIGHT, COIN_TOLERANCE);

	double quarterWidthMax = coinWidthMax(QUARTER_WIDTH, COIN_TOLERANCE);
	double quarterWidthMin = coinWidthMin(QUARTER_WIDTH, COIN_TOLERANCE);

	double quarterWeightMax = coinWeightMax(QUARTER_WEIGHT, COIN_TOLERANCE);
	double quarterWeightMin = coinWeightMin(QUARTER_WEIGHT, COIN_TOLERANCE);

	int pennyCount = 0;
	int nickelCount = 0;
	int dimeCount = 0;
	int quarterCount = 0;
	int invalidCount = 0;

	ifstream infile;
	infile.open("coinstest.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "File could not be opened." << endl;
		return -1;
	}

	double coinWidth;
	double coinWeight;
	while (!infile.eof())
	{
		while (infile >> coinWidth && infile >> coinWeight)
		{
			if (pennyWidthMin < coinWidth && coinWidth < pennyWidthMax)
			{
				if (pennyWeightMin < coinWeight && coinWeight < pennyWeightMax)
				{
					newPenny(coinWidth, coinWeight);
					pennyCount++;
				}
				else
				{
					continue;
				}
			}
			else if (nickelWidthMin < coinWidth && coinWidth < nickelWidthMax)
			{
				if (nickelWeightMin < coinWeight && coinWeight < nickelWeightMax)
				{
					newNickel(coinWidth, coinWeight);
					nickelCount++;
				}
				else
				{
					continue;
				}
			}
			else if (dimeWidthMin < coinWidth && coinWidth < dimeWidthMax)
			{
				if (dimeWeightMin < coinWeight && coinWeight < dimeWeightMax)
				{
					newDime(coinWidth, coinWeight);
					dimeCount++;
				}
				else
				{
					continue;
				}
			}
			else if (quarterWidthMin < coinWidth && coinWidth < quarterWidthMax)
			{
				if (quarterWeightMin < coinWeight && coinWeight < quarterWeightMax)
				{
					newQuarter(coinWidth, coinWeight);
					quarterCount++;
				}
				else
				{
					continue;
				}
			}
			else
			{
				newInvalid(coinWidth, coinWeight);
				invalidCount++;
			}
		}

	}
	infile.close();

	cout << "Acceptable width of a penny is from " << pennyWidthMin << " to " << pennyWidthMax << endl;
	cout << "Acceptable weight of a penny is from " << pennyWeightMin << " to " << pennyWeightMax << endl;
	cout << '\n';
	cout << "Acceptable width of a nickel is from " << nickelWidthMin << " to " << nickelWidthMax << endl;
	cout << "Acceptable weight of a nickel is from " << nickelWeightMin << " to " << nickelWeightMax << endl;
	cout << '\n';
	cout << "Acceptable width of a dime is from " << dimeWidthMin << " to " << dimeWidthMax << endl;
	cout << "Acceptable weight of a dime is from " << dimeWeightMin << " to " << dimeWeightMax << endl;
	cout << '\n';
	cout << "Acceptable width of a quarter is from " << quarterWidthMin << " to " << quarterWidthMax << endl;
	cout << "Acceptable weight of a quarter is from " << quarterWeightMin << " to " << quarterWeightMax << endl;
	cout << '\n';
	cout << "The number of pennies is: " << pennyCount << " and the worth is: " << coinsValue(pennyCount, PENNY_VALUE) << endl;
	cout << '\n';
	cout << "The number of nickels is: " << nickelCount << " and the worth is: " << coinsValue(nickelCount, NICKEL_VALUE) << endl;
	cout << '\n';
	cout << "The number of dimes is: " << dimeCount << " and the worth is: " << coinsValue(dimeCount, DIME_VALUE) << endl;
	cout << '\n';
	cout << "The number of quarters is: " << quarterCount << " and the worth is: " << coinsValue(quarterCount, QUARTER_VALUE) << endl;
	cout << '\n';
	cout << "The number of invalid coins is: " << invalidCount << endl;

	cin.ignore();
	cin.get();
	return 0;

}
double coinWidthTolerance(double width, double tolerance)
{
	double z = width * tolerance;
	return z;
}
double coinWidthMax(double width, double tolerance)
{
	double z = coinWidthTolerance(width, tolerance);
	double maxWidth = width + z;
	return maxWidth;
}
double coinWidthMin(double width, double tolerance)
{
	double z = coinWidthTolerance(width, tolerance);
	double minWidth = width - z;
	return minWidth;
}
double coinWeightTolerance(double width, double tolerance)
{
	double z = width * tolerance;
	return z;
}

double coinWeightMax(double weight, double tolerance)
{
	double z = coinWeightTolerance(weight, tolerance);
	double maxWeight = weight + z;
	return maxWeight;
}
double coinWeightMin(double weight, double tolerance)
{
	double z = coinWeightTolerance(weight, tolerance);
	double minWeight = weight - z;
	return minWeight;
}

double coinsValue(int count, double value)
{
	double totalValue = count * value;
	return totalValue;
}
Penny newPenny(double width, double weight)
{
	Penny penny;
	penny.width = width;
	penny.weight = weight;	

	return penny;
}
Nickel newNickel(double width, double weight)
{
	Nickel nickel;
	nickel.width = width;
	nickel.weight = weight;

	return nickel;
}
Dime newDime(double width, double weight)
{
	Dime dime;
	dime.width = width;
	dime.weight = weight;

	return dime;
}
Quarter newQuarter(double width, double weight)
{
	Quarter quarter;
	quarter.width = width;
	quarter.weight = weight;

	return quarter;
}
Invalid newInvalid(double width, double weight)
{
	Invalid invalid;
	invalid.width = width;
	invalid.weight = weight;

	return invalid;
}