#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Please Enter a Year to Check ?";
	cin >> Year;

	return Year;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease Enter a Month to Check ?";
	cin >> Month;

	return Month;
}

bool IsLeapYearOrNot(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

	return (Month < 1 || Month > 12) ? 0 : (Month == 2) ? (IsLeapYearOrNot(Year) ? 29 : 28) : 
		(Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

int main() {

	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of days in Month [" << Month << "] is " 
		<< NumberOfDaysInMonth(Month, Year) << endl;

	system("pause>0");
}