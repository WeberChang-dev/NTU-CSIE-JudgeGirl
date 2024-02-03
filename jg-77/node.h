#ifndef _NODE_H
#define _NODE_H
 
struct node {
       struct node *next;
};

struct node *getNode(struct node *head, unsigned int i);
 
#endif