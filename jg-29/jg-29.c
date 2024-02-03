#include <stdio.h>

long long C(int n, int m) {
    long long ret = 1;
    for (int i = m + 1; i <= n; i++) ret *= i;
    for (int i = 1; i <= n - m; i++) ret /= i;
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld", C(n + m - 2, m - 1));
}