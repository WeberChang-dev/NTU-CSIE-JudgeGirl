#include <stdio.h>
#include <stdbool.h>
 
typedef struct {
    int x, y;
} Pos;
 
typedef struct {
    int type;
    Pos p;
} L;
 
bool full(int l, int m, int floor[65][65]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - m; j++) {
            if (!floor[i][j] || !floor[j][i]) {
                return false;
            }
        }
    }
    return true;
}
 
bool rowFull(int l, int m, int r, int floor[65][65]) {
    if (r < l - m) {
        for (int i = 0; i < l; i++) {
            if (!floor[r][i]) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < l - m; i++) {
            if (!floor[r][i]) {
                return false;
            }
        }
    }
    return true;
}
 
Pos nextPos(int l, int m, Pos *cur) {
    Pos ret;
    if (cur -> y > l - m) {
        if (cur -> x == l - m - 1) {
            ret.x = 1;
            ret.y = cur -> y + 1;
        } else {
            ret.x = cur -> x + 1;
            ret.y = cur -> y;
        }
    } else {
        if (cur -> x == l - 1) {
            ret.x = 1;
            ret.y = cur -> y + 1;
        } else {
            ret.x = cur -> x + 1;
            ret.y = cur -> y;
        }
    }
    return ret;
}
 
bool inside(int l, int m, int x, int y) {
    if (y >= l - m) {
        return x >= 0 && y >= 0 && x < l - m && y < l;
    }
    return x >= 0 && y >= 0 && x < l && y < l - m;
}
 
bool clear(int l, int m, int floor[65][65], int type, Pos *pos) {
    bool flag = true;
    if (type != 1) flag &= inside(l, m, pos -> x, pos -> y) && !floor[pos -> y][pos -> x];
    if (type != 2) flag &= inside(l, m, pos -> x - 1, pos -> y) && !floor[pos -> y][pos -> x - 1];
    if (type != 3) flag &= inside(l, m, pos -> x - 1, pos -> y - 1) && !floor[pos -> y - 1][pos -> x - 1];
    if (type != 4) flag &= inside(l, m, pos -> x, pos -> y - 1) && !floor[pos -> y - 1][pos -> x];
    return flag;
}
 
void cover(int floor[65][65], int type, Pos *pos, int coverWith) {
    if (type != 1) floor[pos -> y][pos -> x] = coverWith;
    if (type != 2) floor[pos -> y][pos -> x - 1] = coverWith;
    if (type != 3) floor[pos -> y - 1][pos -> x - 1] = coverWith;
    if (type != 4) floor[pos -> y - 1][pos -> x] = coverWith;
}
 
bool tiles(int l, int m, int floor[65][65], L ans[65 * 65], int index, Pos pos) {
    if (pos.y == l) {
        if (full(l, m, floor)) {
            for (int i = 0; i < index; i++) {
                printf("%d %d %d\n", ans[i].type, ans[i].p.x, ans[i].p.y);
            }
            return true;
        }
        return false;
    }
    if (pos.x == 1 && pos.y >= 2 && !rowFull(l, m, pos.y - 2, floor)) return false;
    if (pos.x >= 2 && !floor[pos.y - 1][pos.x - 2]) return false;
    // printf("%d %d %d\n", pos.x, pos.y, index);fflush(stdout);
    if (tiles(l, m, floor, ans, index, nextPos(l, m, &pos)))
        return true;
    for (int i = 1; i <= 4; i++) {
        if (clear(l, m, floor, i, &pos)) {
            cover(floor, i, &pos, 1);
            ans[index].type = i;
            ans[index].p = pos;
            if (tiles(l, m, floor, ans, index + 1, nextPos(l, m, &pos)))
                return true;
            cover(floor, i, &pos, 0);
            ans[index].type = 0;
        }
    }
    return false;
}
 
int main() {
    int m, l, floor[65][65] = {};
    L ans[65 * 65];
    Pos initPos = {1, 1};
    scanf("%d%d", &l, &m);
    tiles(l, m, floor, ans, 0, initPos);
}