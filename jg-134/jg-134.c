#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXN 1005

typedef struct node {
    int data;
    struct node *left, *right;
} TreeNode;

TreeNode *genNode(int data, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    assert(node != NULL);
    node -> data = data;
    node -> left = left;
    node -> right = right;
    return node;
}

TreeNode *buildTree(int data, int depth, int curDepth, TreeNode *curNode) {
    if (depth == curDepth) {
        TreeNode *node = genNode(data, NULL, NULL);
        return node;
    }
    if (curNode -> data > data) {
        curNode -> left = buildTree(data, depth, curDepth + 1, curNode -> left);
    } else {
        curNode -> right = buildTree(data, depth, curDepth + 1, curNode -> right);
    }
    return curNode;
}

int findDistance(TreeNode *curNode, int targetA, int targetB, int *ans) {
    if (curNode == NULL) return -1;
    int num, num2;
    if (targetA <= curNode -> data && targetB <= curNode -> data) {
        num = findDistance(curNode -> left, targetA, targetB, ans);
        if (targetA == curNode -> data || targetB == curNode -> data) {
            if (num != -1) {
                *ans = num;
                return -1;
            } else {
                return 1;
            }
        } else {
            return ((num == -1) ? -1 : num + 1);
        }
    } else if (targetA >= curNode -> data && targetB >= curNode -> data) {
        num = findDistance(curNode -> right, targetA, targetB, ans);
        if (targetA == curNode -> data || targetB == curNode -> data) {
            if (num != -1) {
                *ans = num;
                return -1;
            } else {
                return 1;
            }
        } else {
            return ((num == -1) ? -1 : num + 1);
        }
    } else {
        num = findDistance(curNode -> left, targetA, targetB, ans);
        num2 = findDistance(curNode -> right, targetA, targetB, ans);
        if (num != -1 && num2 != -1) {
            *ans = num + num2;
            return -1;
        } else if (num != -1 || num2 != -1) {
            return ((num == -1) ? 0 : num + 1) + ((num2 == -1) ? 0 : num2 + 1);
        } else {
            return -1;
        }
    }
}

int main() {
    int n, nodes[MAXN][MAXN], a, b, index[MAXN] = {}, ans = 0, *ansPtr = &ans, p;
    TreeNode *root;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        nodes[b][index[b]++] = a;
    }
    // printf("Tree Built");fflush(stdout);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < index[i]; j++) {
            if (i == 1) root = buildTree(nodes[i][j], i, 1, NULL);
            else buildTree(nodes[i][j], i, 1, root);
        }
    }
    scanf("%d", &p);
    while (p--) {
        scanf("%d%d", &a, &b);
        ans = 0;
        findDistance(root, a, b, ansPtr);
        printf("%d\n", ans);
    }
} 