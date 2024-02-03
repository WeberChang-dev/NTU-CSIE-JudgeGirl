#include <stdio.h>
#include <stdbool.h>

bool canPlace(int n, int x, int y, int index, int colors[26][4], int edgeColor[6][6][4]) {
    if (y > 0 && colors[index][0] != edgeColor[x][y - 1][2]) return false;
    if (x > 0 && colors[index][1] != edgeColor[x - 1][y][3]) return false;
    return true; 
}

bool tiling(int n, int x, int y, int used[26], int matrix[6][6], int edgeColor[6][6][4], int colors[26][4]) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    for (int i = 0; i < n * n; i++) {
        if (!used[i] && canPlace(n, x, y, i, colors, edgeColor)) {
            used[i] = 1;
            matrix[x][y] = i;
            for (int j = 0; j < 4; j++) edgeColor[x][y][j] = colors[i][j];
            if (y == n - 1) {
                if (tiling(n, x + 1, 0, used, matrix, edgeColor, colors)) {
                    return true;
                }
            } else {
                if (tiling(n, x, y + 1, used, matrix, edgeColor, colors)) {
                    return true;
                }
            }
            used[i] = 0;
            matrix[x][y] = -1;
            for (int j = 0; j < 4; j++) edgeColor[x][y][j] = -1;
        }
    }
    return false;
}

int main() {
    int matrix[6][6], n, colors[26][4], used[26] = {}, edgeColor[6][6][4];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &colors[i][j]);
                edgeColor[i / n][i % n][j] = -1;
            }
            matrix[i / n][i % n] = -1;
            used[i] = 0;
        }
        if (!tiling(n, 0, 0, used, matrix, edgeColor, colors)) printf("no solution\n");
    }
}