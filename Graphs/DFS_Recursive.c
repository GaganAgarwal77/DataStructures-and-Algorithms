#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct AdjacencyListNode
{
    int i;
    struct AdjacencyListNode *next;
};

void push(struct AdjacencyListNode **head_ref, int new_data)
{
    struct AdjacencyListNode *new_node = (struct AdjacencyListNode *)malloc(sizeof(struct AdjacencyListNode));
    new_node->i = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void DFS(struct AdjacencyListNode **AdjacencyList, int *DT, int *FT, bool *Visited, int *Phi, int *count, int source, int n)
{

    printf("%d ", source);
    Visited[source] = true;
    DT[source] = (*count)++;
    struct AdjacencyListNode *temp = AdjacencyList[source];
    while (temp != NULL)
    {
        if (Visited[temp->i] == false)
        {
            Phi[temp->i] = source;
            DFS(AdjacencyList, DT, FT, Visited, Phi, count, temp->i, n);
        }
        temp = temp->next;
    }
    FT[source] = (*count)++;
}

void DFSUtil(struct AdjacencyListNode **AdjacencyList, int source, int n)
{
    bool *Visited = malloc(n * sizeof(int));
    int *Phi = malloc(n * sizeof(int));
    int *DiscoveryTime = malloc(n * sizeof(int));
    int *FinishTime = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        Phi[i] = -2;
        Visited[i] = false;
        DiscoveryTime[i] = 0;
        FinishTime[i] = 0;
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (Visited[i] == false)
        {
            Phi[i] = -1;
            DFS(AdjacencyList, DiscoveryTime, FinishTime, Visited, Phi, &count, i, n);
        }
    }
    printf("\nPhi[i], i, D[i], F[i] combinations are: \n");
    for (int i = 0; i < n; ++i)
        printf("(%d, %d, %d, %d) ", Phi[i], i, DiscoveryTime[i], FinishTime[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct AdjacencyListNode **AdjacencyList = malloc(n * sizeof(struct AdjacencyListNode *));
    for (int i = 0; i < n; i++)
    {
        AdjacencyList[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        int node;
        printf("Enter a number: ");
        scanf("%d", &node);
        printf("Enter its number of adjacent nodes: ");
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int num;
            printf("Enter its adjcaent edge number %d: ", j + 1);
            scanf("%d", &num);
            push(&AdjacencyList[node], num);
        }
    }

    for (int i = 0; i < n; i++)
    {
        struct AdjacencyListNode *temp = AdjacencyList[i];
        while (temp != NULL)
        {
            printf("i = %d j = %d\n", i, temp->i);
            temp = temp->next;
        }
    }

    DFSUtil(AdjacencyList, 0, n);
    return 0;
}