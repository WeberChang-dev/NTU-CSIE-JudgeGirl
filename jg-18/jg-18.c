#include<stdio.h>
int main() {
    int r, c, arr[105][105] = {}, dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = 0; k <= 3; k++) {
                if (arr[i][j] <= arr[i + dir[k][0]][j + dir[k][1]]) {
                    break;
                }
                if (k == 3) printf("%d\n", arr[i][j]);
            }
        }
    }
}