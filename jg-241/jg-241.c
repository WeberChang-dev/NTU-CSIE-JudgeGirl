#include<stdio.h>
 
int cross(int x1, int y1, int x2, int y2) {
    return (x1 * y2 - x2 * y1);
}
 
int main() {
    int x[4], y[4], len[4], dot[4];
    for (int i = 0; i < 4; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i < 4; i++) {
        int j = 1, k = 1;
        for (j; j < 4; j++)
            if (j != i)
                break;
        for (k; k < 4; k++)
            if (k != i && k != j)
                break;
        int cross1 = cross(x[0] - x[i], y[0] - y[i], x[j] - x[0], y[j] - y[0]), 
            cross2 = cross(x[0] - x[i], y[0] - y[i], x[k] - x[0], y[k] - y[0]);
        if ((cross1 < 0 && cross2 > 0) || (cross1 > 0 && cross2 < 0)) {
            int cross0 = cross(x[0], y[0], x[j], y[j]),
                crossj = cross(x[j], y[j], x[i], y[i]),
                crossi = cross(x[i], y[i], x[k], y[k]),
                crossk = cross(x[k], y[k], x[0], y[0]);
            if ((cross0 > 0 && crossi > 0 && crossj > 0 && crossk > 0) ||
                (cross0 < 0 && crossi < 0 && crossj < 0 && crossk < 0))
                printf("1\n");
            else 
                printf("0\n");
        }
    }
}