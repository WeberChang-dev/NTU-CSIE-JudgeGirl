#include<stdio.h>
#define abs(x) ((x) > 0 ? x : -(x))
#define min(x,y) ((x < y) ? x : y)

int convertTime(int x) {
    int hour, minute, second;
    second = x - x / 100 * 100;
    x /= 100;
    minute = x - x / 100 * 100;
    x /= 100;
    hour = x;
    return hour * 3600 + minute * 60 + second;
}

int main() {
    int cur, prev, ans = 86405;
    scanf("%d", &prev);
    prev = convertTime(prev);
    while (scanf("%d", &cur) != EOF) {
        cur = convertTime(cur);
        ans = min(ans, abs(cur - prev));
        prev = cur;
    }
    printf("%d", ans);
}