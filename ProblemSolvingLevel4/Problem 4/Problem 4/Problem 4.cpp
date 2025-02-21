#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Please enter a year to check ?";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year){

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOFDaysInAYear(short Year) {

	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year) {

	return NumberOFDaysInAYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year) {

	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondesInYear(short Year) {

	return NumberOfMinutesInYear(Year) * 60;
}

void PrintResultsOfDay_Min_Sec() {

	 short Year = ReadYear();

	cout << "\nNumber of days    in Year [" << Year << "] is "
	 	<< NumberOFDaysInAYear(Year);

	cout << "\nNumber of hours   in Year [" << Year << "] is "
		 << NumberOfHoursInYear(Year);

    cout << "\nNumber of Minutes in Year [" << Year << "] is "
		<< NumberOfMinutesInYear(Year);

	cout << "\nNumber of Secondes in Year [" << Year << "] is "
		<< NumberOfSecondesInYear(Year);
}


int main() {

	
	PrintResultsOfDay_Min_Sec();
	system("pause>0");
	return 0;
}