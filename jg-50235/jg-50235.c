#include <stdio.h>
#include <ctype.h>
#include <string.h>

int f(char *s) {
    int ret = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        ret += s[i];
    }
    return (ret % 1000);
}

int find(char ht[1000][4][21], char str[21]) {
    int num = f(str);
    for (int i = 0; i < 4; i++) {
        if (!strcmp(ht[num][i], str)) {
            return i;
        }
    }
    return -1;
}

void update(char ht[1000][4][21], int HT[1000][4], char str[21]) {
    int index = find(ht, str), num = f(str);
    if (index == -1) {
        for (int i = 0; i < 4; i++) {
            if (!strcmp(ht[num][i], "")) {
                strcpy(ht[num][i], str);
                HT[num][i] = 1;
                break;
            }
        }
    } else {
        HT[num][index]++;
    }
}

int main() {
    char *validChars = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_", ht[1000][4][21] = {'\0'}, str[21];
    int HT[1000][4] = {};
    while (scanf("%s", str) != EOF) {
        if (strspn(str, validChars) != strlen(str) || (!isalpha(str[0]) && str[0] != '_')) continue;
        update(ht, HT, str);
        printf("%s %d\n", str, HT[f(str)][find(ht, str)]);
    }
}