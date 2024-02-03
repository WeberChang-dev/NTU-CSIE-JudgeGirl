#include "nextMove.h"
#include "validMoveNum.h"

int nextMove(int r, int c, int n, int visited[100][100]) {
    // if (!(r >= 0 && c >= 0 && r < n && c < n) || visited[r][c]) return -1;
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}, index = -1, min = 10;
    for (int i = 0; i < 8; i++) {
        int p = validMoveNum(r + move[i][0], c + move[i][1], n, visited);
        if (p != -1 && p < min) {
            min = p;
            index = i;
        }
    }
    return index;
}