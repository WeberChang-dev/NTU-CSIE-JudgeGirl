#include <stdio.h>
#define MAXN 105

int inside(int n, int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    int n, m, knights[MAXN * MAXN][3] = {}, board[MAXN][MAXN] = {}, moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &knights[i][0], &knights[i][1]);
        board[knights[i][0]][knights[i][1]] = (i + 1) * 10000;
    }
    while (1) {
        int canMove = 0;
        for (int i = 0; i < m; i++) {
            int jumpIndex = -1, p = MAXN * MAXN;
            for (int j = 0; j < 8; j++) {
                int newX = knights[i][0] + moves[j][0], newY = knights[i][1] + moves[j][1];
                if (inside(n, newX, newY) && !board[newX][newY]) {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int newnewX = newX + moves[k][0], newnewY = newY + moves[k][1];
                        if (inside(n, newnewX, newnewY) && !board[newnewX][newnewY]) {
                            cnt++;
                        }
                    }
                    if (cnt < p) {
                        jumpIndex = j;
                        p = cnt;
                    }
                }
            }
            if (jumpIndex != -1) {
                board[knights[i][0] + moves[jumpIndex][0]][knights[i][1] + moves[jumpIndex][1]] = (i + 1) * 10000 + (++knights[i][2]);
                knights[i][0] += moves[jumpIndex][0];
                knights[i][1] += moves[jumpIndex][1];
                canMove = 1;
            }
        }
        if (!canMove) break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf((j != n - 1) ? "%d " : "%d", board[i][j]);
        }
        printf("\n");
    }
}