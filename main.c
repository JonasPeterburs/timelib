/* *
 * Schreiben Sie ein Programm, welches nach Eingabe des aktuellen Datums berechnet,
 * der wievielte Tag in diesem Jahr es ist.
 *
 * int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 *
 * Eingabegrößen: Tag, Monat, Jahr
 * Ausgabegrößen: Nummer des Tages
 *
 * Hinweis: Es soll bei Eingabe überprüft werden, ob der eingegebene Tag existiert.
 * Schaltjahre soll ebenfalls berücksichtigt werden!
 *
 * Author: Jonas Peterburs
 * Datum: 14.01.2020
 * */
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    int day, month, year;

    input_date(&day, &month, &year);

    printf("%i.%i.%i --> %i", day, month, year, day_of_the_year(day, month, year));
    return 0;
}
