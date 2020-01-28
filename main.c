/*
  Schreiben Sie ein Programm, welches nach Eingabe des aktuellen Datums berechnet,
  der wievielte Tag in diesem Jahr es ist.

  int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  Eingabegrößen: Tag, Monat, Jahr
  Ausgabegrößen: Nummer des Tages

  Hinweis: Es soll bei Eingabe überprüft werden, ob der eingegebene Tag existiert.
  Schaltjahre soll ebenfalls berücksichtigt werden!

  @author Jonas Peterburs
  @date 14-01-2020
*/
#include <stdio.h>
#include <stdlib.h>

int validateDate(int day, int month, int year, int daysInYear[]);
int checkLeapYear(int year);
int sendResult(int day, int month, int year, int daysInYear[]);

int main()
{
    int day, month, year;
    int daysInYear[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

    // Eingabe der Werte
    printf("Tool zur berechnung des Tages im Jahr.\n");

    printf("Tag: ");
    scanf("%i", &day);
    fflush(stdin);

    printf("Monat: ");
    scanf("%i", &month);
    fflush(stdin);

    printf("Jahr: ");
    scanf("%i", &year);
    fflush(stdin);

    validateDate(day, month, year, daysInYear);

    sendResult(day, month, year, daysInYear);

    return 0;
}

/*
  Validirung des Tages, Monats und Jahres (nicht negativ oder 0)
  Tag nicht über 31 und nicht über Monatsgrenze
  Monat nicht über 12
*/
int validateDate(int day, int month, int year, int daysInYear[])
{
    // Validirung des Tages, Monats und Jahres (nicht negativ oder 0)
    if (day <= 0 || month <= 0 || year <= 0 || day > 31 || month > 12)
    {
        printf("Error! Werte unrealistisch.\n");
        printf("Bitte überprüfen Sie ihre Eingabe. (got: %i.%i.%i)\n", day, month, year);
        return 0;
    }

    // Überprüung auf Schaltjahr wenn der angegebende Monat 02 entspricht (Februar)
    if (month >= 2)
    {
        if (checkLeapYear(year))
        {
            daysInYear[2] = 29;
        }
    }

    // Überprüfung ob Tag im Monat moglich ist
    if (day > daysInYear[month])
    {
        return 0;
    }
    return 0;
}

/*
  Der Gregoranischer Kalender gibt 3 Regeln an:
  1. Die durch 4 ganzzahlig teilbaren Jahre sind Schaltjahre.
  2. Säkularjahre, also die Jahre, die ein Jahrhundert
     abschließen (z. B. 1800, 1900, 2100 und 2200)
     sind keine Schaltjahre.
  3. Die durch 400 ganzzahlig teilbaren S�kularjahre
     doch Schaltjahre.

  Quelle: https://de.wikipedia.org/wiki/Schaltjahr
*/
int checkLeapYear(int year)
{
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
    {
        printf("Jahr ist ein Schaltjahr");
        return 1;
    }
    else
    {
        printf("Jahr ist kein Schaltjahr");
        return 0;
    }
}

/*
  Bereitstellung und ausgabe der Werte
*/
int sendResult(int day, int month, int year, int daysInYear[])
{
    int totalDays = 0;

    // Addiert alle Monate zusammen, welche vor dem Angegebenden Moant sind.
    for (int i = 1; i < month; i++)
    {
        totalDays += daysInYear[i];
    }

    // Ausgabe des Ergebnisses
    printf("Der %i.%i.%i ist der %i Tag im Jahr.\n", day, month, year, totalDays += day);
    return 0;
}
