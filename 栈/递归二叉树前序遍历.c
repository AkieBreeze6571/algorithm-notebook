#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void prttree(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    result[*index] = root->val;
    (*index)++;
    
    prttree(root->left, result, index);

    prttree(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result;
    int index;

    result = (int*)malloc(sizeof(int) * 100);
    index = 0;

    prttree(root, result, &index);

    *returnSize = index;

    return result;
}