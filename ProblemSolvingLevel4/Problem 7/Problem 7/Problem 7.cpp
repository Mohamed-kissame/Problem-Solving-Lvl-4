#include <iostream>

using namespace std;

short ReadYear() {

	short Year = 0;

	cout << "Please Enter a year ?";
	cin >> Year;

	return Year;
}

short ReadMonth() {

	short Month = 0;

	cout << "\nPlease Enter a Month ?";
	cin >> Month;

	return Month;
}

short ReadDay() {

	short Day = 0;

	cout << "\nPlease Enter a Day ?";
	cin >> Day;

	return Day;
}

short DayOfWeekOrder(short Day, short Month, short Year) {

	short a, y, m;

	 a = (14 - Month) / 12;
	 y = Year - a;
	 m = Month + (12 * a ) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	
}

string DayShortName(short DayOfWeekOrder) {

	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

void PrintResultsCalendar() {

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate    :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay order :" << DayOfWeekOrder(Day, Month, Year) << endl;
	cout << "Day Name  :" << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;
}

int main() {

	PrintResultsCalendar();

	system("pause>0");

	return 0;
}