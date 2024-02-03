#include <stdio.h>

int convert16bit(int x) {
    return (x > 32767) ? x - 32768 * 2 : x;
}

int main() {
    char filename[205];
    int n = 0, cnt[65537] = {}, c = 0, ans = -32769, ansCnt = 0;
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    for (int i = 0; i < 4; i++) {
        n += fgetc(fp) << (i * 8);
    }
    for (int i = 0; i < n; i++) {
        c = fgetc(fp) + (fgetc(fp) << 8);
        cnt[c]++;
        if (cnt[c] > ansCnt || (cnt[c] == ansCnt && convert16bit(c) > ans)) {
            ansCnt = cnt[c];
            ans = convert16bit(c);
        }
    }
    printf("%d\n%d", ans, ansCnt);
}