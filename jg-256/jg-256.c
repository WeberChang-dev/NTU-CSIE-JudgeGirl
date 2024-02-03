#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define ull unsigned long long

int countOne(ull x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

int cmp(const void *a, const void *b) {
    ull A = *(ull *)a;
    ull B = *(ull *)b;
    int countA = countOne(A), countB = countOne(B);
    if (countA == countB) {
        if (A > B) {
            return 1;
        } else {
            return -1;
        }
    } else {
        return countA - countB;
    }
}

int main() {
    ull arr[1005], x;
    int index = 0;
    while (scanf("%llu", &x) != EOF) {
        arr[index++] = x;
    }
    qsort(arr, index, sizeof(ull), cmp);
    for (int i = 0; i < index; i++) {
        printf("%llu\n", arr[i]);
    }
}