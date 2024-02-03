#include <stdio.h>

void permutation(int n, int k, int arr[10], int ans[10], int vis[10]) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[k] = arr[i];
            permutation(n, k + 1, arr, ans, vis);
            vis[i] = 0;
        }
    }
}

int main() {
    int n, arr[10], vis[10] = {}, ans[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    permutation(n, 0, arr, ans, vis);
}