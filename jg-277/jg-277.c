#include <stdio.h>
#include <string.h>
int main() {
    char str[11];
    int w, h;
    int flag[11][10] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0}
    };
    while (scanf("%s%d%d", str, &w, &h) != EOF) {
        char print[16][95] = {'\0'};
        int i = 0;
        for (i = 0; i < strlen(str); i++) {
            int digit = str[i] - '0';
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < h; k++) {
                    print[k][i * w + j] = ' ';
                }
            }
            for (int j = 1; j < w - 2; j++) {
                if (flag[digit][0]) print[0][i * w + j] = '0' + digit;
                if (flag[digit][3]) print[h / 2][i * w + j] = '0' + digit;
                if (flag[digit][6]) print[h - 1][i * w + j] = '0' + digit;
            }
            for (int j = 0; j < (h - 3) / 2; j++) {
                if (flag[digit][1]) print[j + 1][i * w] = '0' + digit;
                if (flag[digit][2]) print[j + 1][i * w + w - 2] = '0' + digit;
                if (flag[digit][4]) print[j + h / 2 + 1][i * w] = '0' + digit;
                if (flag[digit][5]) print[j + h / 2 + 1][i * w + w - 2] = '0' + digit;
            }
        }
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < i * w; k++) {
                printf("%c", print[j][k]);
            }
            printf("\n");
        }
    }
}