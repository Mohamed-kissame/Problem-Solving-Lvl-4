#include <iostream>

using namespace std;

struct stDate{

	short DAy;
	short Month;
	short Year;
};

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

bool IsLastDayInMonth(stDate date) {

	return (date.DAy == NumberOfDaysInYear(date.Month, date.Year));
}

bool IsValideDate(stDate date) {

	return (date.DAy >= 1 && date.DAy <= NumberOfDaysInYear(date.Month, date.Year));
}

short ReadDay() {

	short day = 0;

	cout << "Please enter a Day ? ";
	cin >> day;

	return day;
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

	Date.DAy = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
int main() {

	stDate Date;
	Date = ReadFullDate();

	if (IsValideDate(Date))

		cout << "\nYes, Date is a Valide date.";
	else
		cout << "\nNo, Date is a Not Valide date.";

	system("pause>0");

	return 0;
	
}