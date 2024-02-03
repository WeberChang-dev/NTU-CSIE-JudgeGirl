#include<stdint.h>
#include <stdio.h>

void printMatrix(uint64_t *matrix) {
    printf("%lu\n", *matrix);
    for (int i = 0; i < 64; i++) {
        printf("%d", (*matrix & ((uint64_t)(1) << i)) != 0);
        if (i % 8 == 7) printf("\n");
    }
}

void rotateMatrix(uint64_t *matrix) {
    // printMatrix(matrix);
    int arr[8][8], cpy[8][8];
    for (int i = 0, cnt = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = cpy[i][j] = (*matrix & ((uint64_t)1 << cnt)) != 0;
            cnt++;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 8 - i; j++) {
            arr[j][7 - i] = cpy[i][j];
            arr[7 - i][7 - j] = cpy[j][7 - i];
            arr[7 - j][i] = cpy[7 - i][7 - j];
            arr[i][j] = cpy[7 - j][i];
        }
    }
    *matrix = 0;
    for (int i = 0, cnt = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            *matrix |= ((uint64_t)arr[i][j] << cnt);
            cnt++;
        }
    }
}

void transposeMatrix(uint64_t *matrix) {
    int arr[8][8], cpy[8][8];
    for (int i = 0, cnt = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = cpy[i][j] = (*matrix & ((uint64_t)(1) << cnt)) != 0;
            cnt++;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = cpy[j][i];
        }
    }

    *matrix = 0;
    for (int i = 0, cnt = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            *matrix |= ((uint64_t)(arr[i][j]) << cnt);
            cnt++;
        }
    }
}