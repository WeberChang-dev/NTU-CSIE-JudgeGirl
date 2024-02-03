#include <stdio.h>
#define MAXN 105

void rotate(int op, int n, int index, int cube[MAXN][MAXN][MAXN]) {
    int new[MAXN][MAXN];
    if (n % 2) new[n / 2][n / 2] = op ? cube[n / 2][n / 2][index] : cube[index][n / 2][n / 2];
    for (int j = 0; j < n / 2; j++) {
        for (int k = j; k < n - j; k++) new[k][n - j - 1] = op ? cube[j][k][index] : cube[index][j][k];
        for (int k = j; k < n - j; k++) new[n - j - 1][n - k - 1] = op ? cube[k][n - j - 1][index] : cube[index][k][n - j - 1];
        for (int k = j; k < n - j; k++) new[k][j] = op ? cube[n - j - 1][k][index] : cube[index][n - j - 1][k];
        for (int k = j; k < n - j; k++) new[j][k] = op ? cube[n - k - 1][j][index] : cube[index][n - k - 1][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!op) cube[index][i][j] = new[i][j];
            else cube[i][j][index] = new[i][j];
        }
    }
}

int main() {
    int cube[MAXN][MAXN][MAXN], n, m, cnt = 0, op, index;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cube[i][j][k] = cnt++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &op, &index);
        rotate(op, n, index, cube);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
}