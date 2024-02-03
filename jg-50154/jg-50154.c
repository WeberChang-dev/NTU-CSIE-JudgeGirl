#include<stdio.h>
int main() {
    int a ,b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    printf("%d\n%d", 
        a + b + c + d + (a + b + c) * e + (c + d) * f + e * g + f + g, 
        a * e * g + b * e * g + c * e * g + c * f + d * f    
    );
}