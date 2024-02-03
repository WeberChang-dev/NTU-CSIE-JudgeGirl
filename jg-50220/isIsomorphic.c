#include <stdio.h>
#include <stdbool.h>
#include "isIsomorphic.h"

bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (!(root1 != NULL && root2 != NULL)) return false;
    TreeNode *children1[3] = { root1 -> left, root1 -> mid, root1 -> right}, *children2[3] = { root2 -> left, root2 -> mid, root2 -> right };
    for (int i = 0; i < 3; i++) {
        bool used[3] = { false };
        used[i] = true;
        for (int j = 0; j < 3; j++) {
            if (used[j]) continue;
            used[j] = true;
            for (int k = 0; k < 3; k++) {
                if (used[k]) continue;
                if (isIsomorphic(children1[0], children2[i]) && isIsomorphic(children1[1], children2[j]) && isIsomorphic(children1[2], children2[k])) {
                    return true;
                }
            }
            used[j] = false;
        }
        used[i] = false;
    }
    return false;
}