#include<stdio.h>
int main() {
    int n, city[105][105] = {}, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, ans[5] = {};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &city[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!city[i][j]) continue; 
            int cnt = 0, road[4] = {};
            for (int k = 0; k < 4; k++) {
                if (city[i + dir[k][0]][j + dir[k][1]]) {
                    cnt++;
                    road[k]++;
                }
            }
            if (cnt == 2 && ((road[0] && road[2]) || (road[1] && road[3]))) continue;
            ans[cnt]++;
        }
    }
    for (int i = 4; i >= 1; i--) printf("%d\n", ans[i]);
}