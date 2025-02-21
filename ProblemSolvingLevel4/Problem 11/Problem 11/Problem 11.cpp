#include <iostream>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

short NumberOfDaysFromTheBeginigOfTheYear(short Day, short Month, short Year) {

	short TotalDays = 0;

	for (int i = 0; i <= Month - 1;i++) {

		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

struct sDate {

	short Year;
	short Month;
	short Day;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {

	sDate Date;

	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{

		MonthDays = NumberOfDaysInMonth(Date.Month, Year);

		if(RemainingDays > MonthDays){
		 
			RemainingDays -= MonthDays;
			Date.Month++;

		}
		else {

			Date.Day = RemainingDays;
			break;
		}

	}

	return Date;
}

short ReadDay() {

	short Day = 0;

	cout << "Please Enter a Day ? ";
	cin >> Day;

	return Day;
}
short ReadMonth() {

	short Month = 0;

	cout << "\nPlease Enter a Month ? ";
	cin >> Month;

	return Month;
}
short ReadYear() {

	short Year = 0;

	cout << "\nPlease Enter a Year ? ";
	cin >> Year;

	return Year;
}

int main() {

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DayOrderInYear = NumberOfDaysFromTheBeginigOfTheYear(Day, Month, Year);

	cout << "\nNumber of Days from the begining of the year is " << DayOrderInYear << "\n" << "\n";

	sDate Date;

	Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);

	cout << "Date for [" << DayOrderInYear << "] is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}