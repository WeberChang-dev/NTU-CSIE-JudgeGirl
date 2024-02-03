#include <stdio.h>
#include "sumOfIntegers.h"

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks) {
    int cnt = 0;
    for (int i = 0; 1; i++) {
        int sum = 0, head = cnt;
        for (cnt; ptrArray[cnt] != NULL; cnt++) {
            int repeated = 0;
            for (int j = head; j < cnt; j++) {
                if (ptrArray[j] == ptrArray[cnt]) {
                    repeated = 1;
                    break;
                }
            }
            if (!repeated) sum += *ptrArray[cnt];
        }
        cnt++;
        answer[i] = sum;
        if (ptrArray[cnt] == NULL) {
            *numberOfBlocks = i + 1;
            break;
        }
    }
}