#include <iostream>
#include <string>

using namespace std;

int main()
{
	// candidate info input and assigned variables
	string first_name;
	string last_name;
		cout << "Input first name : " << endl;
		cin >> first_name;
		cout << "Input last name: " << endl;
		cin >> last_name;

	string full_name;
		full_name = first_name + " " + last_name;
		cout << full_name << endl;
		
	int gender;
	cout << "Please enter 1 for male or 2 for female: ";
	cin >> gender;
	if (gender == 1)
	{
		gender = "male";
	}
	else (gender == 2);
	{
		gender = "female";
	}


	cout << gender << endl;

	string rqual_time;
		int age;
		int h;
		int m;
		double s;
		cout << "Input age: " << endl;
		cin >> age;
		cout << "Input qualifying time in minutes hours seconds: ";
		cin >> h;
		cin >> m;
		cin >> s;
		double qual_time;
		qual_time = (h * 60) + m + (s / 100);
		cout << qual_time << endl;
	
		
	int mbase_time = 185; // male initial qualifying ceiling based on hours+minutes+(seconds/100) to give an integer in the form xx.xx
	int fbase_time = 215; // same as formula for male time
	if (m)
	{
		if (age < 18) 
		{
			cout << "Candidate does not qualify based on age" << endl;
		}
		else if (age > 18 and age < 34)
		{
			if (qual_time < mbase_time)
				cout << full_name << " is a " << age << " " << gender << " " << "with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time)
				cout << full_name << " is a " << age << " " << gender << " " << "with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 35 and age < 39)
		{
			if (qual_time < (mbase_time + 5))
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > (mbase_time + 5))
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 40 and age < 44)
		{
			if (qual_time < mbase_time + 10)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 10)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 45 and age < 49)
		{
			if (qual_time < mbase_time + 15)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 15)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 50 and age < 54)
		{
			if (qual_time < mbase_time + 20)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 20)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 55 and age < 59)
		{
			if (qual_time < mbase_time + 30)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 30)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 60 and age < 64)
		{
			if (qual_time < mbase_time + 35)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 35)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 65 and age < 69)
		{
			if (qual_time < mbase_time + 65)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 65)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 70 and age < 74)
		{
			if (qual_time < mbase_time + 80)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 80)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 75 and age < 79)
		{
			if (qual_time < mbase_time + 95)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 95)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		else if (age > 80)
		{
			if (qual_time < mbase_time + 110)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and qualifies" << endl;
			else if (qual_time > mbase_time + 110)
				cout << full_name << " is a " << age << gender << " with time (" << h << ":" << m << ":" << s << ") and does not qualify" << endl;
		}
		
	}

	
	return 0;



	


	

}