#include <iostream>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfdayInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : day[Month - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year) {

	short a, m, y;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short MonthNumber) {

	string Month[12] = { "Jan","Frb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	return (Month[MonthNumber - 1]);
}

void PrintMonthCalnedar(short Month, short Year) {

	int NumberOfDay;

	int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDay = NumberOfdayInMonth(Month, Year);

	printf("\n_________________________%s___________________________\n\n", MonthShortName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;

	for (i = 0; i < current; i++)

		printf("     ");

	for (int j = 1; j <= NumberOfDay; j++) {

		printf("%5d", j);

		if (++i == 7) {

			i = 0;

			printf("\n");
		}
	}

	printf("\n_______________________________________________________\n");
}

void PrintYearCalnder(int Year) {

	printf("\n________________________________________________________\n\n");

	printf("                 Calendar - %d\n", Year);

	printf("________________________________________________________\n");

	for (int i = 1; i <= 12; i++) {

		PrintMonthCalnedar(i, Year);

		cout << endl;
	}

	return;
}

short ReadYear() {

	short Year = 0;

	cout << "Please enter a year ? ";
	cin >> Year;

	return Year;
}

int main() {

	PrintYearCalnder(ReadYear());

	system("pause>0");
}
