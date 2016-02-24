/*
 *	CalendarClass.h
 *
 *	Created on: Dec 8, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include "BudgetProg.h"

#ifndef CALENDARCLASS_H_
#define CALENDARCLASS_H_

class CalendarClass {
private:
	uint16 day;
	uint16 month;
	uint32 year;
public:
	/* Calendar Class Constructor */
	CalendarClass();
	CalendarClass(uint32 year, uint16 month, uint16 day);

	/* Calendar Class Destructor */
	virtual ~CalendarClass();

	/* Get Calendar Day */
	uint16 getDay(void);

	/* Set Calendar Day */
	void setDay(uint16 day);

	/* Get Calendar Month */
	uint16 getMonth(void);

	/* Set Calendar Month */
	void setMonth(uint16 month);

	/* Get Calendar Year */
	uint32 getYear(void);

	/* Set Calendar Year */
	void setYear(uint32 year);

	/* Show Calendar */
	void showCalendar(uint32 year, uint16 month);

private:
	/* Verify is it`s a Leap Year */
	bool isLeap(uint32 year);

	/* Verify how many days there are in a Month */
	uint16 numOfDaysInMonth(uint16 month, bool leapYear);

	/* Get a number corresponding to a Week Day of a Certain Day of a Month */
	uint8 getDayOfWeek(uint32 year, uint16 month, uint16 day);

	/* Print on console the Month Name */
	void printMonthHeader(uint16 month);

	/* Print space chars on console */
	void skipToWeekDay(uint8 dayOfWeek);

	/* Print on console the Month Days */
	void printDays(uint16 numDays, uint8 dayOfWeek);
};

#endif /* CALENDARCLASS_H_ */
