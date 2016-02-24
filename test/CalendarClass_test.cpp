/*
 * CalendarClass_test.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: lukao
 */

#include<iostream>

#include "CalendarClass.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

int main(void) {
	CalendarClass* calendar = NULL;
	uint32 year;
	uint16 month;
	uint16 day;

	cout << "What year do you want a calendar for?" << endl;
	cin >> year;
	cout << "What month do you want a calendar for?" << endl;
	cin >> month;
	cout << "What day do you want a calendar for?" << endl;
	cin >> day;

	try {
		calendar = new CalendarClass(year, month, day);
		cout << calendar->getDay() << "/" << calendar->getMonth() << "/" << calendar->getYear() << endl;
		calendar->showCalendar(calendar->getYear(), calendar->getMonth());
	}
	catch(const char* msg) {
		cerr << msg << endl;
	}

	return 0;
}
