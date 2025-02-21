#include <iostream>

using namespace std;

struct stDate {

	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDayInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOfDayInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

short ReadDay() {

	short Day = 0;

	cout << "Please enter a Day ? ";
	cin >> Day;

	return Day;
}

short ReadMonth() {

	short Month = 0;

	cout << "Please enter a Month ? ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year = 0;

	cout << "Please enter a Year ? ";
	cin >> Year;

	return Year;
}

stDate ReadFullDate() {

	stDate Date; 
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

void PrintResults() {

	stDate Date = ReadFullDate();

	if (IsLastDayInMonth(Date)) {
		cout << "\nYes, Day is Last Day in Month.";
	}
	else
	{
		cout << "\nNo, Day is Not Last Day in Month.";
	}

	if (IsLastMonthInYear(Date.Month)) {

		cout << "\nYes, is the Last Month in Year.";
	}

	else {
		cout << "\nNo, is Not the Last Month in Year.";
	}
}

int main() {

	PrintResults();
	system("pause>0");
	return 0;
}