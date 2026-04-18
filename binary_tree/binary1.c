#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

static int idx=-1;
struct Node* buildtree(int preorder[]){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    struct Node* root = createNode(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);

    return root;
}
//preorder traversal

void preorder(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d -> " ,root->val);
    preorder(root->left);
    preorder(root->right);


}

void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    printf("%d -> " ,root->val);
    preorder(root->right);


}

void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d -> " ,root->val);


}

int height(struct Node *root){
    if(root==NULL)return 0;
    int leftht=height(root->left);
    int rtht=height(root->right);
    return (leftht>rtht?leftht:rtht)+1;
}

int main()
{
    int pre_order[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1}; 
    struct Node* root=buildtree(pre_order);
    printf("The root value is : %d .\n", root->left->val); 
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    printf("The height of the binary tree is : %d\n",height(root));
    return 0;
}