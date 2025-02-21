#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate {

	short day;
	short Month;
	short Year;
};

vector <string> SplitString(string date, string Delim) {

	short pos = 0;
	vector <string > vString;
	string sWord;

	while ((pos = date.find(Delim)) != std::string::npos)
	{
		sWord = date.substr(0, pos);

		if (sWord != "") {

			vString.push_back(sWord);
		}

		date.erase(0, pos + Delim.length());

	}

	if (date != "") {

		vString.push_back(date);
	}

	return vString;
}

stDate DateStringToStruct(string dateAsString, string seperator = "/") {

	vector <string> vString = SplitString(dateAsString, seperator);

	stDate Date;

	Date.day = stoi(vString.at(0));
	Date.Month = stoi(vString.at(1));
	Date.Year = stoi(vString.at(2));

	return Date;
}

string DateStructToString(stDate Date) {

	return to_string(Date.day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordInString(string date, string StringToReplace, string sReplaceTo) {

	short pos = date.find(StringToReplace);

	while (pos != std::string::npos) {

		date = date.replace(pos, StringToReplace.length(),sReplaceTo);

		pos = date.find(StringToReplace);
	}

	return date;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";

	FormattedDateString = ReplaceWordInString(DateFormat, "dd",
		to_string(Date.day));

	FormattedDateString = ReplaceWordInString(FormattedDateString,
		"mm", to_string(Date.Month));


	FormattedDateString = ReplaceWordInString(FormattedDateString,
		"yyyy", to_string(Date.Year));

	return FormattedDateString;
}

string ReadStringDate(string Message)
{
	string DateString;

	cout << Message;

	getline(cin >> ws, DateString);

	return DateString;
}

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd / mm / yyyy ? ");
	
	stDate Date = DateStringToStruct(DateString);

	cout << "\n" << FormateDate(Date) << "\n";

	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";

	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";

	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";

	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";

	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";

	system("pause>0");
	return 0;
}
