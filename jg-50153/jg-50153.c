#include<stdio.h>
int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n%d", 2 * (a + b + c + d + e + f), a * b + (a + c) * d + (a + c + e) * f);
}