#include<stdio.h>
#define ll long long

ll _gcd(ll x, ll y) {
    if (!y) return x;
    return _gcd(y, x % y);
}

int main() {
    ll lcm = 1, n;
    while (scanf("%lld", &n) != EOF) {
        ll gcd = _gcd(lcm, n);
        lcm = lcm / gcd * n;
    }
    printf("%lld\n", lcm);
}