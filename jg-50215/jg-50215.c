#include <stdio.h>
#include <string.h>
#include <limits.h>

void setCover(int n, int ans, int bits[25], int cost[25], int index, int curAns, int *costAns, int curCost) {
    if (curCost >= *costAns) return;
    if (n == index) {
        if (curAns == ans) {
            *costAns = curCost;
        }
        return;
    }
    setCover(n, ans, bits, cost, index + 1, curAns, costAns, curCost);
    setCover(n, ans, bits, cost, index + 1, curAns | bits[index], costAns, curCost + cost[index]);
}

int main() {
    int n = 0, ans = 0;
    char str[55];
    for (int i = 0; i < 26; i++) ans += (1 << i);
    while (scanf("%d", &n) != EOF) {
        int  max = INT_MAX, bits[25] = {}, cost[25] = {}, *costAns = &max;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            for (int j = 0; j < strlen(str); j++) {
                bits[i] |= (1 << (str[j] - 'a'));
                cost[i] += str[j] - 'a' + 1;
            }
        }
        setCover(n, ans, bits, cost, 0, 0, costAns, 0);
        printf("%d\n", *costAns);
    }
}