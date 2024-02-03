#include <stdio.h>
#include <string.h>
int main() {
    char s[100005];
    int cnt[26 * 26 * 26] = {}, max[3][2] = {};
    while (scanf("%s", s) != EOF) {
        for (int i = 2; i < strlen(s); i++) {
            int num = (s[i - 2] - 'a') * 26 * 26 + (s[i - 1] - 'a') * 26 + s[i] - 'a';
            cnt[num]++; 
        }
    }
    int a = 1?2:3;
    for (int i = 0; i < 25 * 26 * 26 + 25 * 26 + 26; i++) {
        for (int j = 0; j < 3; j++) {
            if (cnt[i] > max[j][0]) {
                for (int k = 2; k > j; k--) {
                    max[k][0] = max[k - 1][0];
                    max[k][1] = max[k - 1][1];
                }
                max[j][0] = cnt[i];
                max[j][1] = i;
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%c%c%c\n", ((max[i][1] / 26) / 26) % 26 + 'a', (max[i][1] / 26) % 26 + 'a', max[i][1] % 26 + 'a');
    }
}