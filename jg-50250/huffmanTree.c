#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "huffmanTree.h"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

Node *genNode(char symbol[SYM_MAX_LEN], int frequency, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != NULL);
    strcpy(node -> symbol, symbol);
    node -> frequency = frequency;
    node -> left = left;
    node -> right = right;
    return node;
}

int compare(const void *a, const void *b) {
    Node *nodeA = *(Node **)a;
    Node *nodeB = *(Node **)b;
    if (nodeA -> frequency != nodeB -> frequency) {
        return (nodeB -> frequency - nodeA -> frequency);
    } else {
        return strcmp(nodeB -> symbol, nodeA -> symbol);
    }
}

Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n) {
    Node *nodes[SYM_MAX_NUM], *tmp;
    int k = 0;
    bool found;
    for (int i = 0; i < n; ++i) {
        found = false;
        for (int j = 0; j < k; ++j) {
            if (!strcmp(s[i], nodes[j] -> symbol)) {
                found = true;
                nodes[j] -> frequency += 1;
                break;
            }
        }
        if (!found) {
            nodes[k++] = genNode(s[i], 1, NULL, NULL);
        }
    }
    qsort(nodes, k, sizeof(nodes[0]), compare);
    for (k; k > 1; --k) {
        nodes[k - 2] = genNode(
            strcmp(nodes[k - 1] -> symbol, nodes[k - 2] -> symbol) > 0 ? nodes[k - 2] -> symbol : nodes[k - 1] -> symbol,
            nodes[k - 1] -> frequency + nodes[k - 2] -> frequency,
            nodes[k - 2],
            nodes[k - 1]
        );
        for (int i = k - 2; i > 0 && (nodes[i] -> frequency > nodes[i - 1] -> frequency || (nodes[i] -> frequency == nodes[i - 1] -> frequency && strcmp(nodes[i] -> symbol, nodes[i - 1] -> symbol) > 0)); i--) {
            tmp = nodes[i];
            nodes[i] = nodes[i - 1];
            nodes[i - 1] = tmp;
        }
    }
    return nodes[0];
}