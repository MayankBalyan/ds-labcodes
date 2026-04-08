//build heap
//heapify
//extract_max
#include<stdio.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//swap the values
void swap(int* a, int* b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

int main()
{
    
    return 0;
}