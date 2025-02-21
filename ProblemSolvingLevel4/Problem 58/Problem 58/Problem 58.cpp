#include <iostream>

using namespace std;

enum enCompareDate {

	Befor = -1 , Equal = 0 , After = 1
};

struct stDate {

	short day;
	short month;
	short year;

};

struct Period {

	stDate DateSart;
	stDate DateEnd;
};

bool IsDate1BeforDate2(stDate date1, stDate date2) {

	return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool IsDate1EqualDate2(stDate date1, stDate date2) {

	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) :false;
}

bool IsDate1AfterDate2(stDate date1, stDate date2) {

	return (!IsDate1BeforDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

enCompareDate CompareDate(stDate date1, stDate date2) {

	if (IsDate1BeforDate2(date1, date2))
		return enCompareDate::Befor;
	if (IsDate1EqualDate2(date1, date2))
		return enCompareDate::Equal;

	return enCompareDate::After;
}

bool IsOverlapDate(Period period1, Period period2) {

	if (CompareDate(period2.DateEnd, period1.DateSart) == enCompareDate::Befor ||
		CompareDate(period2.DateSart, period1.DateEnd) == enCompareDate::After) {

		return false;
	} 
	else {
		return true;
	}

}

short ReadDay() {

	short Day = 0;

	cout << "Please enter a Day ? ";
	cin >> Day ;

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

	cout << "Please enter a Year ?";
	cin >> Year;

	return Year;
}

stDate ReadFullDate() {

	stDate date;

	date.day = ReadDay();
	date.month = ReadMonth();
	date.year = ReadYear();

	return date;
}

int main() {

	cout << "Enter Period 1:\n";
	cout << "Enter Start Date:\n\n";

	Period period;

	period.DateSart = ReadFullDate();

	cout << "\n\nEnter End Date:\n\n";

	period.DateEnd = ReadFullDate();

	cout << "\n\nEnter Period 2:\n";
	cout << "Enter Start Date:\n\n";

	Period period2;

	period2.DateSart = ReadFullDate();

	cout << "\n\nEnter End Date:\n\n";

	period2.DateEnd = ReadFullDate();

	if (IsOverlapDate(period, period2)) {

		cout << "\nYes, Periods OverLap";
	}
	else {

		cout << "\nNo, Periods OverLap";

	}

	system("pause>0");

	return 0;
}