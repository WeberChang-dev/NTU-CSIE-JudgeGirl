#include <stdio.h>

int digitCnt(int x) {
    int exist[10] = {}, cnt = 0;
    while (x) {
        exist[x - x / 10 * 10] = 1;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) cnt += exist[i];
    return cnt;
}

int main() {
    int a, b, x;
    while (scanf("%d%d%d", &a, &b, &x) != EOF) {
        while (digitCnt(x) > 2) {
            x = (a * x) % b;
        }
        printf("%d\n", x);
    }
}