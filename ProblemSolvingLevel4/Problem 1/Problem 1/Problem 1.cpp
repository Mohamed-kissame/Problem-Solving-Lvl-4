#include <iostream>
#include <string>

using namespace std;

int ReadNumber() {

	int Number = 0;

	cout << "Enter a Number ?";
	cin >> Number;

	return Number;
}

string NumberToText(int Number) {

	string Results;

	string ones[] = { "" , "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Teen" };
	string Teens[] = { "","Eleven","Twelve","Thirteen","Fourteen","Fifteen","SiwTeen","Seventeen","Eighteen","Ninteen" };

	if (Number >= 11 && Number <= 19) {

		Results = Teens[Number - 10];
	}

	if (Number >= 20 && Number <= 99) {

		int TensPlace = Number / 10;
		int OnesPlace = Number % 10;

		Results = Teens[TensPlace];

		if (OnesPlace > 0) {

			Results += " " + ones[OnesPlace];
		}
	}
	if (Number >= 100 && Number <= 999) {

		int HundredsPlaces = Number / 100;
		int Remainders = Number % 100;

		Results = ones[HundredsPlaces] + "Hundred";

		if (Remainders > 0) {

			Results += " " + NumberToText(Remainders);
		}
	}

	if (Number >= 1000 && Number <= 999999) {

		int ThousandsPlaces = Number / 1000;
		int Remainders = Number % 1000;

		Results = NumberToText(ThousandsPlaces) + "Thousand";

		if (Remainders > 0) {

			Results += " " + NumberToText(Remainders);
		}
	}

	return Results;
}

int main() {

	int Number = ReadNumber();

	cout << NumberToText(Number);

	system("pause>0");
	return 0;
}