#include <string.h>
#include <stdio.h>

void splitAndMap(char*** ptr, char* str) {
    char *ch = strtok(str, "*");
    int len[11] = {0}, cnt[11] = {0};
    for (int i = 0; ptr[i] != NULL; i++) {
        ptr[i][0] = NULL;
        len[i] = 0;
    }
    while (ch != NULL) {
        int curMin = 400005, curIndex= -1;
        for (int i = 0; ptr[i] != NULL; i++) {
            if (len[i] < curMin) {
                curIndex = i;
                curMin = len[i];
            }
        }
        ptr[curIndex][cnt[curIndex]] = ch;
        len[curIndex] += strlen(ch);
        cnt[curIndex]++;
        ptr[curIndex][cnt[curIndex]] = NULL;
        ch = strtok(NULL, "*");
    }
}