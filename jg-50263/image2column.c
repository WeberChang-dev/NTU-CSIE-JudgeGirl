#include "image2column.h"
#include <stdio.h>
void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]) {
    for (int i = 0, cnt1 = 0; i <= h - k; i++) {
        for (int j = 0; j <= w - k; j++, cnt1++) {
            for (int K = i, cnt2 = 0; K < i + k; K++) {
                for (int l = j; l < j + k; l++, cnt2++) {
                    colMatrix[cnt2][cnt1] = imgMatrix[K][l];
                }
            }
        }
    }
}