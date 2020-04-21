#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BuildMinSegmentTree(int *Array, int *SegmentTree, int n)
{
    for (int i = 0; i < n; i++)
        SegmentTree[n + i - 1] = i;

    for (int i = n - 2; i >= 0; i--)
    {
        if (Array[SegmentTree[2 * i + 1]] > Array[SegmentTree[2 * i + 2]])
            SegmentTree[i] = SegmentTree[2 * i + 2];
        else
            SegmentTree[i] = SegmentTree[2 * i + 1];
    }
}
void BuildMaxSegmentTree(int *Array, int *SegmentTree, int n)
{
    for (int i = 0; i < n; i++)
        SegmentTree[n + i - 1] = i;

    for (int i = n - 2; i >= 0; i--)
    {
        if (Array[SegmentTree[2 * i + 1]] < Array[SegmentTree[2 * i + 2]])
            SegmentTree[i] = SegmentTree[2 * i + 2];
        else
            SegmentTree[i] = SegmentTree[2 * i + 1];
    }
}

void UpdateInMinSegmentTree(int *Array, int *SegmentTree, int i, int x, int n)
{
    Array[i] = x;
    i = (n + i - 2) / 2;
    while (i > 0)
    {
        if (Array[SegmentTree[2 * i + 1]] > Array[SegmentTree[2 * i + 2]])
        {
            SegmentTree[i] = SegmentTree[2 * i + 2];
        }
        else
        {
            SegmentTree[i] = SegmentTree[2 * i + 1];
        }

        i = (i - 1) / 2;
    }

    if (Array[SegmentTree[1]] > Array[SegmentTree[2]])
        SegmentTree[0] = SegmentTree[2];
    else
        SegmentTree[0] = SegmentTree[1];
}
void UpdateInMaxSegmentTree(int *Array, int *SegmentTree, int i, int x, int n)
{
    Array[i] = x;
    i = (n + i - 2) / 2;
    while (i > 0)
    {
        if (Array[SegmentTree[2 * i + 1]] < Array[SegmentTree[2 * i + 2]])
        {
            SegmentTree[i] = SegmentTree[2 * i + 2];
        }
        else
        {
            SegmentTree[i] = SegmentTree[2 * i + 1];
        }

        i = (i - 1) / 2;
    }

    if (Array[SegmentTree[1]] < Array[SegmentTree[2]])
        SegmentTree[0] = SegmentTree[2];
    else
        SegmentTree[0] = SegmentTree[1];
}

int ReturnMinimumQueryUtility(int *Array, int *SegmentTree, int i, int j, int s, int e, int p, int n)
{
    if (j < s || i > e)
        return n;
    if (i <= s && e <= j)
        return SegmentTree[p];

    int m = (s + e) / 2;

    int left = ReturnMinimumQueryUtility(Array, SegmentTree, i, j, s, m, 2 * p + 1, n);
    int right = ReturnMinimumQueryUtility(Array, SegmentTree, i, j, m + 1, e, 2 * p + 2, n);
    //if(left < right)

    if (Array[left] < Array[right])
        return left;
    else
        return right;
}

int ReturnMinimumQuery(int *Array, int *SegmentTree, int i, int j, int n)
{
    int min = ReturnMinimumQueryUtility(Array, SegmentTree, i, j, 0, n - 1, 0, n);
    //printf("%d\n",min);
    return min;
}

int ReturnMaximumQueryUtility(int *Array, int *SegmentTree, int i, int j, int s, int e, int p, int n)
{
    if (j < s || i > e)
        return n + 1;

    if (i <= s && e <= j)
        return SegmentTree[p];

    int m = (s + e) / 2;

    int left = ReturnMaximumQueryUtility(Array, SegmentTree, i, j, s, m, 2 * p + 1, n);
    int right = ReturnMaximumQueryUtility(Array, SegmentTree, i, j, m + 1, e, 2 * p + 2, n);
    //if(left > right)
    if (Array[left] > Array[right])
        return left;
    else
        return right;
}

