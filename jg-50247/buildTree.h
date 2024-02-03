typedef struct Node
{
    char* val;
    struct Node *left, *right;
} Node;

Node* buildTree(char* expr);
void evaluateTree(Node *root, int *values);