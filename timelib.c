/**
 * \author Jonas Peterburs
 * \date 14.01.2020
 */
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

#define LAST_YEAR_OF_USAGE 2400

#define DATE_ERROR "\nERROR : date invalid.\n\n"


/**
    Checks if the given year is a leap year based on the calendar reform (https://en.wikipedia.org/wiki/Calendar_reform).
    Dates before the year 1582 are invalid.
*/
int is_leapyear(int year)
{
    // calendar reform was founded 1582
    if (year < 1582)
    {
        return -1; // invalid year
    }
    // year must be divisible by 4 and 400 or not by 100
    else if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
    {
        return 1; // is leap year
    }
    else
    {
        return 0; // is not leap year
    }
}


/**
    Validates the given date. Dates before 01/01/1582 and after 12/31/2400 are invalid.
*/
int exists_date(struct date current_date)
{
    if (
        current_date.day < 1 || current_date.day > 31 || // day must be from 1 to 31
        current_date.month < 1 || current_date.month > 12 || // month must be from 1 to 12
        current_date.year < 1582 || current_date.year > LAST_YEAR_OF_USAGE // year must be from 1582 to 2400 (expected end of use)
        )
    {
        printf(DATE_ERROR);
        return 0; // invalid date
    }
    else if (current_date.month == 2 && current_date.day > 29)
    {
        printf(DATE_ERROR);
        return 0; // invalid date
    }
    else
    {
        return 1; // date is valid
    }
}


/**
    Returns days of the given month (including leap years).
*/
int get_days_for_month(int month, int year)
{
    // array of days in a month for an average year.
    int daysInYear[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

    if (month < 1 || month > 12)
    {
        printf(DATE_ERROR);
        return -1; // invalid month
    }

    // if its a leap year, the array will be updated
    if (is_leapyear(year))
    {
        daysInYear[2] = 29;
    }
    else
    {
        daysInYear[2] = 28;
    }

    return daysInYear[month];
}


/**
    Calculates the day of the year from 01/01. Leap years are included.
*/
int day_of_the_year(struct date current_date)
{
    int totalDays = 0;
    int i;

    // date validation
    if (exists_date(current_date) == 0)
    {
        return -1; // date invalid
    }

    // Sum up each month total days but not from the last month
    for (i = 1; i < current_date.month; i++)
    {
        totalDays += get_days_for_month(i, current_date.year);
    }

    // add the days from the current month to the total
    totalDays += current_date.day;

    return totalDays;
}


/**
    Formats the user input into a date struct. Will repeat until input is a valid date.
*/
struct date input_date()
{
    struct date current_date;

    // repeat user input until date is valid
    do
    {
        printf("Please input the date.\n\n");

        printf("Day: ");
        scanf("%i", &current_date.day);
        fflush(stdin);

        printf("Month: ");
        scanf("%i", &current_date.month);
        fflush(stdin);

        printf("Year: ");
        scanf("%i", &current_date.year);
        fflush(stdin);

        if (exists_date(current_date) != 1)
        {
            printf(DATE_ERROR);
        }
        else
        {
            printf("\n");
        }
    }
    while (exists_date(current_date) != 1);

    return current_date;
}
