#include <stdio.h>

int canCover(int n, int m, int x, int y, int l, int w) {
    return (x < m && x >= 1 - w) && (y < n && y >= 1 - l);
}

int main() {
    int n, m, l, w, x, y, s, k, sun[205][205], cpy[205][205];
    scanf("%d%d%d%d%d%d%d%d", &n, &m, &l, &w, &x, &y, &s, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &sun[i][j]);
            cpy[i][j] = sun[i][j];
        }
    }
    for (int index = 0; index <= k; index++, x -= s, y -= s) {
        if (!canCover(n, m, x, y, l, w) && (x < 1 - w || y < 1 - l)) break;
        if (!canCover(n, m, x, y, l, w)) continue;
        for (int i = x; i < x + w; i++) {
            for (int j = y; j < y + l; j++) {
                if (canCover(n, m, i, j, 1, 1)) {
                    cpy[n - 1 - j][i] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", cpy[i][j]);
                cpy[i][j] = sun[i][j];;
            }
            printf("\n");
        }
        printf("\n");
    }
}