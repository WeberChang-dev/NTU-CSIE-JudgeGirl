#include <stdio.h>
int main() {
    int n, K, arr[520][520], filter[130][130], ans[520][520] = {};
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &filter[i][j]);
        }
    }
    for (int i = 0; i <= n - K; i++) {
        for (int j = 0; j <= n - K; j++) {
            for (int k = 0; k < K; k++) {
                for (int l = 0; l < K; l++) {
                    ans[i][j] += arr[i + k][j + l] * filter[k][l];
                }
            }
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

}