int ReturnMaximumQuery(int *Array, int *SegmentTree, int i, int j, int n)
{
    int max = ReturnMaximumQueryUtility(Array, SegmentTree, i, j, 0, n - 1, 0, n);
    //printf("%d\n",max);
    return max;
}

int Query(int *min_array, int *max_array, int *MinSegmentTree, int *MaxSegmentTree, int n, int x, int c)
{
    int s = 0;
    int e = n - x;
    int m = (s + e) / 2;
    int flag;
    while (s < e)
    {
        m = (s + e) / 2;
        // printf("x = %d m = %d\n", x, m);
        // printf("x+m<n\n");
        int max = ReturnMaximumQuery(max_array, MaxSegmentTree, x, x + m - 1, n);
        int min = ReturnMinimumQuery(min_array, MinSegmentTree, x, x + m - 1, n);
        // printf("min = %d max =%d\n", min, max);
        if (min_array[min] >= (min_array[x] - c) && max_array[max] <= (max_array[x] + c))
        {
            // printf("len  = %d\n", m + 1);
            s = m + 1;
            flag = 1;
        }
        else
        {
            e = m;
            flag = 0;
        }
    }
    if (flag)
        return m;
    else
        return m - 1;
}

int MinimumZ(int *min_array, int *max_array, int *MinSegmentTree, int *MaxSegmentTree, int n, int x, int m)
{
    int max = ReturnMaximumQuery(max_array, MaxSegmentTree, x, x + m, n);
    int min = ReturnMinimumQuery(min_array, MinSegmentTree, x, x + m, n);
    int a = max_array[max] - max_array[x];
    int minZ = min_array[x] - min_array[min];

    if (a >= minZ)
        minZ = a;

    return minZ;
}

int main()
{
    int num, num_ops;
    scanf("%d %d", &num, &num_ops);
    int k = num;
    int nearestPowerOf2 = 1;
    while (k > 0)
    {
        k = k / 2;
        nearestPowerOf2 *= 2;
    }
    int n = nearestPowerOf2;
    // printf("n = %d , num = %d\n", n, num);
    int *min_array = (int *)calloc(n, sizeof(int));
    int *max_array = (int *)calloc(n, sizeof(int));
    int *MinSegmentTree = (int *)calloc(2 * n, sizeof(int));
    int *MaxSegmentTree = (int *)calloc(2 * n, sizeof(int));

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &max_array[i]); //4 7 3 2 8 12 1 16
        min_array[i] = max_array[i];
    }
    for (int i = num; i < n; i++)
    {
        min_array[i] = -1073741824;
        max_array[i] = 1073741824; //2^30;
    }
    min_array[n] = 1073741824;
    max_array[n] = -1073741824;

    BuildMinSegmentTree(min_array, MinSegmentTree, n);
    BuildMaxSegmentTree(max_array, MaxSegmentTree, n);
    for (int i = 0; i < num_ops; i++)
    {
        char op_type[1];
        int x;
        int value;
        scanf("%s %d %d", op_type, &x, &value);

        if (op_type[0] == 'U')
        {
            if (max_array[x - 1] == value || min_array[x - 1] == value)
                continue;
            else
            {
                UpdateInMaxSegmentTree(max_array, MaxSegmentTree, x - 1, value, n);
                UpdateInMinSegmentTree(min_array, MinSegmentTree, x - 1, value, n);
            }
        }
        else
        {
            if (value < 0)
            {
                printf("-1 -1\n");
            }
            else
            {
                int len = Query(min_array, max_array, MinSegmentTree, MaxSegmentTree, n, x - 1, value);
                int minZ = MinimumZ(min_array, max_array, MinSegmentTree, MaxSegmentTree, n, x - 1, len - 1);
                printf("%d %d\n", len, minZ);
            }
        }
    }

    return 0;
}