#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **AdjacencyMatrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        AdjacencyMatrix[i] = calloc(n, sizeof(int));
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
            printf("Enter its adjcaent edges: ");
            scanf("%d", &num);
            AdjacencyMatrix[node][num] = 1;
        }
    }
    return 0;
}