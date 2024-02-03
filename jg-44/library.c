#include "book.h"
#include "date.h"
#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int dayDiff(struct Date date_borrowed, struct Date date_returned) {
    int days = 0, month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = date_borrowed.year + 1; i < date_returned.year; i++) {
        days += 365 + isLeapYear(i);
    }
    if (date_borrowed.year == date_returned.year) {
        if (date_borrowed.month != date_returned.month) {
            for (int i = date_borrowed.month; i < date_returned.month - 1; i++) {
                days += month[i] + (i == 1 && isLeapYear(date_borrowed.year));
            }
            days += month[date_borrowed.month - 1] + (date_borrowed.month == 2 && isLeapYear(date_borrowed.year)) - date_borrowed.day + date_returned.day;
        } else {
            days += date_returned.day - date_borrowed.day;
        }
    } else {
        for (int i = date_borrowed.month; i < 12; i++) {
            days += month[i] + (i == 1 && isLeapYear(date_borrowed.year));
        }
        for (int i = 0; i < date_returned.month - 1; i++) {
            days += month[i] + (i == 1 && isLeapYear(date_returned.year));
        }
        days += month[date_borrowed.month - 1] + (date_borrowed.month == 2 && isLeapYear(date_borrowed.year)) - date_borrowed.day + date_returned.day;
    }
    return days + 1;
}

int decodeImportance(unsigned int importance) {
    int pos = -1;
    for (int i = 0; importance; i++, importance >>= 1) {
        if (importance & 1 && pos == -1) {
            pos = i;
        } else if (importance & 1) {
            return i - pos - 1;
        }
    }
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
    int days = dayDiff(date_borrowed, date_returned), period[4] = {90, 10, 100, 5};
    if (days <= period[book.type]) return 0;
    return decodeImportance(book.importance) * (days - period[book.type]);
}