#include <stdio.h>
#include <string.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int distance(char str1[15], char str2[15]) {
    if (strlen(str1) == 0) return strlen(str2);
    if (strlen(str2) == 0) return strlen(str1);
    if (str1[0] == str2[0]) 
        return distance(str1 + 1, str2 + 1);
    if (str1[0] != str2[0])
        return 1 + min(distance(str1, str2 + 1), distance(str1 + 1, str2));
}

int main() {
    char strs[105][15];
    int index = 1, ans = INT_MAX, ID = INT_MAX;
    while (scanf("%s", strs[index]) != EOF) {
        for (int i = 1; i < index; i++) {
            int dis = distance(strs[i], strs[index]);
            if (dis < ans || (dis == ans && i * 1000 + index < ID)) {
                ans = dis;
                ID = i * 1000 + index;
            }
        }
        index++;
    }
    printf("%d %d %d", ans, ID / 1000, ID % 1000);
}