#include <iostream>

using namespace std;

struct stDate {

	short Day;
	short Month;
	short Year;
};

bool Date1EqualDate2(stDate Date1, stDate Date2) {

	return (Date1.Year == Date2.Year) ? Date1.Month == Date2.Month ? Date1.Day == Date2.Day : true : false;
}

short ReadDay() {

	short Day = 0;

	cout << "\nPlease enter a Day ? ";
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

	cout << "Please eneter a Year ? ";
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

	if (Date1EqualDate2(Date1, Date2)) {

		cout << "\nYes, Date1 is Equal Date2.";
	}
	else {

		cout << "\nNo, Date1 is Not Equal Date2.";
	}
}

int main() {

	PrintResults();

	system("pause>0");

	return 0;
}