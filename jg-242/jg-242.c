#include<stdio.h>
#define abs(x) ((x) > 0 ? x : -(x))
#define ll long long

int d(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        ll cirX[3], cirY[3], r[3], ans = 0;
        for (int i = 0; i < 3; i++) scanf("%lld %lld %lld", &cirX[i], &cirY[i], &r[i]);
        for (ll x = cirX[0] - r[0]; x <= cirX[0] + r[0]; x++) {
            for (ll y = cirY[0] - r[0]; y <= cirY[0] + r[0]; y++) {
                int cnt = 0;
                if (d(x, y, cirX[0], cirY[0]) <= r[0] * r[0]) {
                    for (int i = 0; i < 3; i++) {
                        if (abs(x - cirX[i]) <= r[i] && abs(y - cirY[i]) <= r[i] && d(x, y, cirX[i], cirY[i]) <= r[i] * r[i])
                            cnt++;
                    }
                } 
                if (cnt == 1 || cnt == 3) ans++;
            }
        }
        for (int j = 1; j < 3; j++) {
            for (ll x = cirX[j] - r[j]; x <= cirX[j] + r[j]; x++) {
                for (ll y = cirY[j] - r[j]; y <= cirY[j] + r[j]; y++) {
                    int cnt = 0;
                    if (d(x, y, cirX[j], cirY[j]) <= r[j] * r[j]) {
                        for (int i = 0; i < 3; i++) {
                            if (abs(x - cirX[i]) > r[i] || abs(y - cirY[i]) > r[i] || d(x, y, cirX[i], cirY[i]) > r[i] * r[i])
                                cnt++;
                        }
                    } 
                    if (cnt == 2) ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}