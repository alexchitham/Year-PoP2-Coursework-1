#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
    int dayOfWeek;
};

int daysinMonths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
struct date decrementDay(struct date date);
int isLeapYear(struct date date);
int howManyDays();

int howManyDays()
{
    struct date knownDate;
    knownDate.day = 24;
    knownDate.month = 3;
    knownDate.year = 2002;
    knownDate.dayOfWeek = 3;

    int counter = 0;

    struct date curDate = knownDate;

    while (curDate.year > 2000)
    {
        curDate = decrementDay(curDate);
    }

    while (curDate.year > 1800)
    {
        if (curDate.day == 5 && curDate.dayOfWeek == 5)
        {
            printf("%d - %d - %d\n", curDate.day, curDate.month, curDate.year);
            counter++;
        }
        curDate = decrementDay(curDate);
        
        //printf("  %d\n", curDate.dayOfWeek);
    }
    return counter;

}

struct date decrementDay(struct date date)
{
    if (date.day > 1)
    {
        date.day--;
    }
    else if (date.day == 1)
    {
        if (date.month == 1)
        {
            date.year--;
            date.month = 12;
        }
        else
        {
            date.month--;
        }

        if (isLeapYear(date) && date.month == 2)
        {
            date.day = 29;
        }
        else
        {
            date.day = daysinMonths[date.month - 1];
        }

    }

    if (date.dayOfWeek == 1)
    {
        date.dayOfWeek = 7;
    }
    else
    {
        date.dayOfWeek--;
    }

    return date;
}

int isLeapYear(struct date date)
{
    if (date.year % 4 == 0)
    {
        if (date.year % 100 == 0 && date.year % 400 != 0)
        {
            return 0;
        }

        return 1;
    }
    return 0;
}




int main(void)
{
    //printf("hi");
    printf("%d", howManyDays());
}