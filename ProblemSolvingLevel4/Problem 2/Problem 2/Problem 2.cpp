#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Please Enter A year ?";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year) {

		if ((Year % 4 == 0 && Year % 100 != 0)) {

				return true;
		}
		if (Year % 400 == 0) {

			return true;
		} 
		if ((Year % 100 == 0 && Year % 400 != 0)){

				return false;
		}

		return false;
}

void PrintIsLeapOrNot(short year) {

	if (IsLeapYear(year)) {

		cout << "\nYes, Year [" << year << "] is a leap year.\n";
	}
	else {

		cout << "\nNo, Year [" << year << "] is Not leap year.\n";
	}
}

int main() {

	short Year = ReadYear();

	PrintIsLeapOrNot(Year);

	system("pause>0");

	return 0;
}