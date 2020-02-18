#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
};

struct Node* CreateNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->lc = NULL;
    node->rc = NULL;
    return node;
}

struct Node* ConstructBinaryTree(int* A,struct Node* root,int i,int n)
{
    if(i<n)
    {
        struct Node* temp = CreateNode(A[i]);
        root = temp;
        root->lc = ConstructBinaryTree(A,root->lc,2*i+1,n);
        root->rc = ConstructBinaryTree(A,root->rc,2*i+2,n);
    }
    return root;
}


int main()
{
    int n;
    scanf("%d",&n);
    int *arr= malloc(n*sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);
    struct Node* root = NULL; 
    root = ConstructBinaryTree(arr,root,0,n);
return 0;
}