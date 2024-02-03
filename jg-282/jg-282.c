#include <stdio.h>
int main() {
    long long n, cnt;
    while (scanf("%lld", &n) != EOF) {
        cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        printf("%lld\n", cnt);
    }
}