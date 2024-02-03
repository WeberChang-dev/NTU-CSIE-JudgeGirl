#include "constructPointerArray.h"
#define MAXN 1024
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN]
, int N) {
    short int pos[N * N][2];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pos[A[i][j]][0] = i;
            pos[A[i][j]][1] = j;
        }
    }
    for (int i = 0; i < N * N; i++) {
        B[pos[i][0]][pos[i][1]] = &A[pos[(i + 1) % (N * N)][0]][pos[(i + 1) % (N * N)][1]];
    }
}