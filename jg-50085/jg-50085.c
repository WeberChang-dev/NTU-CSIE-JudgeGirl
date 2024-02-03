#include <stdio.h>

void printMap(int n, int m, int map[505][505]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, w, l, o, map[505][505] = {}, op, tankX = 0, tankY = 0;
    scanf("%d%d%d%d%d", &n, &m, &l, &w, &o);
    for (int i = 0; i < o; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        map[b][a] = 2;
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            map[i][j] = 1;
        }
    }
    while (scanf("%d", &op) != EOF) {
        if (op == 0) {
            printMap(n, m, map);
        } else if (op == 1) {
            if (tankY + w - 1 == m - 1) continue;
            int oCnt = 0;
            for (int i = 0; i < l; i++) {
                if (map[tankX + i][tankY + w] == 2) {
                    oCnt++;
                }
            }
            if (oCnt > 1) continue;
            for (int i = 0; i < l; i++) {
                map[tankX + i][tankY + w] = 1;
                map[tankX + i][tankY] = 0;
            }
            tankY++;
        } else if (op == 2) {
            if (tankX + l - 1 == n - 1) continue;
            int oCnt = 0;
            for (int i = 0; i < w; i++) {
                if (map[tankX + l][tankY + i] == 2) {
                    oCnt++;
                }
            }
            if (oCnt > 1) continue;
            for (int i = 0; i < w; i++) {
                map[tankX + l][tankY + i] = 1;
                map[tankX][tankY + i] = 0;
            }
            tankX++;
        } else if (op == 3) {
            if (tankY == 0) continue;
            int oCnt = 0;
            for (int i = 0; i < l; i++) {
                if (map[tankX + i][tankY - 1] == 2) {
                    oCnt++;
                }
            }
            if (oCnt > 1) continue;
            for (int i = 0; i < l; i++) {
                map[tankX + i][tankY - 1] = 1;
                map[tankX + i][tankY + w - 1] = 0;
            }
            tankY--;
        } else if (op == 4) {
            if (tankX == 0) continue;
            int oCnt = 0;
            for (int i = 0; i < w; i++) {
                if (map[tankX - 1][tankY + i] == 2) {
                    oCnt++;
                }
            }
            if (oCnt > 1) continue;
            for (int i = 0; i < w; i++) {
                map[tankX - 1][tankY + i] = 1;
                map[tankX + l - 1][tankY + i] = 0;
            }
            tankX--;
        } else {
            if (tankX + l - 1 == n - 1 || tankY + w == m) continue;
            int oCnt = -1 * (map[tankX + l][tankY + w] == 2);
            for (int i = 0; i < w; i++) {
                if (map[tankX + l][tankY + 1 + i] == 2) {
                    oCnt++;
                }
            }
            for (int i = 0; i < l; i++) {
                if (map[tankX + 1 + i][tankY + w] == 2) {
                    oCnt++;
                }
            }
            if (oCnt > 1) continue;
            for (int i = 0; i < w; i++) {
                map[tankX + l][tankY + 1 + i] = 1;
                map[tankX][tankY + i] = 0;
            }
            for (int i = 0; i < l; i++) {
                map[tankX + 1 + i][tankY + w] = 1;
                map[tankX + i][tankY] = 0;
            }
            tankX++;
            tankY++;
        }
    }
}