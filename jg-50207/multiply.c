#include <stdio.h>
#include "multiply.h"

void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC) {
    for (int index = 0; arrayA[index] != NULL; index++) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < ROW; j++) {
                ((int *)(C *)(arrayC[index]))[i * ROW + j] = 0;
                for (int k = 0; k < COL; k++) {
                    ((int *)(C *)(arrayC[index]))[i * ROW + j] += ((int *)(A *)(arrayA[index]))[i * COL + k] * ((int *)(B *)(arrayB[index]))[k * ROW + j];
                }
            }
        }
    }
}