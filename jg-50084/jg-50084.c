#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m, p, q, t, avail[505] = {}, tasks[505][505][2], jobSize[505], start[505], index[505] = {}, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &start[i], &jobSize[i]);
        for (int j = 0; j < jobSize[i]; j++) {
            scanf("%d%d", &tasks[i][j][0], &tasks[i][j][1]);
        }
        cnt += jobSize[i];
    }
    while (cnt--) {
        int minTime = INT_MAX, minIndex;
        for (int i = 0; i < m; i++) {
            if (index[i] == jobSize[i]) continue;
            int endTime = max(start[i], avail[tasks[i][index[i]][0]]) + tasks[i][index[i]][1];
            if (endTime < minTime) {
                minTime = endTime;
                minIndex = i;
            }
        }
        start[minIndex] = avail[tasks[minIndex][index[minIndex]][0]] = max(start[minIndex], avail[tasks[minIndex][index[minIndex]][0]]) + tasks[minIndex][index[minIndex]][1];
        index[minIndex]++;
    }
    for (int i = 0; i < m; i++) {
        printf((i == m - 1) ? "%d" : "%d\n", start[i]);
    }
}