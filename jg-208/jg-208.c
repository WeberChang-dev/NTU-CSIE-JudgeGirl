#include <stdio.h>
#include <stdint.h>
int main() {
    uint32_t n;
    int row, col, cnt, x = 1, y = 1;
    char ch[2], ans[35];
    scanf("%d%d\n", &col, &row);
    scanf("%c %c", &ch[1], &ch[0]);
    while (scanf("%u", &n) != EOF) {
        if (x <= row) {
            cnt = 0;
            while (n > 0) {
                ans[cnt] = ch[n & 1];
                cnt++;
                n >>= 1;
            }
            for (int i = 31; i >= 0 && x <= row; i--) {
                printf("%c", i >= cnt ? ch[0] : ans[i]);
                if (y == col) {
                    x++;
                    y = 1;
                    printf("\n");
                } else {
                    y++;
                }
            }
        }
    }
}