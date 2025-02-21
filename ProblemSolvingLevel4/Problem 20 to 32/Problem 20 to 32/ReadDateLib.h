#pragma once

#include <iostream>
#include <string>

using namespace std;


namespace ReaddateLib {


	short ReadDay() {

		short Day = 0;

		cout << "Please enter a Day ? ";
		cin >> Day;

		return Day;
	}

	short ReadMonth() {

		short Month = 0;

		cout << "Please enter a Month ? ";
		cin >> Month;

		return Month;
	}

	short ReadYear() {

		short Year = 0;

		cout << "Please enter a Year ? ";
		cin >> Year;

		return Year;
	}
	
}