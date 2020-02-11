#include <stdio.h>
#include <stdlib.h>

#define DATE_ERROR "\nERROR : Datum ung�ltig.\n\n"

/* *
 * Beschreibung:
 * Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag,
 * Monat und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an.
 * Schaltjahre werden bei der Berechnung ber�cksichtigt.
 * Ist das �bergebene Datum ung�ltig, betr�gt der R�ckgabewert -1.
 *
 * R�ckgabewert:
 * Nummer des Tages: int
 * */
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

/* *
 * Beschreibung:
 * Die Funktion liest 3 Ganzzahlwerte (Integer) ein, f�r Tag, Monat und Jahr.
 * Wenn das angegebene Datum ung�ltig ist, wird erneut eingelesen, solange bis ein g�ltiges Datum eingegeben wurde.
 *
 * R�ckgabewert:
 * kein R�ckgabewert
 * */
int input_date(int *day, int *month, int *year)
{
    // Eingabe der Werte
    printf("Tool zur berechnung des Tages im Jahr.\n");

    do
    {
	// reset Pointers
	*day = 0, *month = 0, *year = 0;

        printf("Tag: ");
        scanf("%i", day);
        fflush(stdin);

        printf("Monat: ");
        scanf("%i", month);
        fflush(stdin);

        printf("Jahr: ");
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

/* *
 * Beschreibung:
 * Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des
 * gregorianischen Kalender ein Schaltjahr ist.
 * Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
 *
 * R�ckgabewert:
 * 1, wenn �bergebenes Jahr ein Schaltjahr ist
 * 0, wenn �bergebenes Jahr kein Schaltjahr ist
 * -1, wenn ein ung�ltiges Jahr �bergeben wurde
 * */
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

/* *
 * Beschreibung:
 * Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres,
 * wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen.
 * Schaltjahre werden ber�cksichtigt.
 *
 * R�ckgabewert:
 * Anzahl von Tagen: int, 1-31, wenn ein g�ltiger Monar eingegeben wurde
 * -1, wenn ein ung�ltiger Monat oder Jahr �bergeben wurde
 * */
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

/*
 * Beschreibung:
 * Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist.
 * Daten vor dem 1.1.1582 sind ung�ltig, genauso wie alle Daten nach dem 31.12.2400.
 *
 * R�ckgabewert:
 * 1, wenn das �bergebene Datum g�ltig ist
 * 0, wenn das Datum nicht g�ltig ist
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
