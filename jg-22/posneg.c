#include "posneg.h"
void posneg(int array[5][5], int result[2]) {
    int negCnt = 0, posCnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (array[i][j] < 0) negCnt++;
            if (array[i][j] > 0) posCnt++;
        }
    }
    result[0] = negCnt;
    result[1] = posCnt;
}