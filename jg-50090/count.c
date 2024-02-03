#include <stdio.h>

void swapInt(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapPtr(int **a, int **b) {
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

void count(int **p[]) {
    int *ptr[515] = { NULL }, cnt[515] = {}, len = 0;
    for (int i = 0; p[i] != NULL; i++) {
        int newPtr = 1;
        for (int j = 0; ptr[j] != NULL; j++) {
            if (ptr[j] == *p[i]) {
                cnt[j]++;
                newPtr = 0;
            }
        }
        if (newPtr) {
            ptr[len] = *p[i];
            cnt[len]++;
            len++;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (cnt[i] < cnt[j]) {
                swapInt(&cnt[i], &cnt[j]);
                swapPtr(&ptr[i], &ptr[j]);
            } else if (cnt[i] == cnt[j] && *ptr[i] < *ptr[j]) {
                swapInt(&cnt[i], &cnt[j]);
                swapPtr(&ptr[i], &ptr[j]);
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", *ptr[i], cnt[i]);
    }
}