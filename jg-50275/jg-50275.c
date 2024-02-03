#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
int main() {
    char *suffix[25] = {
        "ed", "tion", "ness", "ful",
        "ing", "ly", "able", "ous",
        "ish", "ive", "less", "ism",
        "ist", "ize", "ment", "ship",
        "ary", "ical", "ence", "hood"
    }, str[100005];
    for (int i = 0; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (strcmp(suffix[j - 1], suffix[j]) > 0) {
                char *tmp = suffix[j - 1];
                suffix[j - 1] = suffix[j];
                suffix[j] = tmp;
            }
        }
    }
    int cnt[25] = {};
    while (fgets(str, 100005, stdin) != NULL) {
        char *token = strtok(str, " .,!?;:\n");
        while (token != NULL) {
            for (int i = 0; token[i] != '\0'; i++) token[i] = tolower(token[i]);
            for (int i = 0; i < 20; i++) {
                int cmp = strcmp(token + strlen(token) - strlen(suffix[i]), suffix[i]);
                if (cmp) continue;
                cnt[i]++;
            }
            token = strtok(NULL, " .,!?;:\n");
        }
    }
    for (int i = 0; i < 20; i++) {
        if (cnt[i])
            printf("%s:\nFrequency: %d\n", suffix[i], cnt[i]);
    }
}