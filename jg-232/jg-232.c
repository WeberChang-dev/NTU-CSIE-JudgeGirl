#include<stdio.h>
int main() {
    int year, newMon, newDay, ogDay, n, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &year, &ogDay, &n);
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) months[1]++;
    while (n--) {
        scanf("%d%d", &newMon, &newDay);
        if (newMon < 1 || newMon > 12) { printf("-1\n"); continue; }
        if (newDay < 1 || newDay > months[newMon - 1]) { printf("-2\n"); continue; }
        for (int i = 0; i < newMon - 1; i++) newDay += months[i];
        printf("%d\n", (ogDay + newDay - 1) % 7); 
    }
}