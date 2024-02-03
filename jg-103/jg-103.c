#include<stdio.h>
int main() {
    int n;
    double A[20][20], y[20], x[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }
    x[n - 1] = y[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double xi = y[i];
        for (int j = i + 1; j < n; j++) {
            xi -= A[i][j] * x[j];
        }
        x[i] = xi / A[i][i];
    }
    for (int i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }
}