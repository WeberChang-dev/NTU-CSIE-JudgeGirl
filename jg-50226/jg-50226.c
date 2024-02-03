#include<stdio.h>
#define ll long long

ll _gcd(ll x, ll y) {
    if (!y) return x;
    return _gcd(y, x % y);
}

int main() {
    ll a, b, c, d;
    while (scanf("%lld%lld%lld%lld", &a, &b, &c, &d) != EOF) {
        ll gcd1 = _gcd(a, b), gcd2 = _gcd(c, d);
        ll e = a / gcd1 * b, f = c / gcd2 * d;
        ll gcd3 = _gcd(e, f);
        printf("%lld\n", (e / gcd3 * f) / a);
    }
}