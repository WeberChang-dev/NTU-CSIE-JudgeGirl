#include <stdio.h>
#include <string.h>

int main() {
    char str[100005], result[100005], newResult[100005];
    scanf("%s", str);
    strcpy(result, str);
    while (scanf("%s", str) != EOF) {
        strcpy(newResult, "");
        int i = 0, j = 0;
        for (i, j; str[i] != '\0' && result[j] != '\0';) {
            if (strncmp(str + i, result + j, 3) > 0) {
                strncat(newResult, result + j, 3);
                j += 3;
            } else {
                strncat(newResult, str + i, 3);
                i += 3;
            }
        }
        if (str[i] == '\0') strcat(newResult, result + j);
        else strcat(newResult, str + i);
        newResult[strlen(str) + strlen(result)] = '\0';
        strcpy(result, newResult);
        printf("%s\n", newResult);
    }
}