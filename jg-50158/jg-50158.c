#include <stdio.h>

int max(int a, int b) { return ((a) > (b) ? (a) : (b)); }
int min(int a, int b) { return ((a) < (b) ? (a) : (b)); }

int C(int a, int b, int c, int x) {
    return (a * x + b) % c;
}

int main() {
    int found = 0, a, b, c, d, e, x, prevCnt1 = -100, prevX1, prevX2, prevCnt2 = -100, cnt = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    while (scanf("%d", &x) != EOF) {
        int ogX = x;
        cnt = 0;
        while (x > e || x < d) {
            x = C(a, b, c, x);
            cnt++;
        }
        int maxCnt = max(max(prevCnt1, prevCnt2), cnt), minCnt = min(min(prevCnt1, prevCnt2), cnt);
        int midCnt = prevCnt1 + prevCnt2 + cnt - maxCnt - minCnt;
        if (maxCnt - midCnt == 1 && midCnt - minCnt == 1) {
            found = 1;
            printf("%d %d %d", prevX1, prevX2, ogX);
            break;
        }
        prevX1 = prevX2;
        prevCnt1 = prevCnt2;
        prevCnt2 = cnt;
        prevX2 = ogX;
    }
    if (!found) printf("Not found");
}