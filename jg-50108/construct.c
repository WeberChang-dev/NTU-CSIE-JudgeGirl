#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
#define MAXLENGTH 100 // comment when compile

int cmp(const void *a, const void *b) {
    int A = *(int *)a;
    int B = *(int *)b;
    return B - A;
}

int findKthMaxIndex(int arr[], int n) {
    int sorted[16385];
    for (int i = 0; i < n; i++) sorted[i] = arr[i];
    qsort(sorted, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) 
        if (arr[i] == sorted[MAXLENGTH - 1]) 
            return i;
}

Node *genNode(int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node -> value = value;
    node -> left = left;
    node -> right = right;
    return node;
}

Node* ConstructTree(int sequence[], int N) {
    if (N == 0 || sequence == NULL) return NULL;
    if (N < MAXLENGTH) {
       return genNode(sequence[N - 1], ConstructTree(sequence, N - 1), NULL);
    }
    int index = findKthMaxIndex(sequence, N);
    return genNode(sequence[index], ConstructTree(sequence, index), ConstructTree(sequence + index + 1, N - index - 1));
}