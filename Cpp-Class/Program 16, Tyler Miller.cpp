#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>	
/*Program that reads in the most popular baby names of 2014. The program then separates the names and separates them into separate files for boys and girls names.
Based on code from "Jumping into C++" by Alex Allain and materials presented in this course.
Written by Tyler Miller, 3 August 2019.*/

using namespace std;

vector<string> boyNames;
vector<string> girlNames;
vector<int> popularityIndex;


int main()
{
	int pIndex;
	string boy;
	string girl;

	ifstream infile;
	infile.open("babynames 2014.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "The file could not be opened." << endl;
		cin.get();
		return -1;
	}
	
	while (infile >> pIndex && infile >> boy && infile >> girl)
	{
		popularityIndex.push_back(pIndex);
		boyNames.push_back(boy);
		girlNames.push_back(girl);

	}
	infile.close();

	int index;
	for (index = 0; index < popularityIndex.size(); index++)
	{
		cout << popularityIndex[index] << " " << boyNames[index] << " " << girlNames[index] << endl;
	}
	ofstream outfile;
	outfile.open("boynames 2014.txt", ios::out);
	if (outfile.is_open())
	{
		for (index = 0; index < popularityIndex.size(); index++)
		{
			outfile << popularityIndex[index] << setw(10) << boyNames[index] << '\n';
		}
		cout << "Data upload successful." << endl;
	}
	outfile.close();

	outfile.open("girlnames 2014.txt", ios::out);
	if (outfile.is_open())
	{
		for (index = 0; index < popularityIndex.size(); index++)
		{
			outfile << popularityIndex[index] << setw(10) << girlNames[index] << '\n';
		}
		cout << "Data upload successful." << endl;
	}
	outfile.close();

	cin.ignore();
	cin.get();
	return 0;
}
