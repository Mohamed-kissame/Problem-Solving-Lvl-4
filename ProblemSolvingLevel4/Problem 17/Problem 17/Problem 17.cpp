#include <iostream>

using namespace std;

struct stDate {

	short Day;
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

short ToTalNumberOfDayFromBeginingYear(short Day, short Month, short Year) {

	short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

bool IsDate1BeforDate2(stDate Date1, stDate Date) {

	return (Date1.Year < Date.Year) ? true : ((Date1.Year == Date.Year) ? (Date1.Month < Date.Month ? true : (Date1.Month == Date.Month ? Date1.Day < Date.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {

	if (IsLastDayInMonth(Date)) {

		if (IsLastMonthInYear(Date.Month)) {

			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Day = 1;
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}

	return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeENdDay = false) {

	int Days = 0;

	while (IsDate1BeforDate2(Date1, Date2)) {

		Days++;

		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeENdDay ? ++Days : Days;

}

short ReadDaY() {

	short Day = 0;

	cout << "\nPlease enter a day ? ";
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

	cout << "Please enter a Year ? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate() {

	stDate Date;

	Date.Day = ReadDaY();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

int main() {

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrence is: "
		<< GetDifferenceInDays(Date1, Date2) << " Day(s).";

	cout << "\nDiffrence (Including End Day) is: "
		<< GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

	system("pause>0");

	return 0;
}