#include <stdio.h>
#include "node.h"

struct node *getNode(struct node *head, unsigned int i) {
    int n = 0;
    for (struct node *cur = head; cur != NULL; cur = cur -> next) {
        n++;
    }
    if (i >= n) return NULL;
    for (int it = 0; it < n - i - 1; it++) {
        head = head -> next;
    }
    return head;
}