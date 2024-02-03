#include <stdio.h>
#include <string.h>

int main() {
    int ans = 0, prev = 130;
    char ch = '\0', *con = "qwrtypsdfghjklzxcvbnm";
    while (scanf("%c", &ch) != EOF) {
        if (strchr(con, ch) == NULL) continue;
        if (ch > prev) {
            ans++;
        }
        prev = ch;
    }
    printf("%d", ans);
}