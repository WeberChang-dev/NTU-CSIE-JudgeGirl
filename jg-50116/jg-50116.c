#include <stdio.h>
int main() {
    int n, cnt = 0, evenSum = 0, oddSum = 0, zeroCnt = 0;
    while (scanf("%d", &n) != EOF) {
        cnt++;
        if (cnt % 2) oddSum += n;
        else evenSum += n;
        if (!n) zeroCnt++;
    }
    printf("%d\n%d\n%d\n%d", cnt, (n % 2 == 0), zeroCnt, (oddSum - evenSum) % 11 == 0);
}