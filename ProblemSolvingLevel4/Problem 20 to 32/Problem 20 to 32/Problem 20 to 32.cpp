#include <iostream>
#include "ReadDateLib.h"

using namespace std;
using namespace ReaddateLib;

struct stDate {

	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year) {

	return  (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMont(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	int Days[12] = { 31, 28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
} 

bool IsLastDayInYear(stDate Date) {

	return (Date.Day == NumberOfDaysInMont(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);
}

stDate IncreasDateByOneDay(stDate Date) {

	if (IsLastDayInYear(Date)) {

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

stDate IncreaDateByXDays(stDate Date ,short Day) {


	for (short i = 1; i <= Day; i++) {

	 Date = IncreasDateByOneDay(Date);
    
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {


	for (short i = 1; i <= 7; i++) {

		Date = IncreasDateByOneDay(Date);
		
	}

	return Date;
}

stDate IncreaseDateByXWeeek(stDate date, short Week) {


	for (short i = 1; i <= Week ; i++) {

		date = IncreaseDateByOneWeek(date);
		
	}

	return date;

}

stDate IncreaseDateByOneMonth(stDate Date) {

	short CurrentDay = Date.Day;
	
	if (Date.Month < 12) {

		Date.Month++;
	}
	else {

		if (Date.Month == 12) {

			Date.Year++;
		}
	}

	short MaxDays = NumberOfDaysInMont(Date.Month, Date.Year);

	if (CurrentDay > MaxDays) {

		Date.Day = MaxDays;
	}
	else {

		Date.Day = CurrentDay;
	}

	return Date;
}

stDate IncreaseDateByXMonth(stDate Date, short XMonth) {

	for (short i = 0; i < XMonth; i++) {

		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {

	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYear(stDate Date, short XYear) {

	for (short i = 0; i < XYear;i++) {

		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreasedateByXYearFaster(short Year, stDate Date) {

	Date.Year += Year;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {

	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecade(stDate Date, short Decade) {

	for (int i = 1; i <= Decade * 10 ; i++) {

		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByDecadesFaster(short Decade, stDate Date) {

	Date.Year += Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {

	Date.Year += 100;

	return Date;
}

stDate IncreaseByOneMillenniem(stDate Date) {

	Date.Year += 1000;
	return Date;
}

stDate ReadFullDate() {

	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main() {

	stDate Date = ReadFullDate();

	cout << "\nDate After :\n\n";

	Date = IncreasDateByOneDay(Date);
	cout << "01-Adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaDateByXDays(Date,10);
	cout << "02-Adding 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding one Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXWeeek(Date,10);
	cout << "04-Adding 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXMonth(Date, 5);
	cout << "06-Adding 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneYear(Date);
	cout << "07-Adding One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYear(Date, 10);
	cout << "08-Adding 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasedateByXYearFaster(10,Date);
	cout << "09-Adding 10 Years (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecade(Date,10);
	cout << "11-Adding 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByDecadesFaster(10,Date);
	cout << "12-Adding 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneCentury(Date);
	cout << "13-Adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseByOneMillenniem(Date);
	cout << "14-Adding One Millenniem is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	
	system("pause>0");
	return 0;
}
