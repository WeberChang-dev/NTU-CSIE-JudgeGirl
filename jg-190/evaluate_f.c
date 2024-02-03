#include <limits.h>
#include "evaluate_f.h"

int f(int x, int y) {
    return 4 * x - 6 * y;
}

int evaluate_f(int *iptr[], int n, int *index) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (ans < f(iptr[i][0], iptr[i][1])) {
            ans = f(iptr[i][0], iptr[i][1]);
            *index = i;
        }
    }
    return ans;
}