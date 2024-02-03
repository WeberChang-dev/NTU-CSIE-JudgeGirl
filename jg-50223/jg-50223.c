#include<stdio.h>
#define square(x) (x)*(x)
#define abs(x) ((x > 0) ? x : -(x))
int main() {
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
    if (b) 
        printf("%d", square(w) + square(a + 2 * d + 2 + 2 * e + b + c));
    else 
        printf("%d", square(w) + square(a + d + 1 + abs(e - d) + 1 + e + c));
}