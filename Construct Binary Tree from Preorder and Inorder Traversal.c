#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd) {
    
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, k - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, k + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {
    
    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1);
}

void printLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        if (curr) {
            printf("%d ", curr->val);
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        } else {
            printf("null ");
        }
    }
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Level Order Output:\n");
    printLevelOrder(root);

    return 0;
}