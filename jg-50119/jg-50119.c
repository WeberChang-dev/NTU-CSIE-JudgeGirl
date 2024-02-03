#include <stdio.h>
int main() {
    int x, a, b, c, y, d, e, f, n;
    scanf("%d%d%d%d%d%d%d%d%d", &x, &a, &b, &c, &y, &d, &e, &f, &n);
    while (n--) {
        int cnt = 1;
        while (x % 3 == y % 3) {
            cnt++;
            x = (a * x + b) % c;
            y = (d * y + e) % f;
        }
        if ((x % 3 == 0 && y % 3 == 2) || (x % 3 == 1 && y % 3 == 0) || (x % 3 == 2 && y % 3 == 1)) {
            printf("0 ");
        } else {
            printf("1 ");
        }
        printf("%d\n", cnt);
        x = (a * x + b) % c;
        y = (d * y + e) % f;
    }
}