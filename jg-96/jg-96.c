#include<stdio.h>
int main() {
    double a, b, c, pi = 3.1415926, ans = 0.0;
    scanf("%lf%lf%lf", &a, &b, &c);
    ans += pi * c * c * 3 / 4;
    if (c > b) ans += pi * (c - b) * (c - b) / 4;
    if (c > a) ans += pi * (c - a) * (c - a) / 4;
    printf("%f", ans);
}