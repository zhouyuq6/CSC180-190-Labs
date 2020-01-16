#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode TreeNode;

int add(TreeNode **root,int val);
int print(TreeNode *root);

int add(TreeNode **root,int val){
    if (root==NULL){return -1;}

    if (*root==NULL){
        (*root)=(TreeNode*)malloc(sizeof(TreeNode));
	(*root)->val=val;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else{
        if(val<((*root)->val)){
            add(&((*root)->left),val);
        }
        else if(val>((*root)->val)){
            add(&((*root)->right),val);
        }
    }
    return 0;
}

int print(TreeNode *root){
    if(root==NULL){
	return -1;
    }
    else{
	print(root->left);
	printf("%d\n",root->val);
	print(root->right);
    }
    return 0;
}


