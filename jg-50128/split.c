#include <stdlib.h>
#include <stdio.h>

void split(int A[], int *a[], int *head[], int k) {
    int index[100005];
    for (int i = 0; i < k; i++) index[i] = -1;
    for (int i = 0; 1; i++) {
        if (head[A[i] % k] == NULL) {
            head[A[i] % k] = &A[i];
            index[A[i] % k] = i;
        } else {
            a[index[A[i] % k]] = &A[i];
            index[A[i] % k] = i;
        }
        if (a[i] == NULL) break;
    }
    for (int i = 0; i < k; i++) {
        if (index[i] != -1) {
            a[index[i]] = NULL;
        }
    }
}