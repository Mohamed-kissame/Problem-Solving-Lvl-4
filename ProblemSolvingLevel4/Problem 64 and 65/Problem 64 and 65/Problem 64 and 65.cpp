#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate {

	short day;
	short Month;
	short Year;
};

string ReadADATE() {

	string DateToString;

	cout << "Please Enter Date dd/mm/yyyy? ";
	getline(cin >> ws, DateToString);

	return DateToString;
}

vector <string>  SplitString(string date, string Delim) {

	short pos = 0;
	string sWord = "";

	vector <string> vString;

	while ((pos = date.find(Delim)) != std::string::npos) {

		sWord = date.substr(0, pos);

		if (sWord != "") {

			vString.push_back(sWord);
		}

		date.erase(0,pos + Delim.length());
	}

	if (date != "") {

		vString.push_back(date);
	}

	return vString;
}

stDate ConvertStringToStruct(string date, string seperator = "/") {

	vector <string> vString = SplitString(date, seperator);

	stDate Date;

	Date.day = stoi(vString.at(0));
	Date.Month = stoi(vString.at(1));
	Date.Year = stoi(vString.at(2));

	return Date;
}

string ConvertStructToString(stDate Date) {

	return to_string(Date.day) + "/"
		+ to_string(Date.Month) + "/"
		+ to_string(Date.Year);

	
}

int main() {

	string dateAsString = ReadADATE();

	stDate Date;

	Date = ConvertStringToStruct(dateAsString);

	cout << "\nDay: " << Date.day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year : " << Date.Year;

	cout << "\n\nYou Entered : " << ConvertStructToString(Date);

	system("pause>0");
}