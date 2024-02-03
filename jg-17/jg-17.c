#include<stdio.h>
int main() {
    int arr[105][105], r, c, ans[105] = {};
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            ans[j] += arr[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        ans[i] /= r;
        printf("%d\n", ans[i]);
    }
}