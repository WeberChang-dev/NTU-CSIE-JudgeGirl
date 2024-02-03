#include<stdio.h>

int shift(int x, int n) {
    int cpy = x;
    for (int i = 0; i < n - 1; i++) x /= 10;
    for (int i = 0; i < n - 1; i++) x *= 10;
    return cpy - x;
}

int main() {
    int special[3], first[3], money[6] = {200000, 40000, 10000, 4000, 1000, 200}, lottery, ans = 0;
    for (int i = 0; i < 3; i++) scanf("%d", &special[i]);
    for (int i = 0; i < 3; i++) scanf("%d", &first[i]);
    while (scanf("%d", &lottery) != EOF) {
        if (lottery == special[0] || lottery == special[1] || lottery == special[2]) { ans += 2000000; continue; }
        for (int i = 0; i < 6; i++) {
            int win = 0;
            for (int j = 0; j < 3; j++) {
                if (shift(first[j], 9 - i) == shift(lottery, 9 - i)) {
                    win = 1;
                }
            }
            if (win) { ans += money[i]; break; }
        }
    }
    printf("%d", ans);
}