#include<stdio.h>
int main() {
    int n, m, p1[105], p2[105], ans[205] = {};
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--) scanf("%d", &p1[i]);
    scanf("%d", &m);
    for (int i = m - 1; i >= 0; i--) scanf("%d", &p2[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i + j] += p1[i] * p2[j];
        }
    }
    for (int i = n + m - 2; i > 0; i--) printf("%d ", ans[i]);
    printf("%d", ans[0]);
}