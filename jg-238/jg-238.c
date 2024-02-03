#include <stdio.h>

void subset(int k, int curSum, int *ans, int n, int arr[20], int index) {
    if (curSum == k) {
        *ans += 1;
        return;
    }
    if (curSum > k) return;
    if (index >= n) return;
    subset(k, curSum + arr[index], ans, n, arr, index + 1);
    subset(k, curSum, ans, n, arr, index + 1);
}

int main() {
    int k, ans, n, arr[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    while (scanf("%d", &k) != EOF) {
        ans = 0;
        subset(k, 0, &ans, n, arr, 0);
        printf("%d\n", ans);
    }
}