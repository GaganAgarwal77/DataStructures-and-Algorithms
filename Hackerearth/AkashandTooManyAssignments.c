#include <stdio.h>
#include <stdlib.h>

int BITS[26][1000000];

void Update(int i, int x, int n, int pos) //pos =>character index , i => string index
{
    while (i <= n)
    {
        BITS[pos][i] += x;
        i += i & (-i);
    }
}

void BuildBITS(int n, char *String)
{
    for (int i = 0; i < n; i++)
        Update(i + 1, 1, n, String[i] - 'a');
}

int PrefixSum(int i, int pos)
{
    int sum = 0;
    while (i > 0)
    {
        sum += BITS[pos][i];
        i -= i & (-i);
    }
    return sum;
}

int RangeSumQuery(int i, int j, int pos)
{
    int ans = PrefixSum(j, pos) - PrefixSum(i - 1, pos);
    return ans;
}

int ReturnKthSmallestCharacter(int s, int e, int k)
{
    int total = 0;
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        total += RangeSumQuery(s, e, i);
        if (total >= k)
            break;
    }
    return (i + 'a');
}
int main()
{
    int n, num_ops;
    char *String = (char *)calloc(1000000, sizeof(char));
    scanf("%d %d", &n, &num_ops);
    scanf("%s", String);

    BuildBITS(n, String);
    for (int i = 0; i < num_ops; i++)
    {
        int op_type;
        scanf("%d", &op_type);
        if (op_type == 0)
        {
            int index;
            char c[1];
            scanf("%d %s", &index, c);
            Update(index, -1, n, String[index - 1] - 'a');
            String[index - 1] = c[0];
            Update(index, 1, n, String[index - 1] - 'a');
            // printf("%s\n", String);
        }
        else
        {
            int ll, rl, k;
            scanf("%d %d %d", &ll, &rl, &k);
            if (rl < ll || rl - ll < k - 1)
                printf("Out of range\n");
            else
            {
                char ans = ReturnKthSmallestCharacter(ll, rl, k);
                printf("%c\n", ans);
            }
        }
    }
    return 0;
}
