#include<stdio.h>
#define ll long long

ll digitSum(ll x) {
    ll sum = 0;
    while (x > 0) {
        sum += x - x / 10 * 10;
        x /= 10;
    }
    return sum;
}

ll digitCnt(ll x) {
    ll cnt = 0;
    while (x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
    int ans = 0, n;
    while (scanf("%d", &n) != EOF) {
        if (digitSum(ans) < digitSum(n)) ans = n;
        else if (digitSum(ans) == digitSum(n) && digitCnt(ans) > digitCnt(n)) ans = n;
        else if (digitSum(ans) == digitSum(n) && digitCnt(ans) == digitCnt(n) && ans < n) ans = n;
    }
    printf("%d", ans);
}