#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};

/**
    Checks if the given year is a leap year based on the calendar reform (https://en.wikipedia.org/wiki/Calendar_reform).
    Dates before the year 1582 are invalid.
    @params year: int
    @returns 1, true; 0, false; -1, year is invalid
*/
int is_leapyear(int year);

/**
    Validates the given date. Dates before 01/01/1582 and after 12/31/2400 are invalid.
    @params date: struct
    @returns 1, valid; 0, invalid
*/
int exists_date(struct date);

/**
    Returns days of the given month (including leap years).
    @params month: int; year: int
    @returns days in month
*/
int get_days_for_month(int month, int year);

/**
    Calculates the day of the year from 01/01. Leap years are included.
    @params date: struct
    @returns count of days passed in the year; -1, date invalid
*/
int day_of_the_year(struct date);


/**
    Formats the user input into a date struct. Will repeat until input is a valid date.
    @params day: int; month: int; year: int
    @returns date: struct
*/
struct date input_date();

#endif // TIMELIB_H_INCLUDED
