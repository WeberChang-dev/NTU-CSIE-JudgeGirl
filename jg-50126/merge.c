#include <stdio.h> 

void merge(int A[], int B[], int* a[], int* b[]) {
    int **prevPtr, aIndex = 0, bIndex = 0, n = 0, m = 0;
    for (int i = 0; a[i] != NULL; i++) n++;
    for (int i = 0; b[i] != NULL; i++) m++;
    if (A[0] > B[0]) {
        prevPtr = &b[0];
        bIndex = 1;
    } else {
        prevPtr = &a[0];
        aIndex = 1;
    }
    while (1) {
        if (*prevPtr == NULL) {
            if (prevPtr == &a[n]) {
                for (bIndex; bIndex <= m; bIndex++) {
                    *prevPtr = &B[bIndex];
                    prevPtr = &b[bIndex];
                }
                b[m] = NULL;
            } else {
                for (aIndex; aIndex <= n; aIndex++) {
                    *prevPtr = &A[aIndex];
                    prevPtr = &a[aIndex];
                }
                a[n] = NULL;
            }
            break;
        }
        if (A[aIndex] > B[bIndex]) {
            *prevPtr = &B[bIndex];
            prevPtr = &b[bIndex];
            bIndex++;
        } else {
            *prevPtr = &A[aIndex];
            prevPtr = &a[aIndex];
            aIndex++;
        }
    }
}