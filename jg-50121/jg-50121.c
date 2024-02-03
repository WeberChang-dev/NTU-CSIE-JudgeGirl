#include <stdio.h>

int inside(int n, int m, int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int weightSum(int n, int m, int x, int y, int xd, int yd, int arr[505][505]) {
    if (inside(n, m, x, y) && !arr[x][y]) return 0;
    int sum = 0;
    for (int i = x, j = y; inside(n, m, i, j); i += xd, j += yd) {
        if (!arr[i][j]) {
            return sum;
        }
        sum += arr[i][j];
    }
    return -1;
} 

void shift(int n, int m, int x, int y, int xd, int yd, int arr[505][505], int e, int w) {
    if (w != 0 && e >= w) {
        int i = x, j = y;
        for (i = x, j = y; inside(n, m, i, j); i += xd, j += yd) {
            if (!arr[i][j]) {
                break;
            }
        }
        for (i, j; i != x || j != y; i -= xd, j -= yd) {
            arr[i][j] = arr[i - xd][j - yd];
            // printf("%d", arr[i][j]);
        }
        arr[x][y] = 0;
        arr[x + xd][y + yd] = e - w;
    }
    if (w == 0) {
        arr[x][y] = 0;
        arr[x + xd][y + yd] = e - w;
    }
} 

int main() {
    int n, m, px, py, e, o, arr[505][505] = {}, in;
    scanf("%d%d%d%d%d%d", &n, &m, &px, &py, &e, &o);
    arr[px][py] = e;
    for (int i = 0; i < o; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        arr[x][y] = w;
    }
    while (scanf("%d", &in) != EOF) {
        if (in == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf((j != m - 1) ? "%d " : "%d", arr[i][j]);
                }
                printf("\n");
            }
        } else if (in == 1) {
            int energyCost = weightSum(n, m, px, py + 1, 0, 1, arr);
            if (energyCost > -1 && energyCost <= arr[px][py]) {
                shift(n, m, px, py, 0, 1, arr, arr[px][py], energyCost);
                py++;
            } else if (energyCost == 0) {
                arr[px][py + 1] = arr[px][py];
                arr[px][py] = 0;
                py++;
            }
        } else if (in == 2) {
            int energyCost = weightSum(n, m, px + 1, py, 1, 0, arr);
            if (energyCost > -1 && energyCost <= arr[px][py]) {
                shift(n, m, px, py, 1, 0, arr, arr[px][py], energyCost);
                px++;
            } else if (energyCost == 0) {
                arr[px + 1][py] = arr[px][py];
                arr[px][py] = 0;
                px++;
            }
        } else if (in == 3) {
            int energyCost = weightSum(n, m, px, py - 1, 0, -1, arr);
            if (energyCost > -1 && energyCost <= arr[px][py]) {
                shift(n, m, px, py, 0, -1, arr, arr[px][py], energyCost);
                py--;
            } else if (energyCost == 0) {
                arr[px][py - 1] = arr[px][py];
                arr[px][py] = 0;
                py--;
            }
        } else if (in == 4) {
            int energyCost = weightSum(n, m, px - 1, py, -1, 0, arr);
            if (energyCost > -1 && energyCost <= arr[px][py]) {
                shift(n, m, px, py, -1, 0, arr, arr[px][py], energyCost);
                px--;
            } else if (energyCost == 0) {
                arr[px - 1][py] = arr[px][py];
                arr[px][py] = 0;
                px--;
            }
        }
    }
}