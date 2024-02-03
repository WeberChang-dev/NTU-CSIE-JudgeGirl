#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "buildTree.h"

Node *genNode(char *val, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != NULL);
    node -> val = (char *)malloc(sizeof(char) * 3);
    strcpy(node -> val, val);
    node -> left = left;
    node -> right = right;
    return node;
}

Node *theRealBuildTree(char strs[500005][3], int *index, int n) {
    if (*index >= n) return NULL;
    // printf("%d\n", *index);fflush(stdout);
    if (isalpha(strs[*index][0])) {
        Node *node = genNode(strs[*index], NULL, NULL);
        *index += 1;
        return node;
    } else if (strs[*index][0] == '(') {
        *index += 1;
        Node *leftNode = theRealBuildTree(strs, index, n);
        char op[3];
        strcpy(op, strs[*index]);
        *index += 1;
        Node *rightNode = theRealBuildTree(strs, index, n);
        *index += 1;
        Node *node = genNode(op, leftNode, rightNode);
        return node;
    } else if (strs[*index][0] == '!') {
        *index += 1;
        Node *leftNode = theRealBuildTree(strs, index, n);
        return genNode("!", leftNode, NULL);
    }
}

void traverse(Node *node) {
    printf("%d %s\n", node, node -> val);fflush(stdout);
    if (node -> left != NULL) {
        printf("Left: ");fflush(stdout);
        traverse(node -> left);
    }
    if (node -> right != NULL) {
        printf("Right: ");fflush(stdout);
        traverse(node -> right);
    }
}

Node* buildTree(char* expr) {
    char *ptr = strtok(expr, " \n\0"), strs[500005][3];
    int n = 0, index = 0, *indexPtr = &index;
    for (n; ptr != NULL; n++) {
        strcpy(strs[n], ptr);
        ptr = strtok(NULL, " \n\0");
    }
    Node *ret = theRealBuildTree(strs, indexPtr, n);
    // traverse(ret);
    return ret;
}