#include <stdio.h>
int main() {
    int x[2], y[2], r[2], a, b;
    for (int i = 0; i < 2; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);
    while (scanf("%d%d", &a, &b) != EOF) {
        int con = 0;
        for (int i = 0; i < 2; i++) {
            if ((a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i]) < r[i] * r[i]) {
                printf("In\n");
                con = 1;
                break;
            }
        }
        if (con) continue;
        for (int i = 0; i < 2; i++) {
            if ((a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i]) == r[i] * r[i]) {
                printf("On\n");
                con = 1;
                break;
            }
        }
        if (con) continue;
        printf("Out\n");
    }
}