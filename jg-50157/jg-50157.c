#include <stdio.h>
int main() {
    int k, n, ans = 0, cnt[3] = {}, maxN = -1, secMax = -1;
    scanf("%d", &k);
    while (scanf("%d", &n) != EOF) {
        cnt[n % 3]++;
        if (maxN <= n) {
            secMax = maxN;
            maxN = n;
        } else if (secMax < n) {
            secMax = n;
        }
        if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
            ans += secMax;
            cnt[0] = cnt[1] = cnt[2] = 0;
            maxN = secMax = -1; 
        }
    }
    if (secMax == -1 && maxN != -1) ans += maxN;
    else if (maxN != -1) ans += secMax;
    printf("%d\n", ans);
}