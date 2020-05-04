#include <stdio.h>
#include <stdlib.h>

struct EdgeListNode
{
    int i;
    int j;
    struct EdgeListNode *next;
};

void push(struct EdgeListNode **head_ref, int a, int b)
{
    struct EdgeListNode *new_node = (struct EdgeListNode *)malloc(sizeof(struct EdgeListNode));
    new_node->i = a;
    new_node->j = b;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    int n;
    scanf("%d", &n);
    struct EdgeListNode *EdgeList = NULL;
    for (int k = 0; k < n; k++)
    {
        int i, j;
        printf("Enter i and j: ");
        scanf("%d %d", &i, &j);
        push(&EdgeList, i, j);
    }
    return 0;
}