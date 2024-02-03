#include <stdio.h>

int pickNumbers(int n, int k, int m, int nums[25], int index, int cnt, int sum) {
    if (sum > m) return 0;
    if (index == n) return (cnt >= k);
    return pickNumbers(n, k, m, nums, index + 1, cnt, sum) + pickNumbers(n, k, m, nums, index + 1, cnt + 1, sum + nums[index]);
}

int main() {
    int n, k, m, nums[25];
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < n; i++) 
        scanf("%d", &nums[i]);
    printf("%d", pickNumbers(n, k, m, nums, 0, 0, 0));
}