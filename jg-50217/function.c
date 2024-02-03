#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "function.h"

ListNode *genNode(int data, ListNode *prev, ListNode *next) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    assert(node != NULL);
    node -> data = data;
    node -> prev = prev;
    node -> next = next;
    return node;
}

void insert(LinkedList *list, int data) {
   if (list -> head == NULL && list -> tail == NULL) {
        ListNode *node = genNode(data, NULL, NULL);
        list -> head = node;
        list -> tail = node;
   } else {
        ListNode *iter = list -> head;
        for (iter; iter != NULL; iter = iter -> next) {
            if (iter -> data > data) break;
        }
        if (iter == list -> head) {
            ListNode *node = genNode(data, NULL, list -> head);
            list -> head -> prev = node;
            list -> head = node;
        } else if (iter == NULL) {
            ListNode *node = genNode(data, list -> tail, NULL);
            list -> tail -> next = node;
            list -> tail = node;
        } else {
            ListNode *node = genNode(data, iter -> prev, iter);
            iter -> prev -> next = node;
            iter -> prev = node;
        }
   }
}

void delete_head(LinkedList *list) {
    if (list -> head == NULL) return;
    ListNode *newHead = list -> head -> next;
    free(list -> head);
    list -> head = newHead;
    if (list -> head != NULL) list -> head -> prev = NULL;
    if (list -> head == NULL) list -> tail = NULL; 
}

void delete_tail(LinkedList *list) {
    if (list -> tail == NULL) return;
    ListNode *newTail = list -> tail -> prev;
    free(list -> tail);
    list -> tail = newTail;
    if (list -> tail == NULL) list -> head = NULL; 
    if (list -> tail != NULL) list -> tail -> next = NULL;
}