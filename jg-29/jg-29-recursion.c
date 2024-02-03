#include <stdio.h>

int C(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (x == 1 && y == 1) return 1;
    return C(x - 1, y) + C(x, y - 1);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", C(n, m));
}