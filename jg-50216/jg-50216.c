#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int LCS(char s1[15], char s2[15], char s3[15]) {
    if (strlen(s1) == 0 || strlen(s2) == 0 || strlen(s3) == 0) return 0;
    int ret = 0;
    if (s1[0] == s2[0] && s1[0] == s3[0]) ret = max(ret, 1 + LCS(s1 + 1, s2 + 1, s3 + 1));
    else {
        ret = max(ret, LCS(s1 + 1, s2 + 1, s3 + 1));
        if (strchr(s2, s1[0]) != NULL && strchr(s3, s1[0]) != NULL) ret = max(ret,  1 + LCS(s1 + 1, strchr(s2, s1[0]) + 1, strchr(s3, s1[0]) + 1));
        if (strchr(s1, s2[0]) != NULL && strchr(s3, s2[0]) != NULL) ret = max(ret, 1 + LCS(strchr(s1, s2[0]) + 1, s2 + 1, strchr(s3, s2[0]) + 1));
        if (strchr(s1, s3[0]) != NULL && strchr(s2, s3[0]) != NULL) ret = max(ret, 1 + LCS(strchr(s1, s3[0]) + 1, strchr(s2, s3[0]) + 1, s3 + 1));
    }
    return ret;
}

int main() {
    char s1[15], s2[15], s3[15];
    while (scanf("%s%s%s", s1, s2, s3) != EOF) {
        printf("%d\n", LCS(s1, s2, s3));
    }
}