#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
};

void Inorder(struct Node* node)
{
    if(node != NULL)
    {
        Inorder(node->lc);
        printf("%d ",node->data);
        Inorder(node->rc);
    }
}
void IterativeInorder(struct Node* node)
{
    struct Node* Stack[1000]; //= calloc(1000,sizeof(int));
    int *B =  calloc(1000,sizeof(int));
    if(node != NULL)
    {
        int top =  -1;
        Stack[++top] = node;
        B[top] = 0;
        while(top >= 0)
        {
            if(B[top] == 1)
                printf("%d ",Stack[top--]->data);
            else
            {
                node = Stack[top--];
                if(node->rc != NULL)
                {
                    Stack[++top] = node->rc;
                    B[top] = 0;
                }
                Stack[++top] = node;
                B[top] = 1; 
                if(node->lc != NULL)
                {
                    Stack[++top] = node->lc;
                    B[top] = 0;
                }
            }
        }
    }
} 

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
    Inorder(root);
    printf("\n");
    IterativeInorder(root);
return 0;
}