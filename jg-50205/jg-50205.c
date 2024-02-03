#include <stdio.h>
#include <string.h>
int main() {
    char c, alpha[10] = ")!@#$%^& (";
    int ans = 0, mul = 0, cur = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == '+') {
            ans += mul * cur + cur * (!mul);
            mul = cur = 0;
        } else if (c == '*') {
            if  (mul == 0) mul = cur;
            else mul *= cur;
            cur = 0;
        } else {
            int num = strchr(alpha, c) - alpha;
            cur = cur * 10 + num;
        }
    }
    ans += mul * cur + cur * (!mul);
    printf("%d", ans);
}