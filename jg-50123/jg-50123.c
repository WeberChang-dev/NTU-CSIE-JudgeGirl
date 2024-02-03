#include <stdio.h>
#define MAXN 1005
int main() {
    int n, K, x, y, arr[MAXN][MAXN] = {}, oneX, oneY;
    scanf("%d%d%d%d", &n, &K, &x, &y);
    for (int i = x, j = y, k = K; k >= 1; k--, i = (i + 1) % n, j = (j - 1 + n) % n) {
        if (k == 1) {
            oneX = i, oneY = j;
            break;
        }
    }
    for (int i = oneX, j = oneY, k = 1; k <= n * n; k++, i = (i - 1 + n) % n, j = (j + 1) % n) {
        if (arr[i][j]) {
            i = (i + 1) % n, j = (j - 1 + n) % n;
            i = (i + 1) % n;
        }
        arr[i][j] = k;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(((j == n - 1) ? "%d" : "%d "), arr[i][j]);
        }
        printf("\n");
    }
}