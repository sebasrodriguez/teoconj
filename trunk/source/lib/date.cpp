#include "date.h"

const short MAX_DAY = 31;
const short MIN_DAY = 1;
const short LEAP_DAY = 29;
const short MIN_MONTH = 1;
const short MAX_MONTH = 12;

date createDate(int day, int month, int year){
    date d;
    d.day = day;
    d.month = month;
    d.year = year;
    return d;
}

bool loadDate(date &d){
    printf("\tDia: ");
    scanf("%d", &d.day);
    printf("\tMes: ");
    scanf("%d", &d.month);
    printf("\tAnio: ");
    scanf("%d", &d.year);
    return verifyDate(d);
}

bool verifyDate(date d){
    bool ok = false;
    if (d.month >= MIN_MONTH && d.month <= MAX_MONTH){
        if ((d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) && d.day <= MAX_DAY) {
            ok = true;
        }else{
            if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day == MAX_DAY - 1){
                ok = true;
            }else{
                if (leapYear(d) == true && d.day == LEAP_DAY){
                    ok = true;
                }else{
                    if (d.day <= LEAP_DAY - 1){
                        ok = true;
                    }
                }
            }
        }
    }
    return ok;
}

bool leapYear(date d){
    return ((d.year % 4 == 0) && ((d.year % 100 != 0) || (d.year % 400 == 0)));
}

void printDate(date d){
    printf("%d/%d/%d", d.day, d.month, d.year);
}

bool dateEqual(date d1, date d2){
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

int dateMenor(date d1, date d2){
    bool menor = true;
    if(d1.year > d2.year){
        menor = false;
    }else if(d1.year == d2.year){
        if(d1.month > d2.month){
            menor = false;
        }else if(d1.month == d2.month){
            if(d1.day > d2.day){
                menor = false;
            }
        }
    }
    return menor;
}
