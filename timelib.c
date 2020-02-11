#include <stdio.h>
#include <stdlib.h>

#define DATE_ERROR "\nERROR : Datum ungültig.\n\n"

/* *
 * Beschreibung:
 * Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag,
 * Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an.
 * Schaltjahre werden bei der Berechnung berücksichtigt.
 * Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 *
 * Rückgabewert:
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
 * Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr.
 * Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 *
 * Rückgabewert:
 * kein Rückgabewert
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
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des
 * gregorianischen Kalender ein Schaltjahr ist.
 * Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 *
 * Rückgabewert:
 * 1, wenn übergebenes Jahr ein Schaltjahr ist
 * 0, wenn übergebenes Jahr kein Schaltjahr ist
 * -1, wenn ein ungültiges Jahr übergeben wurde
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
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres,
 * wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen.
 * Schaltjahre werden berücksichtigt.
 *
 * Rückgabewert:
 * Anzahl von Tagen: int, 1-31, wenn ein gültiger Monar eingegeben wurde
 * -1, wenn ein ungültiger Monat oder Jahr übergeben wurde
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
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist.
 * Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400.
 *
 * Rückgabewert:
 * 1, wenn das übergebene Datum gültig ist
 * 0, wenn das Datum nicht gültig ist
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
