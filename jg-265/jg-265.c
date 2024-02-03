#include<stdio.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))

int main() {
    int minX = 10005, minY = 10005, maxX = -10005, maxY = -10005, x, y;
    while (scanf("%d%d", &x, &y) != EOF) {
        minX = min(x, minX);
        maxX = max(x, maxX);
        minY = min(y, minY);
        maxY = max(y, maxY);
    }
    printf("%d", (maxX - minX) * (maxY - minY));
}