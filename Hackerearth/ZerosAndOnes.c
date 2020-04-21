#include <stdio.h>
#include <stdlib.h>

void Update(int *Array, int *BIT, int i, int x, int n)
{
    int temp = x;
    x = x - Array[i];
    Array[i] = temp;

    while (i <= n)
    {
        BIT[i] += x;
        i += i & (-i);
    }
}
void Increase(int *Array, int i, int x, int n)
{
    while (i <= n)
    {
        Array[i] += x;
        i += i & (-i);
    }
}
void BuildBIT(int *Array, int *BIT, int n)
{
    for (int i = 1; i <= n; i++)
        Increase(BIT, i, Array[i], n);
}

int PrefixSum(int *BIT, int i)
{
    int sum = 0;
    while (i > 0)
    {
        // printf("sum = %d i = %d\n", sum, i);
        sum += BIT[i];
        i -= i & (-i);
    }
    return sum;
}

int FindKthOne(int *Array, int n, int k)
{
    int s = 1;
    int e = n + 1;
    while (s < e)
    {
        int m = s + ((e - s) / 2);

        if (PrefixSum(Array, m) < k)
        {
            s = m + 1;
        }
        else
        {
            e = m;
        }
    }
    if (s > n)
        s = -1;

    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    int num_ops;
    scanf("%d", &num_ops);
    int *array = calloc(n + 1, sizeof(int));
    int *BinaryIndexTree = calloc(n + 1, sizeof(int));
    array[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        array[i] = 1;
    }
    BuildBIT(array, BinaryIndexTree, n + 1);

    // for (int i = 0; i <= n; i++)
    //     printf("%d ", BinaryIndexTree[i]);

    // printf("\n");
    // array[5] = 0;
    // array[9] = 0;

    // printf("Prefix Sum : %d\n", PrefixSum(BinaryIndexTree, 5));
    // printf("%d\n", FindKthOne(BinaryIndexTree, n + 1, 2));
    for (int i = 0; i < num_ops; i++)
    {
        int op_type, value;
        scanf("%d %d", &op_type, &value);
        if (op_type == 0)
        {
            Update(array, BinaryIndexTree, value, 0, n);
            // for (int i = 0; i < n; i++)
            // {
            //     printf("%d", array[i]);
            // }

            // printf("\n");

            // for (int i = 0; i <= n; i++)
            //     printf("%d ", BinaryIndexTree[i]);

            // printf("\n");
        }
        else
        {
            printf("%d\n", FindKthOne(BinaryIndexTree, n, value));
        }
    }
    // //Update(BinaryIndexTree,2,-1,n);
    // Update(BinaryIndexTree,2,-BinaryIndexTree[2],n);
    //Update(BinaryIndexTree,2,0,n);
    // printf("%d\n", FindKthOne(BinaryIndexTree, n, 5));

    // // printf("\n");

    // Update(array, BinaryIndexTree, 2, 0, n);
    // Update(array, BinaryIndexTree, 2, 0, n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d", array[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", BinaryIndexTree[i]);
}