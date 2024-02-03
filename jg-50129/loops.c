#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int max(int a, int b) { 
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
bool vis[1000005] = { false }, flag;

void loops(int N, int *A, int *B[], int ans[4]) {
    int index, start = 0;
    ans[0] = ans[2] = -1;
    ans[1] = ans[3] = INT_MAX;
    while (1) {
        int len = 0, maxE = -1, minE = INT_MAX;
        for (int j = start; j < N; j++) {
            if (!vis[j]) {
                index = j;
                start = j;
                break;
            }
            if (j == N - 1) flag = 1;
        }
        if (flag) break;
        while (!vis[index]) {
            len++;
            minE = min(minE, A[index]);
            maxE = max(maxE, A[index]);
            vis[index] = 1;
            index = B[index] - A;
        }
        if (len > ans[0]) {
            ans[0] = len;
            ans[2] = maxE;
        } else if (ans[0] == len && maxE > ans[2]) {
            ans[2] = maxE;
        } 
        if (len < ans[1]) {
            ans[1] = len;
            ans[3] = minE;
        } else if (len == ans[1] && minE < ans[3]) {
            ans[3] = minE;
        }
    }
}