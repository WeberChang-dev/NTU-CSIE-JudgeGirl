#include<stdio.h>
int main() {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    g = ((g > c) ? c : g);
    if (d == 0 || a * b * c == e * f * g) printf("0");
    else if (b * a * d >= a * b * c - e * f * g) printf("%d", c);
    else if (b * a * d <= (a * b - e * f) * g) printf("%d", (b * a * d) / (a * b - e * f));
    else printf("%d", ((b * a * d) - (a * b - e * f) * g) / (a * b) + g);
}