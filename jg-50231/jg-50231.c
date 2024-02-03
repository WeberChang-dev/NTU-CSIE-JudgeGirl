#include<stdio.h>
#define MAXN 110
#define MAXS 11030
#define MAXC 15

int f(int k, int s) {
    return (77 * k + 2222) % s; 
}

int find(int k, int s, int hashTable[MAXS][MAXC][4]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(k, s)][i][0] == k) {
            return i;
        }
    }
    return -1;
}

void insert(int k, int s, int x, int y, int z, int hashTable[MAXS][MAXC][4]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(k, s)][i][0] == 0) {
            hashTable[f(k, s)][i][0] = k;
            hashTable[f(k, s)][i][1] = x;
            hashTable[f(k, s)][i][2] = y;
            hashTable[f(k, s)][i][3] = z;
            return;
        }
    }
}

void delete(int x, int s, int hashTable[MAXS][MAXC][4]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(x, s)][i][0] == x) {
            hashTable[f(x, s)][i][0] = 0;
            hashTable[f(x, s)][i][1] = 0;
            hashTable[f(x, s)][i][2] = 0;
            hashTable[f(x, s)][i][3] = 0;
            return;
        }
    }
}

int main() {
    int k, s, c, n, tower[MAXN][MAXN][MAXN], hashTable[MAXS][MAXC][4] = {}, repeat = 0;
    scanf("%d%d%d", &n, &s, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                scanf("%d", &tower[i][j][k]);
                if (j == i - 1 || k == i - 1) {
                    if (find(tower[i][j][k], s, hashTable) != -1) repeat = tower[i][j][k];
                    insert(tower[i][j][k], s, j, k, i, hashTable);
                }
            }
        }
    }
    while (repeat) {
        printf("%d ", repeat);
        int index1 = find(repeat, s, hashTable);
        int x1 = hashTable[f(repeat, s)][index1][1], y1 = hashTable[f(repeat, s)][index1][2], z1 = hashTable[f(repeat, s)][index1][3];
        delete(repeat, s, hashTable);
        int index2 = find(repeat, s, hashTable);
        int x2 = hashTable[f(repeat, s)][index2][1], y2 = hashTable[f(repeat, s)][index2][2], z2 = hashTable[f(repeat, s)][index2][3];
        delete(repeat, s, hashTable);
        repeat = 0;
        if (z1 != n) {
            if (find(tower[z1 + 1][x1][y1], s, hashTable) != -1) {
                repeat = tower[z1 + 1][x1][y1];
            }
            insert(tower[z1 + 1][x1][y1], s, x1, y1, z1 + 1, hashTable);
        }
        if (z2 != n) {
            if (find(tower[z2 + 1][x2][y2], s, hashTable) != -1) {
                repeat = tower[z2 + 1][x2][y2];
            }
            insert(tower[z2 + 1][x2][y2], s, x2, y2, z2 + 1, hashTable);
        }
    }
}