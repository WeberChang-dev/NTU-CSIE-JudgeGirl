#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void clear(int alphaToNum[30]) {
    for (int i = 0; i <= 26; i++) alphaToNum[i] = -1;
}

unsigned long long convert(char str[20], int n, int alphaToNum[30]) {
    unsigned long long ret = 0;
    for (int i = 0; i < n; i++, ret *= 10) {
        if (isalpha(str[i])) {
            ret += alphaToNum[str[i] - 'A'];
        } else {
            ret += str[i] - '0';
        }
    }
    return ret / 10;
}

void printConvert(char str[20], int n, int alphaToNum[30]) {
    for (int i = 0; i < n; i++) {
        if (isalpha(str[i])) printf("%d", alphaToNum[str[i] - 'A']);
        else printf("%c", str[i]);
    }
}

void doAppeared(char str[20], int appeared[30]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) 
            appeared[str[i] - 'A'] = 1;
    }
}

bool puzzle(char num1[20], char num2[20], char ans[30], int n, int appeared[30], int alphaToNum[30]) {
    if (n == 'Z' - 'A' + 1) {
        unsigned long long n1, n2, a;
        n1 = convert(num1, strlen(num1), alphaToNum);
        n2 = convert(num2, strlen(num2), alphaToNum);
        a = convert(ans, strlen(ans), alphaToNum);
        // printf("%d %d %d\n", n1, n2, a);
        return (n1 * n2 == a);
    }
    if (!appeared[n] || (appeared[n] && alphaToNum[n] != -1)) {
        if (puzzle(num1, num2, ans, n + 1, appeared, alphaToNum))
            return true;
    }
    else {
        for (int i = 0; i < 10; i++) {
            alphaToNum[n] = i;
            if (puzzle(num1, num2, ans, n + 1, appeared, alphaToNum))
                return true;
            alphaToNum[n] = -1;
        }
    }
    return false;
}

int main() {
    char num1[20], num2[20], ans[20];
    int alphaToNum[30], appeared[30] = {};
    scanf("%s%s%s", num1, num2, ans);
    doAppeared(num1, appeared);
    doAppeared(num2, appeared);
    doAppeared(ans, appeared);
    clear(alphaToNum);
    puzzle(num1, num2, ans, 0, appeared, alphaToNum);
    printConvert(num1, strlen(num1), alphaToNum);
    printf(" x ");
    printConvert(num2, strlen(num2), alphaToNum);
    printf(" = ");
    printConvert(ans, strlen(ans), alphaToNum);
    printf("\n");
}