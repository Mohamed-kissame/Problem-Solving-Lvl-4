#include <iostream>

using namespace std;

enum enCompareDate
{

	Befor = -1 , Equal = 0 , After = 1

};

struct stDate {

	short Day;
	short Month;
	short Year;
};

struct stPeriod {

	stDate DateStart;
	stDate DateENd;

};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

bool IsLastMonthInYear(short month) {

	return (month == 12);
}

short NumberOfDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInYear(stDate date) {

	return (date.Day == NumberOfDaysInMonth(date.Month, date.Year));
}

stDate IncreaseDateByOneDay(stDate date) {

	if (IsLastDayInYear(date)) {

		if (IsLastMonthInYear(date.Month)) {

			date.Day = 1;
			date.Month = 1;
			date.Year++;
		}
		else {

			date.Day = 1;
			date.Month++;
			
		}
	}
	else {

		date.Day++;
	}

	return date;
}

int GetDiffernceDAte(stDate Date1, stDate Date2 , bool IncludeEndDay = false) {

	int daysCount = 0;

	while (IsDate1BeforeDate2(Date1,Date2))
	{

		daysCount++;

		Date1 = IncreaseDateByOneDay(Date1);

	}

	return IncludeEndDay ? ++daysCount : daysCount;
}

int PeriodLengthInDays(stPeriod period, bool IncludeEndDay = false) {

	return GetDiffernceDAte(period.DateStart, period.DateENd , IncludeEndDay);

}

short ReadDay() {

	short Days = 0;

	cout << "Please Enter a Day ? ";
	cin >> Days;

	return Days;
}

short ReadMonth() {

	short Month = 0;

	cout << "Please Enter a Month ? ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year = 0;

	cout << "Please Enter a Year ? ";
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

stPeriod ReadPeriod() {

	stPeriod Period;

	cout << "Enter Start Date:\n\n";
	Period.DateStart = ReadFullDate();
	cout << "\n\nEnter Start Date:\n\n";
	Period.DateENd = ReadFullDate();

	return Period;
}

int main() {

	stPeriod Period;

	cout << "Enter Period 1 :\n";

	Period = ReadPeriod();

	cout << "\nPeriod Length is : " << PeriodLengthInDays(Period) << endl;
	cout << "Period Length (Including End Date) is : " << PeriodLengthInDays(Period, true);

	system("pause>0");
	return 0;
}