#include <stdio.h>
#include <string.h>
#define MAXN 101
#define MAXS 10001
#define MAXC 11

int f(char *s, int k) {
    int ret = s[0] - 'a' + 1;
    for (int i = 0; s[i] != '\0'; i++) {
        ret = ret * 29 + s[i] - 'a' + 1;
    }
    return ret % k;
}

int find(char *str, int s, char ht[MAXS][MAXC][6]) {
    int num = f(str, s);
    for (int i = 0; i < MAXC; i++) {
        if (!strcmp(ht[num][i], str)) {
            return i;
        }
    }
    return -1;
}

void insert(char *str, int s, int x, int y, int z, int hashTable[MAXS][MAXC][3], char ht[MAXS][MAXC][6]) {
    int num = f(str, s);
    for (int i = 0; i < MAXC; i++) {
        if (!strcmp(ht[num][i], "\0")) {
            strcpy(ht[num][i], str);
            hashTable[num][i][0] = x;
            hashTable[num][i][1] = y;
            hashTable[num][i][2] = z;
            return;
        }
    }
}

void delete(char *str, int s, int hashTable[MAXS][MAXC][3], char ht[MAXS][MAXC][6]) {
    int num = f(str, s);
    for (int i = 0; i < MAXC; i++) {
        if (!strcmp(ht[num][i], str)) {
            strcpy(ht[num][i], "\0");
            hashTable[num][i][0] = 0;
            hashTable[num][i][1] = 0;
            hashTable[num][i][2] = 0;
            return;
        }
    }
}

int main() {
    int K, s, c, n, hashTable[MAXS][MAXC][3];
    char tower[MAXN][MAXN][MAXN][6], ht[MAXS][MAXC][6], repeat[6];
    scanf("%d", &n);
    s = n * n;
    strcpy(repeat, "\0");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                scanf("%s", &tower[i][j][k]);
                if (j == i - 1 || k == i - 1) {
                    if (find(tower[i][j][k], s, ht) != -1) strcpy(repeat,tower[i][j][k]);
                    insert(tower[i][j][k], s, j, k, i, hashTable, ht);
                }
            }
        }
    }
    while (strcmp(repeat, "\0")) {
        printf("%s\n", repeat);
        int index1 = find(repeat, s, ht), num = f(repeat, s);
        int x1 = hashTable[num][index1][0], y1 = hashTable[num][index1][1], z1 = hashTable[num][index1][2];
        delete(repeat, s, hashTable, ht);
        int index2 = find(repeat, s, ht);
        int x2 = hashTable[num][index2][0], y2 = hashTable[num][index2][1], z2 = hashTable[num][index2][2];
        delete(repeat, s, hashTable, ht);
        strcpy(repeat, "\0");
        if (z1 != n) {
            if (find(tower[z1 + 1][x1][y1], s, ht) != -1) {
                strcpy(repeat, tower[z1 + 1][x1][y1]);
            }
            insert(tower[z1 + 1][x1][y1], s, x1, y1, z1 + 1, hashTable, ht);
        }
        if (z2 != n) {
            if (find(tower[z2 + 1][x2][y2], s, ht) != -1) {
                strcpy(repeat, tower[z2 + 1][x2][y2]);
            }
            insert(tower[z2 + 1][x2][y2], s, x2, y2, z2 + 1, hashTable, ht);
        }
    }
}