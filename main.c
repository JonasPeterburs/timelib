#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/** \brief Example usage.
 *
 * \return int
 *
 */
int main()
{
    printf("Calculation of the day of the year.\n\n");

    struct date current_date = input_date();

    printf("%i.%i.%i --> %i\n", current_date.day, current_date.month, current_date.year, day_of_the_year(current_date));
    return 0;
}
