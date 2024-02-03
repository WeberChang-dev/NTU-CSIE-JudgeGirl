#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char str[10], ans[50005] = {'\0'}, alpha[50005] = {'\0'}, prev;
    int index = 0, pos, len = 0, longest = 0, index2;
    while (scanf("%s", str) != EOF) {
        if (!strcmp(str, "insert")) {
            scanf("%s", str);
            if (!strcmp(str, "left")) {
                scanf("%s", str);
                for (int i = index; i >= 1; i--) {
                    ans[i] = ans[i - 1];
                }
                ans[0] = str[0]; 
                index++;
                ans[index] = '\0';
            } else if (!strcmp(str, "right")) {
                scanf("%s", str);
                ans[index++] = str[0];
                ans[index] = '\0';
            } else {
                pos = atoi(str);
                scanf("%s", str);
                for (int i = index; i >= pos; i--) {
                    ans[i] = ans[i - 1];
                }
                ans[pos - 1] = str[0];
                index++;
                ans[index] = '\0';
            }
        } else {
            scanf("%s", str);
            if (!strcmp(str, "left")) {
                for (int i = 0; ans[i] != '\0'; i++) {
                    ans[i] = ans[i + 1];
                }
                index--;
            } else if (!strcmp(str, "right")) {
                ans[--index] = '\0';
            } else {
                pos = atoi(str);
                for (int i = pos - 1; ans[i] != '\0'; i++) {
                    ans[i] = ans[i + 1];
                }
                index--;
            }
        }
    }
    if (!strcmp(ans, "")) {
        printf("0");
    } else {
        alpha[0] = prev = ans[0];
        len = longest = index2 = 1;
        for (int i = 1; ans[i] != '\0'; i++) {
            if (ans[i] == prev) {
                len++;
                if (len > longest) {
                    strcpy(alpha, "");
                    alpha[0] = ans[i];
                    index2 = 1;
                    alpha[1] = '\0';
                    longest = len;
                } else if (len == longest) {
                    alpha[index2++] = ans[i];
                    alpha[index2] = '\0';
                }
            } else {
                len = 1;
                prev = ans[i];
                if (len == longest) {
                    alpha[index2++] = ans[i];
                    alpha[index2] = '\0';
                }
            }
        }
        for (int i = 0; alpha[i] != '\0'; i++) {
            printf("%c ", alpha[i]);
        }
        printf("%d\n", longest);
        
    }
}