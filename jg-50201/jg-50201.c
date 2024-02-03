#include <stdio.h>
int main() {
    int r, c, arr[605][605] = {}, op, k, top = 0, right;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    right = c - 1;
    while(scanf("%d%d", &op, &k) != EOF) {
        if (op == 1) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j <= right; j++) {
                    arr[top + k + i][j] += arr[top + k - i - 1][j];
                }
            }
            top += k;
        } else if (op == 2) {
            for (int i = 0; i < k; i++) {
                for (int j = top; j < r; j++) {
                    arr[j][right - k - i] += arr[j][right - k + i + 1];
                }
            }
            right -= k;
        } else {
            for (int i = 0; i < k - 1; i++) {
                for (int j = 0; j + i < k - 1; j++) {
                    arr[top + i + 1 + j][right - k + 1 + i] += arr[top + i][right - k + 2 + j + i];
                    arr[top + i][right - k + 2 + j + i] = 0;
                }
            }
        }
    }
    for (int i = top; i < r; i++) {
        for (int j = 0; j <= right; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}