#include <stdio.h>
int main() {
    int h, w, K, arr[205][205], ans = 0;
    scanf("%d%d%d", &h, &w, &K);
    if (h < 2 * K - 1 || w < 2 * K - 1) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = K - 1; i + K <= h; i++) {
        for (int j = K - 1; j + K <= w; j++) {
            int sum = 0;
            for (int k = i - K + 1, l = j; k < i; k++, l++) sum += arr[k][l];
            for (int k = i, l = j + K - 1; l > j; k++, l--) sum += arr[k][l];
            for (int k = i + K - 1, l = j; k > i; k--, l--) sum += arr[k][l];
            for (int k = i, l = j - K + 1; l < j; k--, l++) sum += arr[k][l];
            if (sum > ans) ans = sum;
        }
    }
    printf("%d", ans);
}