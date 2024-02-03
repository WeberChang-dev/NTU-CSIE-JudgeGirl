#include "findLength.h"

int inside(int N, int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int findLength (int array[][256], int N, int r, int c, int dr, int dc) {
    int len = 0, ret = 0;
    if (!inside(N, r, c)) return 0;
    for (int i = r, j = c; inside(N, i, j); i += dr, j += dc) {
        if (array[i][j]) len++;
        else {
            ret = (ret > len) ? ret : len;
            len = 0;
        }
    }
    return (ret > len) ? ret : len;
}