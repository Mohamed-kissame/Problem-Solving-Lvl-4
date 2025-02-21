#include <iostream>

using namespace std;

struct stDate {

	short day;
	short month;
	short year;
};

bool IsDate1BeforDate2(stDate date1, stDate date2) {

	return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool IsDate1EqualDate2(stDate date1, stDate date2) {

	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate date1, stDate date2) {

	return (!IsDate1BeforDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.day = ReadDay();
	Date.month = ReadMonth();
	Date.year = ReadYear();
	return Date;
}

int main()
{
	cout << "\nEnter Date1:";
	stDate Date1 = ReadFullDate();
	cout << "\nEnter Date2:";
	stDate Date2 = ReadFullDate();
	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 is After Date2.";
	else
		cout << "\nNo, Date1 is NOT After Date2.";
	system("pause>0");
	return 0;
}
