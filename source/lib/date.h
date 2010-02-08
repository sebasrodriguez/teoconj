#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <stdio.h>
#include <conio.h>

typedef struct{
	int day;
	int month;
	int year;
}date;

date createDate(int day, int month, int year);

bool loadDate(date &d);

bool verifyDate(date d);

bool leapYear(date d);

void printDate(date d);

bool dateEqual(date d1, date d2);

int dateMenor(date dl, date d2);

#endif
