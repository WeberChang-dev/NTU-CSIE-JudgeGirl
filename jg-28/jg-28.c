#include <stdio.h>

int sumOfSquares(int x) {
    if (x == 1) return 1;
    return x * x + sumOfSquares(x - 1);
} 

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", sumOfSquares(n));
}