#include <stdio.h>
#include <string.h>

void findQ(char *str, int *ans) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '?') {
            *ans += 1;
        }
    }
}

void findIfWhileForCase(char *str, int *ans, char *keyword, int len) {
    if (!strcmp(str, keyword)) {
        *ans += 1;
        return;
    }
    int slen = strlen(str);
    for (int i = 0; i + len < slen; i++) {
        if (!strncmp(str + i, keyword, len) && str[i + len] == '(') {
            if (i != 0 && (str[i - 1] == ')' || str[i - 1] == '{' || str[i - 1] == ';') && str[i + strlen(keyword)] == '(') {
                *ans += 1;
            } else if (i == 0 && str[i + len] == '(') {
                *ans += 1;
            }
        }
    }
}

int main() {
    int ans = 0, preKey = 0;
    char str[1000];
    while (scanf("%s", str) != EOF) {
        findQ(str, &ans);
        findIfWhileForCase(str, &ans, "case", 4);
        findIfWhileForCase(str, &ans, "while", 5);
        findIfWhileForCase(str, &ans, "if", 2);
        findIfWhileForCase(str, &ans, "for", 3);
    }
    printf("%d", ans);
}