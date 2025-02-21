#include <iostream>

using namespace std;

struct stdate {

	short day;
	short month;
	short year;
};

bool IsLeapYear(short year) {

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool IsDate1BeforDate2(stdate date1, stdate date2) {

	return (date1.year < date2.year) ? true :
		((date1.year == date2.year) ? 
			(date1.month < date2.month ? true : 
				(date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

short NumberOfDaysInMonth(short month, short year) {

	if (month < 1 || month > 12)
		return 0;
	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : Days[month - 1];
}

bool IsLastDayInYear(stdate date) {

	return (date.day == NumberOfDaysInMonth(date.month, date.year));
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

stdate IncreaseDateByOneDay(stdate date) {

	if (IsLastDayInYear(date)) {
		if (IsLastMonthInYear(date.month)) {

			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else {
			date.day = 1;
			date.month++;
		}
	}
	else
	{
		date.day++;
	}

	return date;
}

short DayOfWeekOrder(short day, short month, short year) {

	short a, y, m;

	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;

	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stdate date) {

	return DayOfWeekOrder(date.day, date.month, date.year);
}

string DayShortName(short DayOfWeekorder) {

	string arrDayName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	
	return arrDayName[DayOfWeekorder];
}

bool IsWeekEnd(stdate date) {

	short DayIndex = DayOfWeekOrder(date);

	return (DayIndex == 0 || DayIndex == 6);
}

bool IsBusinessDay(stdate date) {

	return !IsWeekEnd(date);
}

short CalculateVacationDays(stdate dateFrom, stdate dateTo) {

	short DaysCount = 0;

	while (IsDate1BeforDate2(dateFrom, dateTo)) 
	{

		if (!IsBusinessDay(dateFrom)) 

			DaysCount++;
		

		dateFrom = IncreaseDateByOneDay(dateFrom);

	}

	return DaysCount;
}

short ReadDay() {

	short day = 0;

	cout << "\nPlease enter a Day ? ";
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

stdate ReadFullDate() {

	stdate date;

	date.day = ReadDay();
	date.month = ReadMonth();
	date.year = ReadYear();

	return date;
}

int main() {

	cout << "\nVacation Starts: ";
	stdate DateFrom = ReadFullDate();

	cout << "\nVacation Ends: ";
	stdate DateTo = ReadFullDate();

	cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.day << "/" << DateFrom.month << "/" << DateFrom.year << endl;

	cout << "Vacation To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , " << DateTo.day << "/" << DateTo.month << "/" << DateTo.year << endl;


	cout << "\n\nActucal Vaction Days is : " << CalculateVacationDays(DateFrom, DateTo);

	system("pause>0");

	return 0;

}