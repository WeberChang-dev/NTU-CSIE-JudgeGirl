#include <stdio.h>
#include <limits.h>
#define uint64_t unsigned long long

void find(int n, int k, int index, uint64_t *ansPtr, uint64_t arr[25], uint64_t curAns, uint64_t set[15], uint64_t setSquare[15]) {
    if (curAns >= (*ansPtr)) return;
    if (index == n) {
        (*ansPtr) = curAns;
        return;
    }
    for (int i = 0; i < k; i++) {
        setSquare[i] += 2 * set[i] * arr[index] + arr[index] * arr[index];
        curAns += 2 * set[i] * arr[index] + arr[index] * arr[index];
        set[i] += arr[index];
        find(n, k, index + 1, ansPtr, arr, curAns, set, setSquare);
        set[i] -= arr[index];
        setSquare[i] -= 2 * set[i] * arr[index] + arr[index] * arr[index];
        curAns -= 2 * set[i] * arr[index] + arr[index] * arr[index];
    }
}

int main() {
    int n, k;
    uint64_t arr[25], ans = ULLONG_MAX, *ansPtr = &ans, set[15] = {}, setSquare[15] = {};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%llu", &arr[i]);
    }
    set[0] = arr[0];
    setSquare[0] = arr[0] * arr[0];
    find(n, k, 1, ansPtr, arr, arr[0] * arr[0], set, setSquare);
    printf("%llu", ans);
}