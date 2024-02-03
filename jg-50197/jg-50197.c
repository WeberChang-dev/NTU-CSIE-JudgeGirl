#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void dfs(int cnt, int ans, int lastDigit, int n) {
    if (cnt == 4) {
        printf("%d\n", ans);
        return;
    }
    for (int i = max(0, lastDigit - n); i <= min(9, lastDigit + n); i++) {
        dfs(cnt + 1, ans * 10 + i, i, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 9; i++) 
        dfs(1, i, i, n);
}