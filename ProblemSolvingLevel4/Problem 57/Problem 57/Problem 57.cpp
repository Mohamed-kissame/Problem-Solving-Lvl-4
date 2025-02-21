#include <iostream>

using namespace std;

enum enCompareDate {

	Befor = -1 , Equal = 0 , After = 1
};

struct stDate {

	short Day;
	short Month;
	short Year;
};

bool IsDate1BeforDate2(stDate date1, stDate date2) {

	return (date1.Year < date2.Year) ? true : ((date1.Year == date2.Year) ? (date1.Month < date2.Month ? true : (date1.Month == date2.Month ? date1.Day < date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate date1, stDate date2) {

	return (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate date1, stDate date2) {

	return (!IsDate1BeforDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

enCompareDate CompareDate(stDate date1, stDate date2) {

	if (IsDate1BeforDate2(date1, date2))
		return enCompareDate::Befor;

	if (IsDate1EqualDate2(date1, date2))
		return enCompareDate::Equal;

    if (IsDate1AfterDate2(date1, date2))
		return enCompareDate::After;
	
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

	stDate date;

	date.Day = ReadDay();
	date.Month = ReadMonth();
	date.Year = ReadYear();

	return date;
}

int main() {

	cout << "Enter Date1:\n";
	stDate Date1 = ReadFullDate();

	cout << "\n\nEnter Date1:\n";
	stDate Date2 = ReadFullDate();

	cout << "\n\nCompare Results = " << CompareDate(Date1, Date2);

	system("pause>0");

	return 0;
}
