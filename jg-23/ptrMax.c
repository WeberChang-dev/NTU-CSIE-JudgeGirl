#include <limits.h>
#include "ptrMax.h"

int max(int *iptr[], int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++, iptr++) 
        if (**iptr > ans)
            ans = **iptr;
    return ans;
}