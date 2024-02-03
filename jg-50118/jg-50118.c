#include <stdio.h>

int getLength(int x) {
    int cnt = 0;
    while (x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

int getMSD(int x) {
    while (x >= 10) x /= 10;
    return x;
}

int getLSD(int x) {
    return x - x / 10 * 10;
} 

int main() {
    int n, prevLSD = -1, ans = 0, curLen = 0, lsd, msd;
    while (scanf("%d", &n) != EOF) {
        lsd = getLSD(n); msd = getMSD(n);
        if (prevLSD == -1) {
            curLen += getLength(n);
        } else if (msd == prevLSD) {
            curLen += getLength(n);
        } else {
            curLen = getLength(n);
        }
        if (curLen > ans) ans = curLen;
        prevLSD = lsd;
    }
    printf("%d", ans);
}