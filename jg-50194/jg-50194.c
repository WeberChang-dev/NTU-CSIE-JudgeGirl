#include<stdio.h>

int digits(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
    int k, l, n, prev = 0;
    scanf("%d%d", &k, &l);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        int t = n % k, d = digits(n);
        if (t * d > l) continue;
        if (prev + t * d > l) {
            printf("\n");
            for (int i = 0; i < t; i++) printf("%d", n);
            prev = t * d;
        } else {
            for (int i = 0; i < t; i++) printf("%d", n);
            prev += t * d;
        }
    }
}