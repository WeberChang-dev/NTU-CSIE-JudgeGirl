#include "snake.h"
#include <stdio.h>

void swapPtr(const int **x, const int **y) {
    const int *tmp = *x;
    *x = *y;
    *y = tmp;
}

void snake(const int *ptr_array[100][100], int m) {
    const int *ptr1d[10000];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++, k++) {
            ptr1d[k] = ptr_array[i][j];
        }
    }
    for (int i = 0; i < m * m; i++) {
        for (int j = 0; j < m * m - 1; j++) {
            if (*(ptr1d[j]) > *(ptr1d[j + 1])) {
                swapPtr(&ptr1d[j], &ptr1d[j + 1]);
            }
        }
    }
    k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2) {
            for (int j = m - 1; j >= 0; j--, k++) {
                ptr_array[i][j] = ptr1d[k];
            }
        } else {
            for (int j = 0; j < m; j++, k++) {
                ptr_array[i][j] = ptr1d[k];
            }
        }
    }
}