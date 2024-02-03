#include "intersection.h"
void intersection(int map[100][100], int result[4]) {
    int city[105][105] = {}, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0 ; i < 4; i++) result[i] = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            city[i][j] = map[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (!city[i][j]) continue; 
            int cnt = 0, road[4] = {};
            for (int k = 0; k < 4; k++) {
                if (city[i + dir[k][0]][j + dir[k][1]]) {
                    cnt++;
                    road[k]++;
                }
            }
            if (cnt == 2 && ((road[0] && road[2]) || (road[1] && road[3]))) continue;
            result[4 - cnt]++;
        }
    }
}