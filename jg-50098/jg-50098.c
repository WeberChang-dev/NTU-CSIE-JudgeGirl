#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
bool disjointSet(int n, int k, int index, bool used[65], uint64_t arr[101], uint64_t cur) {
    if (index == n || k == 0) {
        if (!k) {
            for (int i = 0; i < n; i++) {
                if (used[i]) {
                    printf("%d\n", i);
                }
            }
            return true;
        }
        return false;
    }
    used[index] = 0;
    if ((cur & arr[index]) == 0) {
        used[index] = 1;
        if (disjointSet(n, k - 1, index + 1, used, arr, cur | arr[index])) return true;
        used[index] = 0;
    }
    if (disjointSet(n, k, index + 1, used, arr, cur)) return true;
    return false;
}
 
int main() {
    int n, k, t, m;
    bool used[65] = { false };
    uint64_t arr[101] = {};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &m);
            arr[i] |= ((uint64_t)(1) << m);
        }
    }
    disjointSet(n, k, 0, used, arr, 0);
}