#include <stdio.h>
int main() {
    int r, c, arr[1005][1005], ans = 0;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i < r - 1; i++) {
        for (int j = 0; j <= c - 4; j++) {
            if (arr[i][j] + arr[i][j + 2] == 7 && arr[i][j + 1] + arr[i][j + 3] == 7) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        if (arr[i - 1][j + k] + arr[i + 1][j + l] == 7) {
                            int cnt[7] = {}, isDice = 1;
                            cnt[arr[i][j]]++; cnt[arr[i][j + 1]]++; cnt[arr[i][j + 2]]++; cnt[arr[i][j + 3]]++;
                            cnt[arr[i - 1][j + k]]++; cnt[arr[i + 1][j + l]]++;
                            for (int m = 1; m <= 6; m++) {
                                if (cnt[m] != 1) {
                                    isDice = 0;
                                    break;
                                }
                            }
                            if (isDice) ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
}