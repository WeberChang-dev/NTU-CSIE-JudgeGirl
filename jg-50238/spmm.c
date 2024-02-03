#include <stdio.h>

void sparseMatrixMult(int** A, int** B) {
    for (int i = 0; A[i] != NULL; i++) {
        for (int j = 0; B[j] != NULL; j++) {
            int sum = 0;
            for (int k = 1; A[i][k] != -1; k += 2) {
                for (int l = 1; B[j][l] != -1; l += 2) {
                    if (A[i][k] == B[j][l]) {
                        sum += A[i][k + 1] * B[j][l + 1];
                    }
                }
            }
            if (sum != 0) {
                printf("%d %d %d\n", A[i][0], B[j][0], sum);
            }
        }
    }
}