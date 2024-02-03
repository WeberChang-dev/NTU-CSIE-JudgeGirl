#include <stdio.h>
int *secondLevel[100][100] = { NULL }, **firstLevel[100] = { NULL }, index = 0;
int ***constructTable(int A[], int B[]) {
    for (int i = 0; A[i] != 0; i++) {
        for (int j = 0; j < A[i]; j++) {
            secondLevel[i][j] = B + index;
            for (index; 1; index++) {
                if (B[index] == 0) {
                    index++;
                    break;
                }
            }
        }
        firstLevel[i] = secondLevel[i];
    }
    return firstLevel;
}