#include <stdio.h>
#include <ctype.h>
int main() {
    char str[105];
    int num[4] = {};
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) num[0]++;
        if (isalpha(str[i])) {
            num[1]++;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'
            ) num[2]++;
            else num[3]++;
        }
    }
    for (int i = 0; i < 4; i++) printf((i == 3) ? "%d" : "%d ", num[i]);
}