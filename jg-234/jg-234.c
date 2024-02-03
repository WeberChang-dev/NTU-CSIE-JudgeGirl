#include<stdio.h>
#define abs(x) ((x) > 0 ? (x) : -(x))

int isRoot3(long long a, long long b, long long c, long long x) {
    return ((x * (x * (a + x) + b) + c) ? 0 : 1);
}

int isRoot2(long long a, long long b, long long x) {
    return ((x * (a + x) + b) ? 0 : 1);
}

int main() {
    long long a, b, c, newA, newB, lastA, lastDigit;
    scanf("%lld%lld%d", &a, &b, &c);
    if (c != 0) lastDigit = c;
    else if (b != 0) lastDigit = b;
    else lastDigit = a;
    for (long long i = abs(lastDigit); i >= -abs(lastDigit); i--) {
        if (isRoot3(a, b, c, i)) {
            printf("%d ", -i);
            newA = i + a;
            newB = newA * i + b;
            break;
        }
    }
    if (newB != 0) lastDigit = newB;
    else lastDigit = newA;
    for (long long i = abs(lastDigit); i >= -abs(lastDigit);  i--) {
        if (isRoot2(newA, newB, i)) {
            printf("%d ", -i);
            lastA = i + newA;
            printf("%d", lastA);
            break;
        }
    }
}