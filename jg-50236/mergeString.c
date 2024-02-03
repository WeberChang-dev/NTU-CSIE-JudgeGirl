#include <stdio.h>
#include <string.h>

void mergeString(char** P, char L[26], char* A) {
    int index[205] = {}, maxIndex = -1, max = 30, in = 0;
    while (1) {
        max = 30, maxIndex = -1;
        for (int i = 0; P[i] != NULL; i++) {
            if (P[i][index[i]] == '\0') continue;
            int pos = strchr(L, P[i][index[i]]) - L;
            if (pos < max) {
                max = pos;
                maxIndex = i;
            }
        }
        if (max == 30) break;
        A[in] = P[maxIndex][index[maxIndex]];
        in++;
        index[maxIndex]++;
    }
}