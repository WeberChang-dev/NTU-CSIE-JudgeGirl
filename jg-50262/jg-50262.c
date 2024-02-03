#include <stdio.h>
#include <limits.h>
#define MAXN 50005
int main() {
    int n, x[MAXN], y[MAXN], xy, yy, d = INT_MAX, ans[MAXN], len = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
    scanf("%d%d", &xy, &yy);
    for (int i = 0; i < n; i++) {
        if ((x[i] - xy) * (x[i] - xy) + (y[i] - yy) * (y[i] - yy) < d) {
            len = 1;
            ans[0] = i;
            d = (x[i] - xy) * (x[i] - xy) + (y[i] - yy) * (y[i] - yy);
        } else if ((x[i] - xy) * (x[i] - xy) + (y[i] - yy) * (y[i] - yy) == d) {
            ans[len++] = i;
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d\n", ans[i]);
    }
}