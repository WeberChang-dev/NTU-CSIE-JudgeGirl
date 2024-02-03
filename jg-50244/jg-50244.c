#include <stdio.h>
#define MAXN 21

typedef struct {
    int size;
    int num;
} Component;

Component solve(int n, int tower[MAXN][MAXN][MAXN], int num, int x, int y, int z, int dir[3][3], Component eachBest[MAXN][MAXN][MAXN]) {
    Component best = {1, num}, new, empty = {0, 0}, curComponent = {1, num};
    for (int i = 0; i < 3; i++) {
        int newX = x + dir[i][0], newY = y + dir[i][1], newZ = z + dir[i][2];
        if (tower[newX][newY][newZ] == -1 || newY > newX || newZ > newX || newX >= n || newX < 0 || newY < 0 || newZ < 0) {
            continue;
        }
        tower[x][y][z] = -1;
        if (tower[newX][newY][newZ] != num) {
            new = solve(n, tower, tower[newX][newY][newZ], newX, newY, newZ, dir, eachBest);
            if (new.size > best.size || (best.size == new.size && best.num < new.num)) {
                best = new;
            }
        } else {
            solve(n, tower, num, newX, newY, newZ, dir, eachBest);
            curComponent.size += eachBest[newX][newY][newZ].size;
        }  
        tower[x][y][z] = num;
    }
    if (curComponent.size > best.size || (best.size == curComponent.size && best.num < curComponent.num)) {
        best = curComponent;
    }
    eachBest[x][y][z] = curComponent;
    return best;
}
 
int main() {
    int n, tower[MAXN][MAXN][MAXN], dir[6][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    scanf("%d", &n);
    Component eachBest[MAXN][MAXN][MAXN];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                scanf("%d", &tower[i][j][k]);
                eachBest[i][j][k].num = tower[i][j][k];
                eachBest[i][j][k].size = 1;
            }
        }
    }
    Component ans = solve(n, tower, tower[0][0][0], 0, 0, 0, dir, eachBest);
    printf("%d %d", ans.num, ans.size);
}