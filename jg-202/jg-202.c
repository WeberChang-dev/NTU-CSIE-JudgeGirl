#include<stdio.h>
#define abs(x) (((x) > 0) ? (x) : -(x))

int _gcd(int x, int y) {
    if (!y) return x;
    return _gcd(y, x % y);
}

int main() {
    int a, b, c, d, e, f, g, numer1, numer2, denominator, numerator, gcd;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    numer1 = ((a > 0) ? a * c + b : a * c - b);
    numer2 = ((e > 0) ? e * g + f : e * g - f);
    if (d == 0) {
        denominator = c * g;
        numerator = numer1 * g + numer2 * c;
    } else if (d == 1) {
        denominator = c * g;
        numerator = numer1 * g - numer2 * c;
    } else if (d == 2) {
        denominator = c * g;
        numerator = numer1 * numer2;
    } else {
        denominator = numer2 * c;
        numerator = numer1 * g;
    }
    gcd = _gcd(abs(denominator), abs(numerator));
    denominator /= gcd;
    numerator /= gcd;
    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
    printf("%d\n%d\n%d", numerator / denominator
                       , abs(numerator % denominator)
                       , ((numerator % denominator) ? denominator : 1)
    );
}