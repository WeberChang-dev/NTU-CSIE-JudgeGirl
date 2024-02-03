#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int abs(int x) { return x < 0 ? -x : x; }

int main() {
    char str[1005];
    while (1) {
        scanf("%s", str);
        if (!strcmp(str, "-1")) break;
        bool flags[4] = { false };
        int sum = 0, oddSum = 0, evenSum = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            flags[0] = (str[i] - '0') % 2 == 0;
            flags[2] = (str[i] - '0') % 5 == 0;
            if (i % 2) oddSum += str[i] - '0';
            else evenSum += str[i] - '0';
            sum += str[i] - '0';
        }
        flags[1] = (sum % 3) == 0;
        flags[3] = (abs(oddSum - evenSum) % 11) == 0;
        for (int i = 0; i < 3; i++) printf(flags[i] ? "yes " : "no ");
        printf(flags[3] ? "yes" : "no");
        printf("\n");
    }
}