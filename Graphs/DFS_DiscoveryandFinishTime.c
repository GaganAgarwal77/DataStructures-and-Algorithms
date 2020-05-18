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

void DFS(struct AdjacencyListNode **AdjacencyList, int source, int n)
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
        int *Stack = malloc(n * sizeof(int));
        int top = 0;
        if (Visited[i] == false)
        {
            Phi[i] = -1;
            Stack[top] = i;
        }
        while (top >= 0)
        {
            int node = Stack[top--];
            if (Visited[node] == false)
            {
                printf("%d ", node);
                Visited[node] = true;
                Stack[++top] = node;
                DiscoveryTime[node] = count++;
                struct AdjacencyListNode *temp = AdjacencyList[node];
                while (temp != NULL)
                {
                    if (Visited[temp->i] == false)
                    {
                        Phi[temp->i] = node;
                        Stack[++top] = temp->i;
                    }
                    temp = temp->next;
                }
            }
            else if (FinishTime[node] == 0)
            {
                FinishTime[node] = count++;
            }
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

    DFS(AdjacencyList, 0, n);
    return 0;
}