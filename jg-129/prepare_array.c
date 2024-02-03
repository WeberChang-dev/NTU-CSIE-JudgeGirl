#include "prepare_array.h"

void prepare_array(int buffer[], int *array[], int row, int column[]) {
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        array[i] = &buffer[cnt];
        cnt += column[i];
    }
}