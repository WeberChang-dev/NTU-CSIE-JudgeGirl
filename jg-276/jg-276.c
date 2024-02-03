#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char str[130], ab[130];
    int index = 0;
    ab[index] = '\0';
    while (scanf("%s", str) != EOF) {
        if (strcmp(str, "the") && strcmp(str, "and") && strcmp(str, "of") && strcmp(str, "at") && strcmp(str, "the.") && strcmp(str, "and.") && strcmp(str, "of.") && strcmp(str, "at.")) {
            ab[index] = toupper(str[0]);
            index++;
            ab[index] = '\0';
        }
        if (str[strlen(str) - 1] == '.') {
            printf("%s\n", ab);
            index = 0;
            strcpy(ab, "\0");
        }
    }
}