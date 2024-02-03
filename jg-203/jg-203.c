#include<stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int X, Y, x1, x2, y1, y2, dx1, dy1, dx2, dy2, t;
    scanf("%d %d %d %d %d %d %d %d %d %d %d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);
    while (t--) {
        if (x1 == x2 && y1 == y2) {
            swap(&dx1, &dx2);
            swap(&dy1, &dy2);
        }
        if (x1 == 1 || x1 == X) dx1 *= -1;
        if (y1 == 1 || y1 == Y) dy1 *= -1;
        if (x2 == 1 || x2 == X) dx2 *= -1;
        if (y2 == 1 || y2 == Y) dy2 *= -1;
        x1 += dx1;
        x2 += dx2;
        y1 += dy1;
        y2 += dy2;
    }
    printf("%d\n%d\n%d\n%d", x1, y1, x2, y2);
}