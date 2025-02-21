#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Please enter a year to check ?";
	cin >> Year;

	return Year;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease enter a Month to check ?";
	cin >> Month;

	return Month;
}

bool IsLeapOrNot(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DaysInFebruary(short Year) {

	return IsLeapOrNot(Year) ? 29 : 28;
}

short NumberOfDaysInMonth(short Year, short Month) {

	return (Month == 2) ? DaysInFebruary(Year) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

short NumberOfHours(short Year, short Month) {

	return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutes(short Year, short Month) {

	return NumberOfHours(Year, Month) * 60;
}

int NumberOfSeconds(short Year, short Month) {

	return NumberOfMinutes(Year, Month) * 60;
}

void PrintResults() {

	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days     in Month [" << Month << "] is "
		<< NumberOfDaysInMonth(Year, Month) << endl;

	cout << "Number Of Hours    in Month [" << Month << "] is "
		<< NumberOfHours(Year, Month) << endl;

	cout << "Number Of Minutes  in Month [" << Month << "] is "
		<< NumberOfMinutes(Year, Month) << endl;

	cout << "Number Of Seconds  in Month [" << Month << "] is "
		<< NumberOfSeconds(Year, Month) << endl;

}

int main() {

	PrintResults();

	system("pause>0");

	return 0;
}