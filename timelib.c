/**
 * \author Jonas Peterburs
 * \date 14.01.2020
 */
#include <stdio.h>
#include <stdlib.h>

#define DATE_ERROR "\nERROR : date invalid.\n\n"


/** \brief Checks if year is a leap year.
 *
 * \param year int
 * \return int
 *
 */
int is_leapyear(int year)
{
    if (year < 1582)
        return -1;
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
 * \param day int
 * \param month int
 * \param year int
 * \return int
 *
 */
int exists_date(int day, int month, int year)
{
    if (day < 1 || month < 1 || year < 1582 || day > 31 || month > 12 || year > 2400)
    {
        return 0;
        printf(DATE_ERROR);
    }
    else if (month = 2 && day > 29)
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
 * \param day int
 * \param month int
 * \param year int
 * \return int
 *
 */
int day_of_the_year(int day, int month, int year)
{
    int totalDays = 0;
    int i;

    if (exists_date(day, month, year) == 0)
    {
        return -1;
    }

    for (i = 1; i < month; i++)
    {
        totalDays += get_days_for_month(i, year);
    }

    totalDays += day;

    return totalDays;
}

/** \brief Reads user date input.
 *
 * \param day int*
 * \param month int*
 * \param year int*
 * \return void
 *
 */
void input_date(int *day, int *month, int *year)
{
    printf("Calculation for day of the year.\n");

    do
    {
        // reset Pointers
        *day = 0, *month = 0, *year = 0;

        printf("Day: ");
        scanf("%i", day);
        fflush(stdin);

        printf("Month: ");
        scanf("%i", month);
        fflush(stdin);

        printf("Year: ");
        scanf("%i", year);
        fflush(stdin);

        if (exists_date(*day, *month, *year) != 1)
        {
            printf(DATE_ERROR);
        }
        else
        {
            printf("\n");
        }
    }
    while (exists_date(*day, *month, *year) != 1);
}
