#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint64_t set;
    int num;
} Set;

int min(int a, int b) {
    return a < b ? a : b;
}
 
bool no(uint64_t set, int friend[2020][2], int index, int m) {
    for (int i = 0; i < m; i++) {
        if ((((uint64_t)(1) << friend[i][0]) & set) == 0 && (((uint64_t)(1) << friend[i][1]) & set) == 0 && index > friend[i][1]) {
            return true;
        }
    }
    return false;
}
 
Set cover(int n, int m, uint64_t set, int friend[2020][2], int index, int isFriend[65]) {
    Set solution = {set, 64}, another;
    if (no(set, friend, index, m)) return solution;
    if (index == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (set & 1) cnt++;
            set >>= 1;
        }
        solution.num = cnt;
        return solution;
    }
    if (!isFriend[index]) 
        return cover(n, m, set, friend, index + 1, isFriend);
    solution = cover(n, m, set, friend, index + 1, isFriend);
    another = cover(n, m, set | (uint64_t)(1) << index, friend, index + 1, isFriend);
    return (solution.num < another.num) ? solution : another;
}
 
int main() {
    int n, m, friend[2020][2], isFriend[65] = {};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &friend[i][0], &friend[i][1]);
        isFriend[friend[i][0]] = isFriend[friend[i][1]] = 1;
        if (friend[i][1] < friend[i][0]) {
            int tmp = friend[i][0];
            friend[i][0] = friend[i][1];
            friend[i][1] = tmp;
        }
    }
    Set ans = cover(n, m, (uint64_t)0, friend, 0, isFriend);
    // printf("%d", ans.num);
    for (int i = 0; i < n; i++) {
        if (ans.set & 1) printf("%d\n", i);
        ans.set >>= 1;
    }
}