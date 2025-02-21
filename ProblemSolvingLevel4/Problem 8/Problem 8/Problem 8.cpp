#include <iostream>

using namespace std;

bool IsLeapYearOrNot(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short DaY, short Month, short Year) {

	short a, m, y;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (DaY + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfMonth) {

	string arrNameDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

	return arrNameDays[DayOfMonth];
}

short ReadYear() {

	short Year = 0;

	cout << "Please enter a year ?";
	cin >> Year;
	return Year;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease enter a Month ? ";
	cin >> Month;

	return Month;
}

short NumberOfDaysInMonth(short Month, short Year) {

	return (Month < 1 || Month > 12) ? 0 : (Month == 2) ? (IsLeapYearOrNot(Year) ? 29 : 28) :
		(Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

string MonthShortName(short MonthNumber) {

	string Month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	return Month[MonthNumber - 1];
}

void PrintMonthCalenar(short Month, short Year ) {

	int currentDayOfWeek = DayOfWeekOrder(1, Month, Year);;

	int NumberOfDays = NumberOfDaysInMonth(Month, Year);

	printf("\n__________________________%s______________________\n\n",MonthShortName(Month).c_str());

	printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

	
	int i ;
	for (i = 0 ; i < currentDayOfWeek; i++) 

		printf("      ");

		for (int j = 1; j <= NumberOfDays ;j++) {

			printf("%5d", j);

			if (++i == 7) {

				i = 0;

				printf("\n");
			}

		}
	printf("\n____________________________________________________");

}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();

	
	PrintMonthCalenar(Month,Year);

	system("pause>0");

	return 0;
}