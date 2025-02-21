#include <iostream>

using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
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

short NumberOfDaysFromBeginingYear(short Day, short Month, short Year) {

	short TotalDays = 0;

	for (int i = 0; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

sDate DaysToAdd(short Days, sDate Date) {

	short RemainingDays = Days + NumberOfDaysFromBeginingYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays) {

			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12) {
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}


	}

	return Date;

}

short ReadDay() {

	short Day = 0;

	cout << "Please enter a Day ? ";
	cin >> Day;

	return Day;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease enter a Month ? ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year = 0;

	cout << "\nPlease enter a Year ? ";
	cin >> Year;

	return Year;
}

sDate ReadDate() {

	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short ReadDaysToAdd() {

	short DaysToAdd = 0;

	cout << "\nHow Many days you need To add ? ";
	cin >> DaysToAdd;

	return DaysToAdd;
}

int main() {

	sDate Date = ReadDate();
	short Days = ReadDaysToAdd();

	Date = DaysToAdd(Days,Date);
	cout << "\nDate after adding [" << Days << "] days is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}
