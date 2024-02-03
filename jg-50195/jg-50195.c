#include<stdio.h>
#define MAX 1000000000
int main() {
    int n, max[4][2] = {}, prev[4] = {0, MAX, MAX, MAX}, i = 0, pos[4][2][2] = {};
    while (scanf("%d", &n) != EOF) {
        int dis = i - prev[n];
        if (dis > max[n][0]) {
            max[n][1] = max[n][0];
            pos[n][1][0] = pos[n][0][0];
            pos[n][1][1] = pos[n][0][1];
            max[n][0] = dis;
            pos[n][0][0] = prev[n];
            pos[n][0][1] = i;
        } else if (dis == max[n][0]) {
            pos[n][0][0] = prev[n];
            pos[n][0][1] = i;
        } else if (dis >= max[n][1]) {
            max[n][1] = dis;
            pos[n][1][0] = prev[n];
            pos[n][1][1] = i;
        }
        prev[n] = i;
        i++;
    }
    for (int i = 1; i <= 3; i++) {
        printf("%d %d %d\n", max[i][1], pos[i][1][0], pos[i][1][1]);
    }
}