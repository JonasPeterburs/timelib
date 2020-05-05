# Documentation

## Table of contents
- [Functions](#functions)
- [Structs](#structs)

### Functions
- [is_leapyear](#int-is_leapyear)
- [exists_date](#int-exists_date)
- [get_days_for_month](#int-get_days_for_month)
- [day_of_the_year](#int-day_of_the_year)
- [input_date](#struct-input_date)

### Structs
- [date](#struct-date)

## Functions

### `int` is_leapyear()
<div align="right">
  <br />
  <p>
    <img src="images/is_leapyear.png" width="450">
  </p>
  <br />
</div>

Checks if the given year is a leap year based on the [calendar reform](https://en.wikipedia.org/wiki/Calendar_reform).
Dates before the year 1582 are invalid.

|Parameter|Type|Description  |
|:--------|:---|:------------|
|year     |int |Year to check|

|Returns|Description |
|:------|:-----------|
|1      |true        |
|0      |false       |
|-2     |invalid year|

### `int` exists_date()
<div align="right">
  <br />
  <p>
    <img src="images/exists_date.png" width="450">
  </p>
  <br />
</div>

Validates the given date. Dates before 01/01/1582 and after 12/31/2400 are invalid.

|Parameter   |Type  |Description     |
|:-----------|:-----|:---------------|
|current_date|struct|Date to validate|

|Returns|Description |
|:------|:-----------|
|1      |valid date  |
|0      |invalid date|

### `int` get_days_for_month()
<div align="right">
  <br />
  <p>
    <img src="images/get_days_for_month.png" width="450">
  </p>
  <br />
</div>

Returns days of the given month (including leap years).

|Parameter|Type|Description            |
|:--------|:---|:----------------------|
|month    |int |Range from 1 to 12     |
|year     |int |Range from 1852 to 2400|

|Returns|Description  |
|:------|:------------|
|1-31   |days in month|
|-1     |invalid date |

### `int` day_of_the_year()
<div align="right">
  <br />
  <p>
    <img src="images/day_of_the_year.png" width="450">
  </p>
  <br />
</div>

Calculates the day of the year from 01/01. Leap years are included.

|Parameter   |Type  |Description         |
|:-----------|:-----|:-------------------|
|current_date|struct|Date for calculation|

|Returns|Description          |
|:------|:--------------------|
|1-366  |number of day in year|
|-1     |date invalid         |

### `struct` input_date()
<div align="right">
  <br />
  <p>
    <img src="images/input_date.png" width="450">
  </p>
  <br />
</div>

Formats the user input into a date struct. Will repeat until input is a valid date.
Format: DIN ISO 8601:2006-09

## Structs

### `struct` date
```c
struct date
{
    int day;
    int month;
    int year;
}
```
