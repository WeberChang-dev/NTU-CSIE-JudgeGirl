#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define MAXN 1000001
 
typedef struct date {
    short year, month, day;
} Date;
 
int cmp(const void *a, const void *b) {
    Date A = *(Date *)a;
    Date B = *(Date *)b;
    if (A.year != B.year) {
        return A.year - B.year;
    } else {
        if (A.month != B.month) {
            return A.month - B.month;
        } else {
            return A.day - B.day;
        }
    }
}
 
int main() {
    int n;
    Date arr[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%hd %hd %hd", &arr[i].year, &arr[i].month, &arr[i].day);
    }
    qsort(arr, n, sizeof(Date), cmp);
    for (int i = 0; i < n; ++i) {
        printf("%hd %hd %hd\n", arr[i].year, arr[i].month, arr[i].day);
    }
}