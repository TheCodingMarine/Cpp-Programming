#include <iostream>
#include <fstream>

using namespace std;

double average(int sum, int num);

int main()
{
	int totalWindSpeed = 0;
	int windSpeed;

	ifstream infile("weatherdata_1.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "File could not be opened." << endl;
		cin.get();
		return -1;
	}
	int count = 0;
	while (infile >> windSpeed)
	{
		totalWindSpeed += windSpeed;
		count++;
	}

	double averageWindSpeed = average(totalWindSpeed, count);

	printf("The total number of entries is %d, the sum of all entries is %d, and the average wind speed is %.2f", count, totalWindSpeed, averageWindSpeed);
	cin.get();
	cin.ignore();
	return 0;

}
double average(int sum, int num) {
	return sum / num;
}