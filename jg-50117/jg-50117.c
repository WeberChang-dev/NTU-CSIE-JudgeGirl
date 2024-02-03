#include <stdio.h>
int main() {
    int k, n, r = 0, q = 0;
    scanf("%d", &k);
    while (scanf("%d", &n) != EOF) {
        r = r * 10 + n;
        if (r / k != 0 || q) printf("%d\n", r / k);
        q += r / k;
        r %= k;
    }
    if (!q) printf("0");
}