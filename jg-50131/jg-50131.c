#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[10005];
    int cnt = 0, a, b, intervalA[2] = {-1, -1}, intervalB[2] = {-1, -1};
    while (scanf("%s%d%d", str, &a, &b) != EOF) {
        cnt = 0;
        intervalA[0] = intervalA[1] = intervalB[0] = intervalB[1] = -1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (cnt == a && intervalA[0] == -1) {
                intervalA[0] = i;
            }
            if (cnt == a && isVowel(str[i])) {
                intervalA[1] = i;
            }
            if (cnt == b && intervalB[0] == -1) {
                intervalB[0] = i;
            }
            if (cnt == b && isVowel(str[i])) {
                intervalB[1] = i;
            }
            if (isVowel(str[i])) cnt++;
        }
        for (int i = 0; str[i] != '\0'; i++) {
            if (i >= intervalA[0] && i <= intervalA[1]) {
                printf("%c", str[i]);
            } else {
                printf("+");
            }
        }
        printf("\n");
        for (int i = 0; str[i] != '\0'; i++) {
            if (i >= intervalB[0] && i <= intervalB[1]) {
                printf("%c", str[i]);
            } else {
                printf("+");
            }
        }
        printf("\n");
        for (int i = 0; str[i] != '\0'; i++) {
            if (!(i >= intervalA[0] && i <= intervalA[1] ) && !(i >= intervalB[0] && i <= intervalB[1])) {
                printf("%c", str[i]);
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
}