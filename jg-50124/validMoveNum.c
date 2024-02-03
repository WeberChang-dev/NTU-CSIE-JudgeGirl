#include "validMoveNum.h"

int inside(int n, int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int validMoveNum(int r, int c, int n, int visited[100][100]) {
    if (!inside(n, r, c) || visited[r][c]) return -1;
    int cnt = 0, moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    for (int i = 0; i < 8; i++) {
        if (inside(n, r + moves[i][0], c + moves[i][1]) && !visited[r + moves[i][0]][c + moves[i][1]]) {
            cnt++;
        }
    }
    return cnt;
}