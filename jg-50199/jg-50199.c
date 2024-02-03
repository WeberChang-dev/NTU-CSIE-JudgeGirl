#include <stdio.h>
int main() {
    int r, c, arr[505][505] = {};
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!arr[i][j]) continue;
            if (arr[i][j] == arr[i - 1][j] && arr[i][j] ==  arr[i + 1][j]) {
                arr[i][j] = arr[i - 1][j] = arr[i + 1][j] = 0;
            } else if (arr[i][j] == arr[i][j - 1] && arr[i][j] ==  arr[i][j + 1]) {
                arr[i][j] = arr[i][j - 1] = arr[i][j + 1] = 0;
            } else if (arr[i][j] == arr[i - 1][j] && arr[i][j] ==  arr[i][j + 1]) {
                arr[i][j] = arr[i - 1][j] = arr[i][j + 1] = 0;
            } else if (arr[i][j] == arr[i - 1][j] && arr[i][j] ==  arr[i][j - 1]) {
                arr[i][j] = arr[i - 1][j] = arr[i][j - 1] = 0;
            } else if (arr[i][j] == arr[i + 1][j] && arr[i][j] ==  arr[i][j + 1]) {
                arr[i][j] = arr[i + 1][j] = arr[i][j + 1] = 0;
            } else if (arr[i][j] == arr[i + 1][j] && arr[i][j] ==  arr[i][j - 1]) {
                arr[i][j] = arr[i + 1][j] = arr[i][j - 1] = 0;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}