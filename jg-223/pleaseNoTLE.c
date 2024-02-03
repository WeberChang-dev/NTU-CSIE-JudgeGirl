#include <stdio.h>

void tiles(int l, int m, int x, int y, int type, int dir[4][2]) {
    if (l <= 0 || m <= 0 || x <= 0 || y <= 0) return;
    if (l == 2 && m == 1) {
        printf("%d %d %d\n", type, x, y);
        return;
    }
    if (m < l / 2) tiles(l / 2, m, x, y, type, dir);
    tiles(2, 1, x + (l / 2 - m) * dir[type - 1][0], y + (l / 2 - m) * dir[type - 1][1], type, dir);
    tiles(l / 2, 1, x + (l / 2 - m + 1) * dir[type - 1][0], y + (l / 2 - m + 1) * dir[type - 1][1], type, dir);
    int newType1 = ((type - 2) + 4) % 4 + 1, newType2 = type % 4 + 1;
    tiles(l / 2, 1, x + (l / 2 - m) * dir[type - 1][0] + dir[newType1 - 1][0], y + (l / 2 - m) * dir[type - 1][1] + dir[newType1 - 1][1], newType1, dir);
    tiles(l / 2, 1, x + (l / 2 - m) * dir[type - 1][0] + dir[newType2 - 1][0], y + (l / 2 - m) * dir[type - 1][1] + dir[newType2 - 1][1], newType2, dir);
}

int main() {
    int m, l, dir[4][2] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
    scanf("%d%d", &l, &m);
    tiles(l, m, l - m, l - m, 1, dir);
}