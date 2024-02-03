#include <stdio.h>

double foo(double f[15], double x, int d) {
    double ret = 0.0, curX = 1;
    for (int i = 0; i <= d; i++) {
        ret += curX * f[i];
        curX *= x;
    }
    return ret;
}

int main() {
    int d, k;
    double f[15], x, fp[15];
    scanf("%d", &d);
    for (int i = d; i >= 0; i--) scanf("%lf", &f[i]);
    for (int i = d - 1; i >= 0; i--) fp[i] = (i + 1) * f[i + 1];
    scanf("%d%lf", &k, &x);
    for (int i = 0; i < k; i++) {
        double y = foo(f, x, d), m = foo(fp, x, d - 1);
        printf("%.4lf %.4lf\n", x, y);
        x -= y / m;
    }
}