#include <stdio.h>
#include <ctype.h>
int main() {
    char s[105];
    int cnt[30] = {};
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (islower(s[i])) {
            cnt[s[i] - 'a']++;
        } else if (isupper(s[i])) {
            cnt[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d\n", cnt[i]);
    }
}