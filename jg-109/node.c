#include <stdio.h>
#include "node.h"

void the_real_print_all_paths(struct node *root, int depth, int route[1005]) {
    if (root == NULL) return;
    route[depth] = root -> data;
    if (root -> left == NULL && root -> right == NULL) {
        for (int i = 0; i <= depth; i++) {
            printf("%d ", route[i]);
        }
        printf("\n");
        return;
    }
    the_real_print_all_paths(root -> left, depth + 1, route);
    the_real_print_all_paths(root -> right, depth + 1, route);
}

void print_all_paths(struct node *root) {
    int route[1005] = {};
    the_real_print_all_paths(root, 0, route);
}