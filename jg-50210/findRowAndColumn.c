#include <stdio.h>
void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol) {
    for (int i = 0; ptr[i] != NULL; i++) {
        int pos = ptr[i] - start[i];
        ansRow[i] = pos / Col[i];
        ansCol[i] = pos % Col[i];
    }
}