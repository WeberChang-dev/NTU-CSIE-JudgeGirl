#include <stdio.h>

int C(int n, int x, int y, int arr[13][13]) {
    if (x > n || y < 0 || !arr[x][y]) return 0;
    if (x == n && y == 1) return 1;
    return C(n, x + 1, y, arr) + C(n, x, y - 1, arr);
}

int main() {
    int n, m, arr[13][13];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", C(n, 1, m, arr));
}