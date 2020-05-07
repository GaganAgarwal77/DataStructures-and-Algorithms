#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX 1147483647
#define swap(a, b) \
    {              \
        int(temp); \
        temp = a;  \
        a = b;     \
        b = temp;  \
    }
struct AdjacencyListNode
{
    int i;
    int weight;
    struct AdjacencyListNode *next;
};
struct HeapNode
{
    int node;
    int priority;
};
void push(struct AdjacencyListNode **head_ref, int new_data, int w)
{
    struct AdjacencyListNode *new_node = (struct AdjacencyListNode *)malloc(sizeof(struct AdjacencyListNode));
    new_node->i = new_data;
    new_node->weight = w;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void HeapNodeSwap(struct HeapNode **Heap, int i, int p)
{
    struct HeapNode *temp = Heap[i];
    Heap[i] = Heap[p];
    Heap[p] = temp;
}
void BottomUpHeapify(int i, struct HeapNode **Heap, int *indexes)
{
    int p = (i - 1) / 2;
    while (p >= 0 && Heap[p]->priority < Heap[i]->priority)
    {
        HeapNodeSwap(Heap, i, p);
        swap(indexes[Heap[i]->node], indexes[Heap[p]->node]);
        i = p;
        p = (i - 1) / 2;
    }
}

void TopDownHeapify(int i, int n, struct HeapNode **Heap, int *indexes)
{
    int l = 0;
    while (2 * i + 2 < n)
    {
        if (Heap[2 * i + 1]->priority > Heap[2 * i + 2]->priority)
            l = 2 * i + 1;
        else
            l = 2 * i + 2;
        if (Heap[i]->priority < Heap[l]->priority)
        {
            HeapNodeSwap(Heap, i, l);
            swap(indexes[Heap[i]->node], indexes[Heap[l]->node]);
            i = l;
        }
        else
            break;
    }
    if (2 * i + 1 < n && Heap[i]->priority < Heap[2 * i + 1]->priority)
    {
        int p = 2 * i + 1;
        HeapNodeSwap(Heap, i, p);
        swap(indexes[Heap[i]->node], indexes[Heap[p]->node]);
    }
}

void BuildHeap(struct HeapNode **Heap, int n, int *indexes)
{
    for (int i = n / 2; i >= 0; i--)
        TopDownHeapify(i, n, Heap, indexes);
}

int DeleteMax(struct HeapNode **Heap, int *n, int *indexes)
{
    int a = Heap[0]->node;
    HeapNodeSwap(Heap, 0, --(*n));
    swap(indexes[Heap[0]->node], indexes[Heap[*n]->node]);
    TopDownHeapify(0, *n, Heap, indexes);
    return a;
}
void IncreaseKey(int i, int data, struct HeapNode **Heap, int *indexes, int *n)
{
    Heap[i]->priority = data;
    BottomUpHeapify(i, Heap, indexes);
}

void PrimsAlgorithm(struct AdjacencyListNode **AdjacencyList, int source, int n)
{
    int a = n;
    int u;
    bool *Visited = malloc(n * sizeof(int));
    int *Phi = malloc(n * sizeof(int));
    int *indexes = malloc(n * sizeof(int));
    struct HeapNode **Heap = malloc(n * sizeof(struct HeapNode *));
    for (int i = 0; i < n; i++)
    {
        Heap[i] = (struct HeapNode *)malloc(sizeof(struct HeapNode));
        Heap[i]->node = i;
        Heap[i]->priority = -INT_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        Phi[i] = -2;
        Visited[i] = false;
        indexes[i] = i;
    }
    IncreaseKey(source, 0, Heap, indexes, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d ", Heap[i]->node, Heap[i]->priority);
    }
    printf("\n");
    Phi[source] = -1;
    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d %d ", Heap[i]->node, Heap[i]->priority);
        }
        printf("\n");
        u = DeleteMax(Heap, &n, indexes);
        Visited[u] = true;
        printf("u = %d, indexes[u] = %d , Heap[indexes[u]]->priority = %d\n", u, indexes[u], Heap[indexes[u]]->priority);
        for (int i = 0; i < n; i++)
        {
            printf("%d %d ", Heap[i]->node, Heap[i]->priority);
        }
        printf("\n");
        struct AdjacencyListNode *temp = AdjacencyList[u];
        while (temp != NULL)
        {
            printf("u = %d, v = %d, index[v] =%d index[u] = %d\n", u, temp->i, indexes[temp->i], indexes[u]);
            if (Visited[temp->i] == false)
            {
                printf("%d %d %d \n", Heap[indexes[temp->i]]->priority, Heap[indexes[u]]->priority, temp->weight);
                if (Heap[indexes[temp->i]]->priority < temp->weight)
                {
                    printf("Yes\n");
                    IncreaseKey(indexes[temp->i], temp->weight, Heap, indexes, &n);
                    for (int i = 0; i < n; i++)
                    {
                        printf("%d %d ", Heap[i]->node, Heap[i]->priority);
                    }
                    printf("\n");
                    Phi[temp->i] = u;
                }
            }
            temp = temp->next;
        }
    }
    int max_weight = 0;
    printf("\nPhi[i] and i combinations are: \n");
    for (int i = 0; i < a; ++i)
    {
        printf("(%d,%d)", Phi[i], i);
        max_weight += Heap[i]->priority;
    }
    printf("\n");
    printf("Weight of the Maximum Spanning Tree is : %d\n", max_weight);
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
        // printf("Enter a number: ");
        scanf("%d", &node);
        // printf("Enter its number of adjacent nodes: ");
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int num, w;
            // printf("Enter its adjcaent edge number %d and weight: ", j + 1);
            scanf("%d %d", &num, &w);
            push(&AdjacencyList[node], num, w);
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

    PrimsAlgorithm(AdjacencyList, 0, n);
    return 0;
}

/*Input:
5
0
2
1 10
2 1
1
4
0 10
2 4
4 5
3 8
2
3
0 1
1 4
4 3
3
2
1 8
4 2
4
3
1 5
2 3
3 2
*/