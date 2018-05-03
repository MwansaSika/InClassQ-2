#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
	int day;
	static int MnthDays[];
	static string MnthName[];
public:
	int getDay()
	{
		return day;
	}
	void operator++(int);
	DayOfYear operator--(int);
	DayOfYear() {}
	DayOfYear(int day)
	{
		this->day = day;
	}
	DayOfYear(string month, int date)
	{
		int i;
		for (i = 0; i < 12; i++)
		{
			if (MnthName[i] == month)
				break;
		}
		day = MnthDays[i] + date;
	}
	void print();
};
int DayOfYear::MnthDays[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
string DayOfYear::MnthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


// This helps show the month and day
// with the value inputed*
void DayOfYear::operator++(int)
{
	this->day = (this->day % 365 + 1);
}
DayOfYear DayOfYear::operator--(int)
{
	if (day == 1)
		day = 365;
	else
		day = day - 1;
	return DayOfYear(day);
}

void DayOfYear::print()
{
	int month = 0;

	while (MnthDays[month] < day)
		month = (month + 1) % 12;

	//Display month and day
	cout << MnthName[month] << " ";
	if (month == 0)
		cout << day << endl;
	else
		cout << day - MnthDays[month - 1] << endl;
}


int main()
{

	//Used array to set months
	//Loop using a switch
	char f;
	do {
		cout << "1. Day till Date\n2. Date till Day\n";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{int day;
		//display to person the total day number
		cout << "\nPlease input a number you would like to change into a month and day";
		cin >> day;
		DayOfYear dYear(day);
		//Do if and if it does not match condition get to else
		if (day <= 0 || day > 365)
		{
			cout << "You need to input a valid number (1 thru 365)" << endl;
		}
		else
			dYear.print();
		dYear++;
		cout << "After ++" << endl;
		dYear.print();
		cout << "After --" << endl;
		dYear--;
		dYear.print();
		}
		break;
		case 2:
		{string month; int date;
		cout << "\nEnter the month:" << endl;
		cin >> month;
		cout << "\nEnter the date:" << endl;
		cin >> date;
		DayOfYear dYear1(month, date);
		cout << "Day:" << dYear1.getDay() << endl; }
		break;
		}
		cout << "\nDo you wish to continue(y/n)?" << endl;
		cin >> f;
	} while (f == 'y' || f == 'Y');

	system("pause");
	return 0;

}