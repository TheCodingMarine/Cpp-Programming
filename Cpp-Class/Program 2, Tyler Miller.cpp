#include <iostream>
#include <string>

// Program 2 based upon code from "Jumping into C++" chapters 3 and 4 by Alex Allain, modified by Tyler Miller//

using namespace std;

int main()

{
	// Comparing the area of two rectangles


	string rectangle_measurements;

	cout << "Welcome" << endl;

	cout << "Please input the length and width of rectangles Alpha and Bravo" << endl;

	cout << "Length of rectangle Alpha:" << endl;
	int length_alpha;
	cin >> length_alpha;

	cout << "Width of the rectangle Alpha:" << endl;
	int width_alpha;
	cin >> width_alpha;

	cout << "Length of Bravo:" << endl;
	int length_bravo;
	cin >> length_bravo;

	cout << "Width of Bravo:" << endl;
	int width_bravo;
	cin >> width_bravo;

	int area_alpha, area_bravo;
	area_alpha = (2 * length_alpha) + (2 * width_alpha);
	area_bravo = (2 * length_bravo) + (2 * width_bravo);
	cout << "The Area of Bravo is " << area_bravo << " and the area of Alpha is " << area_alpha << endl;

	string result;

	if (area_alpha != area_bravo)
		result = " not equivalent";
	else
		result = "equivalent";
	cout << "Alpha and Bravo are " << result << endl;


	// pH program code

	cout << "Please enter the pH level of a solution as an integer: " << endl;
	int ph;
	cin >> ph;
	if (ph < 3)
		cout << "The solution is very acidic";
	else if (ph >= 3 && ph < 7)
		cout << "The solution is acidic";
	else if (ph > 7 && ph < 12)
		cout << "The solution is alkaline";
	else if (ph >= 12)
		cout << "The solution is very alkaline";
	else if (ph = 7)
		cout << "The solution is neutral";

	cin.ignore();
	cin.get();
	return 0;
}