//Uses Edge List, takes O(mn) time
//Finds Shortest Path from source node to every other node in the graph.
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
struct EdgeListNode
{
    int i;
    int j;
    int weight;
    struct EdgeListNode *next;
};

void push(struct EdgeListNode **head_ref, int a, int b, int w)
{
    struct EdgeListNode *new_node = (struct EdgeListNode *)malloc(sizeof(struct EdgeListNode));
    new_node->i = a;
    new_node->j = b;
    new_node->weight = w;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void BellmanFord(struct EdgeListNode *EdgeList, int *ShortestDistances, int source, int n)
{
    for (int i = 0; i < n; i++)
    {
        ShortestDistances[i] = INT_MAX;
    }
    ShortestDistances[source] = 0;

    struct EdgeListNode *temp = NULL;
    for (int i = 0; i < n; i++) //->O(n)
    {
        temp = EdgeList;
        while (temp != NULL) //->O(m)
        {
            if (ShortestDistances[temp->j] > ShortestDistances[temp->i] + temp->weight)
            {
                ShortestDistances[temp->j] = ShortestDistances[temp->i] + temp->weight;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    struct EdgeListNode *EdgeList = NULL;
    int *ShortestDistances = malloc(n * sizeof(int));
    for (int k = 0; k < n; k++)
    {
        int i, j, w;
        printf("Enter i and j and weight: ");
        scanf("%d %d %d", &i, &j, &w);
        push(&EdgeList, i, j, w);
    }

    for (int i = 0; i < n; i++)
    {
        BellmanFord(EdgeList, ShortestDistances, i, n);
        for (int j = 0; j < n; j++)
        {
            printf("Shortest Distance from node %d to node %d is = %d", i, j, ShortestDistances[j]);
        }
    }
    return 0;
}