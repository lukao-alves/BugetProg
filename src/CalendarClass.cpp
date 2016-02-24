/*
 *	CalendarClass.cpp
 *
 *	Created on: Dec 8, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <iostream>
#include <iomanip>

#include "include/CalendarClass.h"

using std::cout;
using std::cerr;
using std::endl;
using std::setw;

/*  Default Class Constructor */
CalendarClass::CalendarClass() {
	setYear(2015);
	setMonth(1);
	setDay(1);
}

/* Class Constructor witch exact values */
CalendarClass::CalendarClass(uint32 year, uint16 month, uint16 day) {
	setYear(year);
	setMonth(month);
	setDay(day);
}

/*  Class Destructor */
CalendarClass::~CalendarClass() {
	delete &day;
	delete &month;
	delete &year;
}

/* Get Day from Calendar Class */
uint16 CalendarClass::getDay(void) {
	return this->day;
}

/* Set Day to Calendar Class */
void CalendarClass::setDay(uint16 day) {
	if(day <= numOfDaysInMonth(month, isLeap(year)))
		this->day = day;
	else
		throw "Invalid Day! Number of days in this month is incorrect!";
}

/* Get Month from Calendar Class */
uint16 CalendarClass::getMonth(void) {
	return this->month;
}

/* Set Month to Calendar Class */
void CalendarClass::setMonth(uint16 month) {
	if (month >= 0 && month <= 12)
		this->month = month;
	else
		throw "Invalid Month! Incorrect month!";
}

/* Get Year from Calendar Class */
uint32 CalendarClass::getYear(void) {
	return this->year;
}

/* Set Year to Calendar Class */
void CalendarClass::setYear(uint32 year)  {
	if(year > 1752)
		this->year = year;
	else
		throw "Invalid Year! The should be higher than 1752!";
}

/* Print at console the Calendar of a certain month of a year */
void CalendarClass::showCalendar(uint32 year, uint16 month) {
	bool leap;
	uint16 numDays;
	uint8 dayOfWeek;

	leap = isLeap(year);
	numDays = numOfDaysInMonth(month, leap);
	dayOfWeek = getDayOfWeek(year, month, 1);

	printMonthHeader(month);
	printDays(numDays, dayOfWeek);
}

/*  Verify if the year correspond to a Leap Year */
bool CalendarClass::isLeap(uint32 year) {
	// If year is divisible by 4
	if ((year % 4) == 0) {
		// If year divisible by 4 and divisible by 100
		if((year % 100) == 0) {
			// If year divisible by 4, divisible by 100 and divisible by 400
			if((year % 400) == 0) {
				// It's a Leap Year
				return true;
			}
		}
		// If year is divisible by 4 and not divisible by 100
		else
			// It's a Leap Year
			return true;
	}
	// Otherwise it's not a Leap Year
	return false;
}

/* Gets the number of days from a certain year */
uint16 CalendarClass::numOfDaysInMonth(uint16 month, bool leapYear) {
	if(month == 1)
		return(31);			// January has 31 days
	else if(month == 2)
		if(leapYear)
			return (29);	// February has 29 days in a Leap Year
		else
			return (28);	// February has 28 days in a non Leap Year
	else if(month == 3)
		return (31);		// March has 31 days
	else if(month == 4)
		return (30);		// April has 30 days
	else if(month == 5)
		return (31);		// May has 31 days
	else if(month == 6)
		return (30);		// June has 30 days
	else if(month == 7)
		return (31);		// July has 31 days
	else if(month == 8)
		return (31);		// August has 31 days
	else if(month == 9)
		return (30);		// September has 30 days
	else if(month == 10)
		return (31);		// October has 31 days
	else if(month == 11)
		return (30);		// November has 30 days
	else if(month == 12)
		return (31);		// December has 31 days
	else
		return 0;			// Otherwise return a non valid number of days
}

/* Get the Day of the Week of any Date
 *
 * Copied from Wikipedia */
uint8 CalendarClass::getDayOfWeek(uint32 year, uint16 month, uint16 day) {
	static uint8 table[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	year -= month < 3;
	return ((year + year/4 - year/100 + year/400 + table[month-1] + day) % 7);
}

/* Print at console the Month Header */
void CalendarClass::printMonthHeader(uint16 month) {
	if(month == 1)
		cout << "January" << endl;
	else if (month == 2)
		cout << "February" << endl;
	else if (month == 3)
		cout << "March" << endl;
	else if (month == 4)
		cout << "April" << endl;
	else if (month == 5)
		cout << "May" << endl;
	else if (month == 6)
		cout << "June" << endl;
	else if (month == 7)
		cout << "July" << endl;
	else if (month == 8)
		cout << "August" << endl;
	else if (month == 9)
		cout << "September" << endl;
	else if (month == 10)
		cout << "October" << endl;
	else if (month == 11)
		cout << "November" << endl;
	else if (month == 12)
		cout << "December" << endl;

	// Print Days of Week Header
	cout << " S  M  T  W  T  F  S" << endl;
	cout << "____________________" << endl;
}

/* Point the console to the exact week day of a calendar */
void CalendarClass::skipToWeekDay(uint8 dayOfWeek) {
	dayOfWeek = dayOfWeek * 3;
	while(dayOfWeek > 0) {
		cout << " ";
		dayOfWeek--;
	}
}

/* Print at console the days of a month */
void CalendarClass::printDays(uint16 numDays, uint8 dayOfWeek) {
	uint16 day = 1;

	skipToWeekDay(dayOfWeek);
	while (day <= numDays) {
		cout << std::setw(2) << day << " ";
		if(dayOfWeek == 6) {
			cout << endl;
			dayOfWeek = 0;
		}
		else
			dayOfWeek++;
		day++;
	}

	cout << endl;
}
