#include <stdio.h>
#include <string.h>
#include "HuffmanDecoding.h"

void print(char *str) {
    #ifdef SPACE
        printf("%s ", str);
    #endif

    #ifdef NEWLINE
        printf("%s\n", str);
    #endif
}

char *decode(Node *node, char **data) {
    if (node -> left == NULL && node -> right == NULL) return node -> symbol;
    if (**data == '\0') return "FAIL";
    if (**data == '0') {
        *data += 1;
        return decode(node -> left, data); 
    } else {
        *data += 1;
        return decode(node -> right, data); 
    }
}

void HuffmanDecoding(Node *root, char *data) {
    char strs[100005][5], ret[5];
    int i;
    for (i = 0; *data != '\0'; ++i) {
        strcpy(ret, decode(root, &data));
        // print(ret);
        if (!strcmp(ret, "FAIL")) {
            print("-1");
            return;
        }
        else strcpy(strs[i], ret);
        // data += 1;
    }
    for (int j = 0; j < i; j++) {
        print(strs[j]);
    }
}