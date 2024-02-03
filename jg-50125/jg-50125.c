#include <stdio.h>
#include "findLength.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int arr[256][256] = {}, n, ans = 0, d[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                ans = max(ans, findLength(arr, n, i, j, d[k][0], d[k][1]));
                ans = max(ans, findLength(arr, n, i, j, -1 * d[k][0], -1 * d[k][1]));
            }
        }
    }
    printf("%d", ans);
}