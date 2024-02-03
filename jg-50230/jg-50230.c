#include<stdio.h>
#define MAXS 100001
#define MAXC 11

int f(int x, int s) {
    return (77 * x + 2222) % s; 
}

int found(int x, int s, int hashTable[MAXS][MAXC]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(x, s)][i] == x) {
            return 1;
        }
    }
    return 0;
}

void insert(int x, int s, int hashTable[MAXS][MAXC]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(x, s)][i] == 0) {
            hashTable[f(x, s)][i] = x;
            return;
        }
    }
}

void delete(int x, int s, int hashTable[MAXS][MAXC]) {
    for (int i = 0; i < MAXC; i++) {
        if (hashTable[f(x, s)][i] == x) {
            hashTable[f(x, s)][i] = 0;
            return;
        }
    }
}

int main() {
    int k, s, c, hashTable[MAXS][MAXC] = {};
    scanf("%d%d", &s, &c);
    while (scanf("%d", &k) != EOF) {
        if (found(k, s, hashTable)) {
            delete(k, s, hashTable);
            printf("%d %d\n", k, f(k, s));
        } else {
            insert(k, s, hashTable);
        }
    }
}