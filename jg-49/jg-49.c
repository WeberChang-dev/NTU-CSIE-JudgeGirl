#include<stdio.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))

int main() {
    int tmp, n, m, arr[1005][3] = {};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) arr[i][2] = 10005;
    while (n--) {
        scanf("%d", &tmp);
        arr[tmp % m][0] += tmp;
        arr[tmp % m][1] = max(tmp, arr[tmp % m][1]);
        arr[tmp % m][2] = min(tmp, arr[tmp % m][2]);
    }
    for (int i = 0; i < m; i++) {
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}