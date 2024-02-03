#include <stdio.h>
int main() {
    int n, cnt, ans;
    while (scanf("%d", &n) != EOF) {
        cnt = ans = 0;
        while (n > 0) {
            cnt += n & 1;
            ans = (ans > cnt) ? ans : cnt;
            if (!(n & 1)) {
                cnt = 0;
            }
            n >>= 1;
        }
        printf("%d\n", ans);
    }
}