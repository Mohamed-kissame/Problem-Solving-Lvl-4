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

short NumberOdDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool Date1BeforDate2(stDate Date1, stDate Date2) {

	return (Date1.Year < Date2.Year) ? true : 
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOdDaysInMonth(Date.Month, Date.Year));
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

void SwapDates(stDate& Date1, stDate& Date2) {

	stDate TempDate;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}

int GetDiffereneceInDays(stDate Date1, stDate Date2, bool  IncludeEndDay = false) {

	short NegValue = 1;

	if (!Date1BeforDate2(Date1, Date2)) {

		SwapDates(Date1, Date2);
		NegValue = -1;
	}

	int Days = 0;

	while (Date1BeforDate2(Date1, Date2)) {

		Days++;
		Date1 = IncreaseDateByOneDay(Date1);


	}

	return IncludeEndDay ? ++Days * NegValue : Days * NegValue;
}

short ReadDay() {

	short Day = 0;

	cout << "\nPlease enter a day ?";
	cin >> Day;

	return Day;
}

short ReadMonth() {

	short Month = 0;

	cout << "Please enter a Month ?";
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

	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main() {

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrenece is : " << GetDiffereneceInDays(Date1, Date2) << endl;
	cout << "\nDiffrenece (Include End Day) is : " << GetDiffereneceInDays(Date1, Date2,true) << endl;

}