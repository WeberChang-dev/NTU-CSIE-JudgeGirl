#include "fill_array.h"

void fill_array(int *ptr[], int n) {
    int m = ptr[n - 1] - ptr[0], val[m + 5], left = 0, rightIndex = -1, right[n + 5];
    for (int i = 0; i <= m; i++) val[i] = -1;
    for (int i = 0; i < n; i++) val[ptr[i] - ptr[0]] = i;
    for (int i = 1, j = 0; i <= m; i++) {
        if (val[i] != -1) {
            right[j] = val[i];
            j++;
        }
    }
    for (int i = 0; i <= m; i++) {
        if (val[i] == -1) {
            val[i] = left + right[rightIndex];
        } else if (val[i] != -1) {
            left = val[i];
            rightIndex++;
        }
        *(ptr[0] + i) = val[i];
    }
}