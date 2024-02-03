#include<stdio.h>
int main() {
    int n, m, arr[200005] = {}, tmp, ans[200005] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) ans[arr[i] % m]++;
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}