#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *genNode(int data, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != NULL);
    node -> data = data;
    node -> left = left;
    node -> right = right;
    return node; 
}

int extractNum(char **str) {
    int ret = 0;
    while (isdigit(*(*str))) {
        ret = ret * 10 + *(*str) - '0';
        *str += 1;
    }
    return ret;
}

Node *buildTree(char **str) {
    if (**str != '(') return NULL;
    Node *node = genNode(0, NULL, NULL), *left, *right;
    int leftData, rightData;
    *str += 1; // (
    if (**str == '(') {
        left = buildTree(str);
        leftData = left -> data;
    } else {
        leftData = extractNum(str);
        left = genNode(leftData, NULL, NULL);
    }
    *str += 1; // ,
    if (**str == '(') {
        right = buildTree(str);
        rightData = right -> data;
    } else {
        rightData = extractNum(str);
        right = genNode(rightData, NULL, NULL);
    }
    *str += 1; // )
    node -> data = leftData + rightData;
    node -> left = left;
    node -> right = right;
    return node;
}

void traverse(Node *node, int type) {
    if (node == NULL) return;
    printf("%d\n", node -> data);
    if (type == 1) traverse(node -> left, 0);
    else traverse(node -> right, 1);
    printf("%d\n", node -> data);
    if (type == 1) traverse(node -> right, 0);
    else traverse(node -> left, 1);
}

int main() {
    char *str = (char *)malloc(sizeof(char) * 4005);
    scanf("%s", str);
    traverse(buildTree(&str), 1);
}