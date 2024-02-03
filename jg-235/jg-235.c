#include<stdio.h>
#define ll long long

ll _gcd(ll x, ll y) {
    if (!y) return x;
    return _gcd(y, x % y);
}

int main() {
    ll n, pin[20][20][2], ans[20][20][2] = {};
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            scanf("%lld %lld", &pin[i][j][0], &pin[i][j][1]);
            ll gcd = _gcd(pin[i][j][0], pin[i][j][1]);
            pin[i][j][0] /= gcd; 
            pin[i][j][1] /= gcd; 
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            ans[i][j][1] = 1;
        }
    }
    ans[1][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // ans[i + 1][j] + ans[i][j] * left
            ans[i + 1][j][0] = ans[i + 1][j][0] * (ans[i][j][1] * (pin[i][j][0] + pin[i][j][1])) + ans[i][j][0] * pin[i][j][0] * ans[i + 1][j][1];
            ans[i + 1][j][1] *= ans[i][j][1] * (pin[i][j][0] + pin[i][j][1]);
            ll gcd = _gcd(ans[i + 1][j][0], ans[i + 1][j][1]);
            ans[i + 1][j][0] /= gcd;
            ans[i + 1][j][1] /= gcd;

            ans[i + 1][j + 1][0] = ans[i + 1][j + 1][0] * (ans[i][j][1] * (pin[i][j][0] + pin[i][j][1])) + ans[i][j][0] * pin[i][j][1] * ans[i + 1][j + 1][1];
            ans[i + 1][j + 1][1] *= ans[i][j][1] * (pin[i][j][0] + pin[i][j][1]);
            gcd = _gcd(ans[i + 1][j + 1][0], ans[i + 1][j + 1][1]);
            ans[i + 1][j + 1][0] /= gcd;
            ans[i + 1][j + 1][1] /= gcd;
        }
    }
    for (int i = 0; i <= n; i++) {
        printf("%lld/%lld\n", ans[n + 1][i][0], ans[n + 1][i][1]);
    }
}