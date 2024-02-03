#include <stdio.h>
#include <stdlib.h>
#include "treeToList.h"

TreeNode *buildList(TreeNode *node, List *list) {
    if (node -> left == NULL && node -> right == NULL) {
        list -> tail = node;
        return node;
    }
    if (node -> value % 2) {
        TreeNode *leftNode = NULL;
        if (node -> right != NULL) {
            leftNode = buildList(node -> right, list);
        }
        if (node -> left != NULL) {
            if (leftNode == NULL) leftNode = buildList(node -> left, list);
            else list -> tail -> left = buildList(node -> left, list);
        }
        node -> right = NULL;
        node -> left = leftNode;
    } else {
        TreeNode *leftNode = NULL;
        if (node -> left != NULL) {
            leftNode = buildList(node -> left, list);
        }
        if (node -> right != NULL) {
            if (leftNode == NULL) leftNode = buildList(node -> right, list);
            else list -> tail -> left = buildList(node -> right, list);
        }
        node -> right = NULL;
        node -> left = leftNode;
    }
    return node;
}

List treeToListFunc(TreeNode * root) {
    List list;
    list.tail = NULL;
    list.head = root;
    buildList(root, &list);
    while (root != NULL) {
        if (root -> left == NULL) {
            list.tail = root;
            break;
        }
        root = root -> left;
    }
    return list;
}