#include <iostream>
#include <string>
#include <math.h>
#include <arithmetic.h>


/* Basic calculator sourced from Jumping Into C++ By Alex Allain
Modified by Tyler Miller, 02July2019*/

using namespace std;

extern double b, t, s;

int main()
{
	string user_first_name;

	cout << "Please enter your first name: ";
	cin >> user_first_name;
	cout << "Welcome " << user_first_name << endl;

	int x;
	int y;
	int z;
	cout << "Please enter the length of a rectangle in inches" << endl;
	cin >> x;
	cout << "Please enter the width of a rectangle in inches" << endl;
	cin >> y;
	cout << "Please enter the width of a rectangular floor in feet" << endl;
	cin >> z;
	cout << "The dimensions of your rectangle are " << x << " inches by " << y << " inches" << endl;
	cout << "The area of your rectangle is " << x * y << endl;
	cout << "The perimeter of your rectangle is " << x + y + x + y << endl;
	
	int c;
	int b;
	c = (x * x) + (y * y);
	b = sqrt(c);

	cout << "The diagonal of your rectangle is " << b << endl;

	int t;
	int s;
	s = x * 25.4;
	t = y * 25.4;

	cout << "The length of your rectangle in millimeters is " << s << endl;
	cout << "The width of you rectangle in millimeters is " << t << endl;
		 
	cin.ignore();
	cin.get();
	return 0;

}