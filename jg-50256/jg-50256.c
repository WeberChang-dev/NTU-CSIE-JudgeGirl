#include <stdio.h>
int main() {
    int n, x, y, h, w, ans = 0, X, Y;
    scanf("%d", &n);
    scanf("%d%d%d%d", &x, &y, &w, &h);
    n--;
    ans = h * w;
    X = x + w, Y = y + h;
    while (n--) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        ans += w * h;
        ans -= (X - x) * (Y - y);
        X = x + w, Y = y + h;
    }
    printf("%d", ans);
}