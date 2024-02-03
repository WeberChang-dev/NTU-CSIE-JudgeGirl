#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
int main() {
    int arr[1005][1005] = {}, n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int prev = -1;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] && prev == -1) prev = j;
            else if (arr[i][j]) ans = max(ans, j - prev + 1);
            else if (prev != -1 && !arr[i][j]) prev = -1;
        }
        prev = -1;
        for (int j = 1; j <= n; j++) {
            if (arr[j][i] && prev == -1) prev = j;
            else if (arr[j][i]) ans = max(ans, j - prev + 1);
            else if (prev != -1 && !arr[j][i]) prev = -1;
        }
    }
    for (int i = 1; i < n; i++) {
        int prev = -1;
        for (int j = 1, k = i; j <= n && k <= n; j++, k++) {
            if (arr[j][k] && prev == -1) prev = j;
            else if (arr[j][k]) ans = max(ans, j - prev + 1);
            else if (prev != -1 && !arr[j][k]) prev = -1;
        }
        prev = -1;
        for (int j = 1, k = i; j <= n && k <= n; j++, k++) {
            if (arr[k][j] && prev == -1) prev = j;
            else if (arr[k][j]) ans = max(ans, j - prev + 1);
            else if (prev != -1 && !arr[k][j]) prev = -1;
        }
    } 
    printf("%d", ans);
}