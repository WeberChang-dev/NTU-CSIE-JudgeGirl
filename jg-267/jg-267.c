#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

typedef struct point {
    int x, y;
} Point;

int dis(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int cmp(const void *a, const void *b) {
    Point A = *(Point *)a;
    Point B = *(Point *)b;
    if (dis(A.x, A.y, 0, 0) == dis(B.x, B.y, 0, 0)) {
        if (A.x == B.x) {
            return A.y - B.y;
        } else {
            return A.x - B.x;
        }
    } else {
        return dis(A.x, A.y, 0, 0) - dis(B.x, B.y, 0, 0);
    }
}

int main() {
    Point cities[MAXN];
    int x, y, n = 0, ans = 0;
    while (scanf("%d%d", &x, &y) != EOF) {
        cities[n].x = x; 
        cities[n++].y = y;
    }
    qsort(cities, n, sizeof(Point), cmp);
    x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        ans += dis(x, y, cities[i].x, cities[i].y);
        x = cities[i].x;
        y = cities[i].y;
    }
    printf("%d", ans);
}