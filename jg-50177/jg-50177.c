#include <stdio.h>
#include <stdbool.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

bool allDark(int n, int lights[5][5]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lights[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool inside(int n, int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void switchLight(int n, int m, int lights[5][5]) {
    int dir[5][2] = {{0, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}}, row = m / n, col = m % n;
    for (int i = 0; i < 5; i++) {
        if (inside(n, row + dir[i][0], col + dir[i][1])) {
            lights[row + dir[i][0]][col + dir[i][1]] ^= 1;
        }
    }
}

void turnOff(int n, int lights[5][5], int index, int *used, int curUsed, int cur, int *best) {
    if (cur > *best) return;
    if (index == n * n) {
        if (allDark(n, lights) && (cur <= *best)) {
            *used = curUsed;
            *best = cur;
        }
        return;
    }
    turnOff(n, lights, index + 1, used, curUsed, cur, best);
    switchLight(n, index, lights);
    turnOff(n, lights, index + 1, used, curUsed | (1 << index), cur + 1, best);
    switchLight(n, index, lights);
}

void printAns(int n, int used) {
    for (int i = 0; i < n * n; i++) {
        if (used & 1) printf("%d ", i);
        used >>= 1;
    }
}

int main() {
    int n, m, lights[5][5] = {}, used = 0, *usedPtr = &used;
    scanf("%d", &n);
    while (scanf("%d", &m) != EOF) {
        lights[m / n][m % n] = 1;
    }
    int ans = n * n, *ansPtr = &ans;
    turnOff(n, lights, 0, usedPtr, 0,  0, ansPtr);
    printAns(n, used);
}