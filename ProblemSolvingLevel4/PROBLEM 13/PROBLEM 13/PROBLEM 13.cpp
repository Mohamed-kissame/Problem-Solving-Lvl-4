#include <iostream>

using namespace std;

struct stDate {

	short Day;
	short Month;
	short Year;
};

bool IsDateBeforDate2(stDate Date1 , stDate Date2) {

	return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short ReadDay() {

	short Day = 0;

	cout << "\nPlease enter a day ? ";
	cin >> Day;

	return Day;
}

short ReadMonth() {

	short Month = 0;

	cout << "Please enter a month ? ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year = 0;

	cout << "Please enter a year ? ";
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

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	if (IsDateBeforDate2(Date1, Date2)) {

		cout << "\nYes, Date1 is Less than Date2. ";
	}
	else {

		cout << "\nNo, Date1 is Not Less than Date2. ";
	}
}

int main() {

	PrintResults();

	system("pause>0");
	return 0;
}