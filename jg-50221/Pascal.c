#include <stdio.h>
#include "Pascal.h"

void build_Pascal(Node* node_array, int height) {
    int index = 0;
    node_array[0].value = 1;
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < i; j++, index++) {
            if (j == i - 1) node_array[index].left = node_array[index].right = NULL;
            else {
                node_array[index].left = node_array + index + i;
                node_array[index].left -> value += node_array[index].value;
                node_array[index].right = node_array + index + 1;
                node_array[index].right -> value += node_array[index].value;
            }
        }
    }
}