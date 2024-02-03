#include<stdio.h>
int main() {
    int year, month, day, dates[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &year, &month, &day);
    if ((month > 12 || month < 1) || (day < 0 || day > 6)) {
        printf("invalid\n");
        return 0;
    }
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    if (month == 2 && year % 4 == 0) {
        if (year % 100 != 0) dates[1]++; 
        else if (year % 400 == 0) dates[1]++;
    }
    for (int i = 0; i < day; i++) printf("   ");
    for (int i = 1; i <= dates[month - 1]; i++) {
        printf("%3d", i);
        if (day == 6) printf("\n");
        if (i == dates[month - 1] && day != 6) printf("\n");
        day = (day + 1) % 7;
    }
    printf("=====================\n");
}