/**
 * \author Jonas Peterburs
 * \date 14.01.2020
 */
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

#define LAST_YEAR_OF_USAGE 2400

#define DATE_ERROR "\nERROR : date invalid.\n\n"


/** \brief Checks if year is a leap year.
 *
 * \param year int
 * \return int
 *
 */
int is_leapyear(int year)
{
    // Leap year calculation based of: https://en.wikipedia.org/wiki/Calendar_reform
    if (year < 1582)
    {
        return -1;
    }
    // year must be divisible by 4 and 400 or not by 100
    else if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/** \brief Validates given date.
 *
 * \param current_date struct
 * \return int
 *
 */
int exists_date(struct date current_date)
{
    if (
        current_date.day < 1 || current_date.day > 31 ||
        current_date.month < 1 || current_date.month > 12 ||
        current_date.year < 1582 || current_date.year > LAST_YEAR_OF_USAGE
        )
    {
        return 0;
        printf(DATE_ERROR);
    }
    else if (current_date.month = 2 && current_date.day > 29)
    {
        return 0;
        printf(DATE_ERROR);
    }
    else
    {
        return 1;
    }
}

/** \brief Gets days of the given month.
 *
 * \param month int
 * \param year int
 * \return int
 *
 */
int get_days_for_month(int month, int year)
{
    int daysInYear[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

    if (month < 1 || month > 12)
    {
        printf(DATE_ERROR);
        return -1;
    }

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

/** \brief Calculation for the day of the year.
 *
 * \param current_date struct
 * \return int
 *
 */
int day_of_the_year(struct date current_date)
{
    int totalDays = 0;
    int i;

    if (exists_date(current_date) == 0)
    {
        return -1;
    }

    for (i = 1; i < current_date.month; i++)
    {
        totalDays += get_days_for_month(i, current_date.year);
    }

    totalDays += current_date.day;

    return totalDays;
}

/** \brief Reads user date input.
 *
 * \return current_date struct
 *
 */
struct date input_date()
{
    struct date current_date;

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
