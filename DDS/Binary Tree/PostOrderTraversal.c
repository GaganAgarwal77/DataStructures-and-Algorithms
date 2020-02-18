#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
};

void Postorder(struct Node* node)
{
    if(node != NULL)
    {
        Preorder(node->lc);
        Preorder(node->rc);
        Visit(node);
    }
}