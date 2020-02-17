<div align="center">
  <br />
  <p>
    <img src="https://i.imgur.com/H7fiSmp.png" alt="Timelib">
  </p>
  <br />
  <p>
    <a href="https://github.com/jpeterburs/timelib/actions"><img src="https://github.com/jpeterburs/timelib/workflows/Build/badge.svg" alt="Build"></a>
  </p>
</div>

## Table of contents
- [About](#about)
- [Installation](#installation)
- [Example Usage](#example-usage)
- [Links](#links)

## About
Timelib is a library that allows you to interact with time.

## Installation

## Example usage
```c
#include "timelib.h"
#include <stdio.h>

int main()
{
    int day, month, year;

    input_date(&day, &month, &year);

    printf("%i.%i.%i --> %i", day, month, year, day_of_the_year(day, month, year));
    return 0;
}
```

## Links
* [Documentation (WIP)](#)
* [GitHub](https://github.com/jpeterburs/timelib/)
