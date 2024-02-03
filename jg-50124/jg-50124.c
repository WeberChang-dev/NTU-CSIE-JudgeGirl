#include <stdio.h>
#include "nextMove.h"
#include "validMoveNum.h"
#define MAXN 100

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
            int jumpIndex = nextMove(knights[i][0], knights[i][1], n, board);
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
        if (i != n - 1) printf("\n");
    }
}