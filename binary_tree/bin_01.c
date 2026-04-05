
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countInternalNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}
int countTotalNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}
int countLeaves(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    struct TreeNode *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("The No of interenal nodes are : %d.\n", countInternalNodes(root));
    printf("The No of Total nodes are : %d.\n", countTotalNodes(root));
    printf("The No of leaves nodes are : %d.\n", countLeaves(root));

    return 0;
}