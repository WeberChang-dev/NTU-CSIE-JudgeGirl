#include<stdio.h>

int win(int m, int bingo[257][257]) {
    int ret = 0;
    for (int i = 0; i < m ; i++) {
        if (ret) break;
        for (int j = 0; j < m - 1; j++) {
            if (bingo[i][j] != bingo[i][j + 1]) {
                break;
            }
            if (j == m - 2) {
                ret = 1;
            }
        }
    }
    if (ret) return ret;
    for (int i = 0; i < m ; i++) {
        if (ret) break;
        for (int j = 0; j < m - 1; j++) {
            if (bingo[j][i] != bingo[j + 1][i]) {
                break;
            }
            if (j == m - 2) {
                ret = 1;
            }
        }
    }
    if (ret) return ret;
    for (int i = 0; i < m - 1; i++) {
        if (bingo[i][i] != bingo[i + 1][i + 1]) {
            break;
        }
        if (i == m - 2) {
            ret = 1;
        }
    }
    if (ret) return ret;
    for (int i = 0; i < m - 1; i++) {
        if (bingo[i][m - 1 - i] != bingo[i + 1][m - 2 - i]) {
            break;
        }
        if (i == m - 2) {
            ret = 1;
        }
    }
    return ret;
}

int main() {
    char names[11][70];
    int n, m, bingos[10][257][257], num, end = 0, ans[11], ptr = 0, pos[10][256 * 256 + 1][2];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &bingos[i][j][k]);
                pos[i][bingos[i][j][k]][0] = j;
                pos[i][bingos[i][j][k]][1] = k;
            }
        }
    }
    for (int it = 0; it < m * m; it++) {
        scanf("%d", &num);
        for (int i = 0; i < n; i++) {
            bingos[i][pos[i][num][0]][pos[i][num][1]] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (win(m, bingos[i])) {
                end = 1;
                ans[ptr++] = i;
            }
        }
        if (end) {
            printf("%d ", num);
            for (int i = 0; i < ptr - 1; i++) printf("%s ", names[ans[i]]);
            printf("%s", names[ans[ptr - 1]]);
            break;
        }
    }
}