#include <stdio.h>
#include <string.h>

int main() {
    char S[1030], str[1015], newS[1030], A[505], B[505], deli[2] = {'\0'};
    scanf("%s", S);
    while (scanf("%s", str) != EOF) {
        if (!strcmp(str, "p")) {
            printf("%s\n", S);
        } else {
            strcpy(deli, "");
            strncpy(deli, str + 1, 1);
            deli[2] = '\0';
            strtok(str, deli);
            strcpy(A, strtok(NULL, deli));
            strcpy(B, strtok(NULL, deli));
            if (strstr(S, A) != NULL) {
                int index = strstr(S, A) - S;
                strcpy(newS, "");
                strncat(newS, S, index);
                newS[strlen(newS)] = '\0';
                strcat(newS, B);
                strcat(newS, S + index + strlen(A));
                strcpy(S, newS);
            }
        }
    }
}