#include <stdio.h>
#include "BuildTree.h"

int calcLen(Node *node) {
    int len = 0;
    while (node != NULL) {
        len++;
        node = node -> left;
    }
    return len;
}

Node *breakInHalf(Node *node, int n) {
    if (node == NULL || n < 2) return NULL;
    for (int i = 0; i < n / 2 + (n % 2) - 1; i++) {
        node = node -> left;
    }
    Node *ret = node -> left;
    node -> left = NULL;
    return ret;
}

Node* BuildTree(Node* list1, Node* list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    int n = calcLen(list1), m = calcLen(list2);
    if (list1 -> val < list2 -> val) {
        if (list1 -> left == NULL) list1 -> left = list2;
        else {
            list1 -> right = BuildTree(breakInHalf(list1 -> left, n - 1), breakInHalf(list2, m));
            list1 -> left = BuildTree(list1 -> left, list2);
        } 
        return list1;
    } else {
        if (list2 -> left == NULL) list2 -> left = list1;
        else {
            list2 -> right = BuildTree(breakInHalf(list1, n), breakInHalf(list2 -> left, m - 1));
            list2 -> left = BuildTree(list1, list2 -> left);
        }
        return list2;
    }
}