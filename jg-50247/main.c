#include <stdio.h>
#include "buildTree.h"

int main() {
    char str[100];
    while (fgets(str, 100, stdin) != NULL) {
        int values[30] = {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        // printf("UWU\n");fflush(stdout);
        Node *node = buildTree(str);
        evaluateTree(node, values);
        // printf("UWU\n");fflush(stdout);
    }
}