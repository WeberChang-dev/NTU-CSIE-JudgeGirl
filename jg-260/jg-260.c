#include <stdio.h>
#include <string.h>
int main() {
    char str1[130], str2[130];
    scanf("%s", str1);
    while (scanf("%s", str2) != EOF) {
        int i = strlen(str1) - 1, j = 0, len = 0;
        char str3[130];
        for (i, j; i >= 0 && str2[j] != '\0'; i--, j++) {
            strncpy(str3, str2, j + 1);
            str3[j + 1] = '\0';
            if (!strcmp(str3, str1 + i)) {
                len = j + 1;
            }
        }
        strcat(str1, str2 + len);
    } 
    printf("%s", str1);
}