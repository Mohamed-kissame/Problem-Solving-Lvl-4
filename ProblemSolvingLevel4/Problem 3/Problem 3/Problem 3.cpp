#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Enter Please a Year?";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

void PrintIsleapOrNot() {

	short Year = ReadYear();

	if (IsLeapYear(Year)) {

		cout << "\nYes , Year [" << Year << "] is leap year.\n";
	}
	else {

		cout << "\nNo , Year [" << Year << "] is Not leap year.\n";
	}
}

int main() {

	PrintIsleapOrNot();

	system("pause >0");

	
}