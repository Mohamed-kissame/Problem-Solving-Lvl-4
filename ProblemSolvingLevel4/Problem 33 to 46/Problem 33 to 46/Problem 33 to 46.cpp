#include <iostream>

using namespace std;

struct stdate {

	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInMonth(stdate Date) {

	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

stdate DecreaseDateByOneDay(stdate date) {

	if (date.Day == 1) {

		if (date.Month == 1) {

			date.Month = 12;
			date.Day = 31;
			date.Year--;
		}
		else {

			date.Month--;
			date.Day = NumberOfDaysInMonth(date.Month, date.Year);
		}
	}
	else {

		date.Day--;
	}

	return date;
}

stdate DecreaseDatebyXDays(stdate date, short day) {

	for (short i = 1; i <= day; i++) {

		date = DecreaseDateByOneDay(date);
	}

	return date;
}

stdate DecreaseDateByOneWeek(stdate date) {

	for (short i = 1; i <= 7; i++) {

		date = DecreaseDateByOneDay(date);
	}

	return date;
}

stdate DecreaseDateByXWeek(stdate date , short xWeek) {

	for (short i = 1; i <= xWeek; i++) {

		date = DecreaseDateByOneWeek(date);
	}

	return date;
}

stdate DecreaseDateByOneMonth(stdate date) {

	if (date.Month == 1) {

		date.Month = 12;
		date.Year--;
	}
	else {
		
		date.Month--;
	}

	short NumberofDays = NumberOfDaysInMonth(date.Month, date.Year);

	if (date.Day > NumberofDays) {

		date.Day = NumberofDays;
	}

	return date;
}

stdate DecreaseDateByXMonth(stdate date, short Xmonth) {

	for (short i = 1; i <= Xmonth; i++) {

		date = DecreaseDateByOneMonth(date);
	}

	return date;
}

stdate DecreaseDateByOneYear(stdate date) {

	date.Year--;
	return date;
}

stdate DecreaseDateByXYear(stdate date, short XYear) {

	for (short i = 1; i <= XYear; i++) {

		date = DecreaseDateByOneYear(date);
	}

	return date;
}

stdate DecreaseDateByXYearFaster(stdate date, short XYear) {

	date.Year -= XYear;
	return date;
}

stdate DecreaseDateByOneDecade(stdate date) {

	date.Year -= 10;
	return date;
}

stdate DecreaseDateByXDecade(stdate date, short xDecade) {

	for (short i = 1; i <= xDecade;i++) {

		date = DecreaseDateByOneDecade(date);
	}

	return date;
}

stdate DecreaseDateByxDecadeFaster(stdate date , short xDecade) {

	date.Year -= xDecade * 10;
	return date;
}

stdate DecreaseDateByOneCentury(stdate date) {

	date.Year -= 100;
	return date;
}

stdate DecreaseDateByOneMillennium(stdate date) {

	date.Year -= 1000;
	return date;
}

short ReadDay() {

	short Day = 0;

	cout << "Please enter a Day ?";
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

stdate ReadFullDate() {

	stdate date;

	date.Day = ReadDay();
	date.Month = ReadMonth();
	date.Year = ReadYear();

	return date;
}


int main() {

	stdate Date = ReadFullDate();

	cout << "\nDate After:\n\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "01-Substracting one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDatebyXDays(Date, 10);
	cout << "02-Substracting 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Substracting one Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByXWeek(Date, 10);
	cout << "04-Substracting 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Substracting one Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByXMonth(Date, 5);
	cout << "06-Substracting 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByOneYear(Date);
	cout << "07-Substracting one Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByXYear(Date, 10);
	cout << "08-Substracting 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByXYearFaster(Date, 10);
	cout << "09-Substracting 10 Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByOneDecade(Date);
	cout << "10-Substracting one Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByXDecade(Date, 10);
	cout << "11-Substracting 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByxDecadeFaster(Date, 10);
	cout << "12-Substracting 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByOneCentury(Date);
	cout << "13-Substracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = DecreaseDateByOneMillennium(Date);
	cout << "14-Substracting One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	system("pause>0");
}