#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

struct stdate {

	short day;
	short Month;
	short Year;
};

bool isLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1Befordate2(stdate date1, stdate date2) {

	return (date1.Year < date2.Year) ? true : 
		((date1.Year == date2.Year) ? 
			(date1.Month < date2.Month ?
				true : (date1.Month == date2.Month 
					? date1.day < date2.day : false)) : false);
}

short NumberOfDayInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInMonth(stdate date) {

	return (date.day == NumberOfDayInMonth(date.Month, date.Year));
}

bool IsLastMonthInYear(short month) {

	return (month == 12);
}

stdate IncreaseDateByOneDay(stdate date) {

	if (IsLastDayInMonth(date)) {

		if (IsLastMonthInYear(date.Month)) {

			date.day = 1;
			date.Month = 1;
			date.Year++;
		}
		else {
			date.day = 1;
			date.Month++;
		}
	}
	else {
		date.day++;
	}

	return date;
}

int GetDeiffernceDay(stdate date1, stdate date2, bool IncludeEndDay = false) {

	int days = 0;

	while (IsDate1Befordate2(date1, date2)) {

		days++;

		date1 = IncreaseDateByOneDay(date1);
	}

	return IncludeEndDay ? ++days : days;
}

short DayOfWeekOrder(short day, short Month, short Year) {

	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return(day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stdate date) {

	return DayOfWeekOrder(date.day, date.Month, date.Year);
}

string DayShortName(short DayOfWeekOrderr) {

	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrderr];
}

short IsEndOfWeek(stdate date) {

	return DayOfWeekOrder(date) == 6;
}

bool IsWeekEnd(stdate date) {

	short dayIndex = DayOfWeekOrder(date);
	return (dayIndex == 5 || dayIndex == 6);
}

bool IsBusinessDay(stdate date) {

	return !IsWeekEnd(date);
}

short daysUntilTheEndOfWeek(stdate date) {

	return 6 - DayOfWeekOrder(date);
}

short DaysUntilTheEndOfMonth(stdate date) {

	stdate EndOfMontDate;
	EndOfMontDate.day = NumberOfDayInMonth(date.Month,
		date.Year);
	EndOfMontDate.Month = date.Month;
	EndOfMontDate.Year = date.Year;
	return GetDeiffernceDay(date, EndOfMontDate, true);

}

short DaysUntilTheEndOfYear(stdate date)
{
	stdate EndOfYearDate;
	EndOfYearDate.day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = date.Year;
	return GetDeiffernceDay(date, EndOfYearDate, true);
}

stdate GetSystemDate() {

	stdate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.day = now->tm_mday;
	return Date;
}

int main()
{
	stdate Date1 = GetSystemDate();
	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1))
		<< " , "
		<< Date1.day << "/" << Date1.Month << "/" << Date1.Year <<
		endl;

	cout << "\nIs it End of Week?\n";
	if (IsEndOfWeek(Date1))
		cout << "Yes it is Saturday, it's of Week.";
	else
		cout << "No it's Not end of week.";

	cout << "\n\nIs it Weekend?\n";
	if (IsWeekEnd(Date1))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " <<
		DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";

	cout << "\n\nIs it Business Day?\n";
	if (IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";

	cout << "\n\nDays until end of week : "
		<< daysUntilTheEndOfWeek(Date1) << " Day(s).";

	cout << "\nDays until end of month : "
		<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";

	cout << "\nDays until end of year : "
		<< DaysUntilTheEndOfYear(Date1) << " Day(s).";

	system("pause>0");
	return 0;
}