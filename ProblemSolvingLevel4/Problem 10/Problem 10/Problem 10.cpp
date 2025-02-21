#include <iostream>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDayInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;
	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {

	short TotalDays = 0;

	for (int i = 1; i <= Month - 1;i++) {

		TotalDays += NumberOfDayInMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

short ReadYear() {

	short Year = 0;

	cout << "\nNPlease enter a year ? ";
	cin >> Year;

	return Year;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease enter a Month ? ";
	cin >> Month;

	return Month;
}

short ReadDay() {

	short Day = 0;

	cout << "Please enter a Day ? ";
	cin >> Day;

	return Day;
}

int main() {

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of days from the begining of the year is "
		<< NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	system("pause>0");
	return 0;
}


