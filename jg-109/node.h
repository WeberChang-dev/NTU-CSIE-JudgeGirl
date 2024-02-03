#ifndef _NODE_H
#define _NODE_H
 
struct node {
    struct node *left;
    struct node *right;
    int data;
};
 
void print_all_paths(struct node *root);
void the_real_print_all_paths(struct node *root, int depth, int route[1005]);
 
#endif