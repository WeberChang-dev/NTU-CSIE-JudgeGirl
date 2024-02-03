#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isNum(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void solve(int **A[], int a, int *B[], int b, int C[], int c, char str[70]) {
    char *strs[4];
    strs[0] = strtok(str, " \t\n");
    if (strs[0] == NULL) {
        printf("0\n");
        return;
    }
    for (int i = 1; i < 4; i++) {
        strs[i] = strtok(NULL, " \t\n");
        if (strs[i] == NULL) {
            printf("0\n");
            return;
        }
    }
    if (strtok(NULL, " ") != NULL) {
        printf("0\n");
    } else if (((!strcmp(strs[0], "A") && !strcmp(strs[2], "B")) || 
        (!strcmp(strs[0], "B") && !strcmp(strs[2], "C"))) && 
        (isNum(strs[1]) && isNum(strs[3]))
    ) {
        if (!strcmp(strs[0], "A") && atoi(strs[1]) < a && atoi(strs[3]) < b) {
            A[atoi(strs[1])] = B + atoi(strs[3]);
            printf("1\n");
        } else if (!strcmp(strs[0], "B") && atoi(strs[1]) < b && atoi(strs[3]) < c) {
            B[atoi(strs[1])] = C + atoi(strs[3]);
            printf("1\n");
        } else {
            printf("0\n");
        }
    } else {
        printf("0\n");
    }
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
    char ch, str[70] = {'\0'};
    for (int i = 0; i < a; i++) A[i] = NULL;
    for (int i = 0; i < b; i++) B[i] = NULL;
    while (fgets(str, 70, stdin) != NULL) {
        solve(A, a, B, b, C, c, str);
    }
}