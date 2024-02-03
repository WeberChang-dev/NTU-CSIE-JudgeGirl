#include <stdio.h>
#define ll long long
#define min(a,b) ((a) < (b) ? (a) : (b))

ll C(ll n, ll k) {
    k = min(k, n - k);
    ll a = 1, b = 1;
    for (int i = n, j = k; j > 0; i--, j--) {
        a *= i;
        b *= j;
    }
    return a / b;
}

int main() {
    ll ans = 0, n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i <= m; i++) ans += C(n, i);
    printf("%lld", ans);
}