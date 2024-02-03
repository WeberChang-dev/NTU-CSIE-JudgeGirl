#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int findVarIndex(int n, char *str, char var[55][35]) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(str, var[i])) {
            return i;
        }
    }
}

int extractNum(char **str) {
    int ret = 0;
    while (isdigit(*(*str))) {
        ret = ret * 10 + *(*str) - '0';
        *str += 1;
    }
    return ret;
}

int expression(int n, char **str, char var[55][35], int val[55]) {
    if (**str != '(') return 0;
    *str += 2;
    char op = **str;
    *str += 2;
    int left, right;
    if (**str == '(') left = expression(n, str, var, val);
    else if (isdigit(**str)) left = extractNum(str);
    else {
        char tmp[35];
        strcpy(tmp, "");
        for (str; **str != ' '; *str += 1) {
            strncat(tmp, *str, 1);
            strcat(tmp, "\0");
        }
        left = val[findVarIndex(n, tmp, var)];
    }
    *str += 1;
    if (**str == '(') right = expression(n, str, var, val);
    else if (isdigit(**str)) right = extractNum(str);
    else {
        char tmp[35];
        strcpy(tmp, "");
        for (; **str != ' '; *str += 1) {
            strncat(tmp, *str, 1);
            strcat(tmp, "\0");
        }
        right = val[findVarIndex(n, tmp, var)];
    }
    *str += 2;
    if (op == '+') return right + left;
    if (op == '-') return left - right;
    if (op == '*') return left * right;
    return left / right;
}

int main() {
    char str[35], *tree = (char *)malloc(sizeof(char) * 1005), var[55][35];
    int n = 0, val[55];
    fgets(tree, 1005, stdin);
    for (int i = 0; tree[i] != '\0' && tree[i] != '\n'; i++) {
        if (tree[i] == '(' || tree[i] == ')' || tree[i] == ' ' || tree[i] == '+' || tree[i] == '-' || tree[i] == '*' || tree[i] == '/' || isdigit(tree[i])) continue;
        strcpy(str, "");
        for (i; tree[i] != ' '; i++) {
            strncat(str, tree + i, 1);
            strcat(str, "\0");
        }
        strcpy(var[n++], str);
    }
    while (scanf("%s", str) != EOF) {
        int index = findVarIndex(n, str, var);
        scanf("%s", str);
        scanf("%s", str);
        val[index] = atoi(str);
    }
    printf("%d", tree[0] != '(' ? extractNum(&tree) : expression(n, &tree, var, val));
}