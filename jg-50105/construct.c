#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

int findBalanceIndex(int arr[], int n) {
    if (n < 3) return -1;
    long long G = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        G += arr[i] * i ;
        sum += arr[i];
    }
    if (G % sum) return -1;
    return G / sum;
}

Node *genNode(int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node -> value = value;
    node -> left = left;
    node -> right = right;
    return node;
}

Node *ConstructTree(int T[], int N) {
    if (N <= 0 || T == NULL) return NULL;
    int G = findBalanceIndex(T, N);
    if (G == -1) {
        Node *ret = genNode(T[N - 1], NULL, NULL), *node = ret, *prev = NULL;
        for (int i = N - 2; i >= 0; i--) {
            prev = node;
            node = genNode(T[i], NULL, NULL);
            prev -> left = node;
        }
        return ret;
    }
    return genNode(T[G], ConstructTree(T, G), ConstructTree(T + G + 1, N - G - 1));
}