#include "timelib.h"
#include <stdio.h>

/** \brief Example usage.
 *
 * \return int
 *
 */
int main()
{
    int day, month, year;

    printf("Calculation of the day of the year.\n\n");

    input_date(&day, &month, &year);

    printf("%i.%i.%i --> %i\n", day, month, year, day_of_the_year(day, month, year));
    return 0;
}
