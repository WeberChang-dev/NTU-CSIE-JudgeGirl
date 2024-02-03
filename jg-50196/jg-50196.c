#include <stdio.h>
int main() {
    int ans = 0, n, mulNum = 1, num = 0, lastSign = 8;
    while (scanf("%d", &n)) {
        if (n == 0) {
            if (lastSign == 8) ans += num;
            if (lastSign == 9) ans += mulNum * num;
            break;
        } else if (n == 9) {
            mulNum *= num;
            num = 0;
            lastSign = 9;
        } else if (n == 8) {
            ans += mulNum * num;
            mulNum = 1;
            num = 0;
            lastSign = 8;
        } else {
            num = num * 10 + n;
        }
    }
    printf("%d", ans);
}