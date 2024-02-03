#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "evaluateTree.h"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

bool theRealEvaluateTree(Node *root, int *values) {
    if (!strcmp(root -> val, "&&")) {
        return theRealEvaluateTree(root -> left, values) && theRealEvaluateTree(root -> right, values);
    } else if (!strcmp(root -> val, "||")) {
        return theRealEvaluateTree(root -> left, values) || theRealEvaluateTree(root -> right, values);
    } else if (!strcmp(root -> val, "!")) {
        return !theRealEvaluateTree(root -> left, values);
    } else {
        return values[root -> val[0] - 'A'] == 1;
    }
}

void evaluateTree(Node *root, int *values) {
    #ifdef LOWER
        if (theRealEvaluateTree(root, values)) printf("true\n");
        else printf("false\n");
    #endif

    #ifdef UPPER
        if (theRealEvaluateTree(root, values)) printf("TRUE\n");
        else printf("FALSE\n");
    #endif
}