#include <stdio.h>
#include "tree.h"

void traversal(Node *root, int N, int command[]) {
    Node *path[1005], *curNode = root;
    int pathIndex = 0;
    for (int i = 0; i < N; i++) path[i] = NULL;
    for (int i = 0; i < N; i++) {
        if (command[i] == 0) {
            printf("%d\n", curNode -> label);
            return;
        }
        else if (command[i] == 1) {
            printf("%d\n", curNode -> label);
        } else if (command[i] == 2) {
            if (pathIndex == 0) {
                printf("%d\n", curNode -> label);
                return;
            }
            curNode = path[pathIndex - 1];
            pathIndex--;
        } else if (command[i] == 3) {
            if (curNode -> left == NULL) {
                printf("%d\n", curNode -> label);
                return;
            }
            path[pathIndex] = curNode;
            curNode = curNode -> left;
            pathIndex++;
        } else if (command[i] == 4) {
            if (curNode -> right == NULL) {
                printf("%d\n", curNode -> label);
                return;
            }
            path[pathIndex] = curNode;
            curNode = curNode -> right;
            pathIndex++;
        } else {
            if (pathIndex == 0) {
                printf("%d\n", curNode -> label);
                return;
            }
            if (
                (path[pathIndex - 1] -> left == curNode && path[pathIndex - 1] -> right == NULL) ||
                (path[pathIndex - 1] -> right == curNode && path[pathIndex - 1] -> left == NULL)
            ) {
                printf("%d\n", curNode -> label);
                return;
            }
            if (path[pathIndex - 1] -> left == curNode) curNode = path[pathIndex - 1] -> right;
            else curNode = path[pathIndex - 1] -> left;
        }
    }
}