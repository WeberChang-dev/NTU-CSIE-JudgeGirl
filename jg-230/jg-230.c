#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int W, int curAns, int w[25], int v[25], int index, int n) {
    if (W < 0) return 0;
    if (index == n) return curAns;
    curAns = max(knapsack(W - w[index], curAns + v[index], w, v, index + 1, n), knapsack(W, curAns, w, v, index + 1, n));
    return curAns;
}

int main() {
    int n, W, w[25], v[25];
    scanf("%d%d", &n, &W);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    printf("%d", knapsack(W, 0, w, v, 0, n));
}