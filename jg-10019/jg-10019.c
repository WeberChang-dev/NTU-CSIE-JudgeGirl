#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char str[105], ch;
    int head = 0, i = 0;
    while (scanf("%c", &ch) != EOF) { 
        if (!head && isspace(ch)) continue;
        if (!head && !isspace(ch)) head = 1;
        if (head && ch != '\n') {
            str[i] = ch;
            i++;
        } else {
            for (int j = i - 1; isspace(str[j]) && j >= 0; j--) {
                str[j] = '\0';
            }
            printf("%s\n", str);
            strcpy(str, "");
            i = head = 0;
        }
    }
    if (!strcmp(str, "")) {
        for (int j = i - 1; isspace(str[j]) && j >= 0; j--) {
            str[j] = '\0';
        }
        printf("%s", str);
    }
}