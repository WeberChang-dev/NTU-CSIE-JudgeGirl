#include <stdio.h>
#include <stdbool.h>

bool inside(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int lake(int n, int m, int map[401][401], int x, int y, int dir[4][2]) {
    map[x][y] = 0;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        if (inside(x + dir[i][0], y + dir[i][1], n, m) && map[x + dir[i][0]][y + dir[i][1]]) {
            ret += lake(n, m, map, x + dir[i][0], y + dir[i][1], dir);
        }
    }
    return ret;
}

int main() {
    int n, m, map[401][401], dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, ans[80002], ansIndex = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                ans[ansIndex++] = lake(n, m, map, i, j, dir);
            }
        }
    }
    for (int i = 0; i < ansIndex; i++) {
        for (int j = 1; j < ansIndex; j++) {
            if (ans[j - 1] < ans[j]) {
                int tmp = ans[j - 1];
                ans[j - 1] = ans[j];
                ans[j] = tmp;
            }
        }
    }
    for (int i = 0; i < ansIndex; i++) {
        printf("%d\n", ans[i]);
    }
}