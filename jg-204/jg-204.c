#include<stdio.h>

int findPos(int x, int y, int n, int pos[][2]) {
    for (int i = 0; i < n; i++) {
        if (pos[i][0] == x && pos[i][1] == y) {
            return i;
        }
    }
    return -1;
}

int changeDir(int preDir) {
    if (preDir == 0) return 1;
    if (preDir == 1) return 0;
    if (preDir == 2) return 3;
    return 2;
}

int main() {
    int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}}, w, d, house[105][105], pos[405][2], curDir[405], x = 0, y = d;
    scanf("%d%d", &w, &d);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &house[i][j]);
        }
    }
    for (int i = 0; i < w; i++) {
        pos[i][0] = d;
        pos[i][1] = i;
        curDir[i] = 0;
    }
    for (int i = w; i < d + w; i++) {
        pos[i][0] = d - 1 - i + w;
        pos[i][1] = w;
        curDir[i] = 2;
    }
    for (int i = d + w; i < d + 2 * w; i++) {
        pos[i][0] = -1;
        pos[i][1] = w - 1 - i + w + d;
        curDir[i] = 3;
    }
    for (int i = d + 2 * w; i < 2 * d + 2 * w; i++) {
        pos[i][0] = i - d - 2 * w;
        pos[i][1] = -1;
        curDir[i] = 1;
    }
    for (int i = 0; i < 2 * (d + w); i++) {
        x = pos[i][0] + dir[curDir[i]][0];
        y = pos[i][1] + dir[curDir[i]][1];
        while (1) {
            if (x == -1 || y == -1 || y == w || x == d) {
                printf("%d\n", findPos(x, y, 2 * (d + w), pos));
                break;
            }
            if (house[x][y] == 1) {
                curDir[i] = changeDir(curDir[i]);
            }
            x += dir[curDir[i]][0];
            y += dir[curDir[i]][1];
        }
    }
}