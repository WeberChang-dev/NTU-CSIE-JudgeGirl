#include <stdio.h>
#include <stdbool.h>
#define MAXN 10

int  determinant(int n, int matrix[MAXN][MAXN]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    if (n == 1) return matrix[0][0];
    int ret = 0, tmp[MAXN][MAXN];;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (k == i) {
                    flag = true;
                    continue;
                }
                tmp[j - 1][k - flag] = matrix[j][k];
            }
        }
        if (i % 2 == 0) ret += matrix[0][i] * determinant(n - 1, tmp);
        else ret -= matrix[0][i] * determinant(n - 1, tmp);
    }
    printf("determinant=%d\n", ret);
    return ret;
}

int main() {
    int n, matrix[MAXN][MAXN], tmp[MAXN][MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    determinant(n, matrix);
}