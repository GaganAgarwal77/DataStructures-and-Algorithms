//Uses Adjacency Matrix, takes O(n^3) time
//Finds Shortest Path between every pair of nodes in the graph.
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

void FloydWarshall(int **AdjacencyMatrix, int **ShortestDistances, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (AdjacencyMatrix[i][j] != 0)
                ShortestDistances[i][j] = AdjacencyMatrix[i][j];
            else
                ShortestDistances[i][j] = INT_MAX;
            if (i == j)
                ShortestDistances[i][j] == 0;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ShortestDistances[i][j] > ShortestDistances[i][k] + ShortestDistances[k][j])
                    ShortestDistances[i][j] = ShortestDistances[i][k] + ShortestDistances[k][j];
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int **AdjacencyMatrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        AdjacencyMatrix[i] = calloc(n, sizeof(int));
    }
    int **ShortestDistances = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        ShortestDistances[i] = calloc(n, sizeof(int));
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
            int num, w;
            printf("Enter its adjcaent edges and weight: ");
            scanf("%d %d", &num, &w);
            AdjacencyMatrix[node][num] = w;
        }
    }
    FloydWarshall(AdjacencyMatrix, ShortestDistances, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Shortest Distance from node %d to node %d is = %d", i, j, ShortestDistances[i][j]);
        }
    }
    return 0;
}