#include <stdio.h>
#include <string.h>

int main() {
    char str[31], prevLast = '\0';
    int starLen = 0, hor = 1;
    while (scanf("%s", str) != EOF) {
        if (hor) {
            if (str[0] == prevLast) {
                printf("%s\n", str + 1);
                starLen += strlen(str) - 1;
            } else {
                if (starLen != 0) printf("\n");
                for (int i = 0; i < starLen; i++) printf("*");
                printf("%s\n", str);
                starLen += strlen(str) - 1;
            }
        } else {
            if (str[0] == prevLast) {
                for (int i = 1; str[i] != '\0'; i++) {
                    for (int j = 0; j < starLen; j++) printf("*");
                    printf(i != strlen(str) - 1 ? "%c\n" : "%c", str[i]);
                }
            } else {
                for (int i = 0; str[i] != '\0'; i++) {
                    for (int j = 0; j < starLen; j++) printf("*");
                    printf(i != strlen(str) - 1 ? "%c\n" : "%c", str[i]);
                }
            }
        }
        hor = !hor;
        prevLast = str[strlen(str) - 1];
    }
}