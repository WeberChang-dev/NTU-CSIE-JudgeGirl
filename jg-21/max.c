#include "max.h"
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int max(int arr[5][5]) {
    int ret = -1000000000;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ret = MAX(ret, arr[i][j]);
        }
    }
    return ret;
}