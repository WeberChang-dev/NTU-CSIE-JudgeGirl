#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    char str1[85], str2[85];
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", str1, str2);
        if (!strcmp(str1, str2)) {
            printf("yes\n");
        } else if (strlen(str1) == strlen(str2)) {
            int flag = 0, wrong = 0, cnt1[30] = {}, cnt2[30] = {};
            for (int i = 1; i < strlen(str1); i++) {
                if (str1[i - 1] == str2[i - 1]) continue;
                if (str1[i] == str2[i - 1] && str1[i - 1] == str2[i]) {
                    if (flag) {
                        wrong = 1;
                        break;
                    } else {
                        flag = 1;
                        i++;
                    }
                } else {
                    wrong = 1;
                    break;
                }
            }
            for (int i = 0; str1[i] != '\0'; i++) {
                cnt1[str1[i] - 'a']++;
                cnt2[str2[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (cnt1[i] != cnt2[i]) {
                    wrong = 1;
                    break;
                }
            }
            if (wrong) printf("no\n");
            else printf("yes\n");
        } else if (abs(strlen(str1) - strlen(str2)) == 1) {
            int flag = 0, wrong = 0;
            for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++) {
                if (str1[i] == str2[j]) continue;
                if (flag) {
                    wrong = 1;
                    break;
                } else {
                    if (strlen(str1) < strlen(str2)) i--;
                    else j--;
                    flag = 1;
                }
            }
            if (wrong) printf("no\n");
            else printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}