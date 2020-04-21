#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int start;
    int count;
    struct node *next;
};

void push(struct node **head_ref, int index)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->start = index;
    new_node->count = 1;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int SubStringMatching(char *text, int pattern_len, int k)
{
    if (k <= 1)
    {
        return 1;
    }
    int n = strlen(text);
    int hash_table_size = 100000;
    struct node **arr = malloc(hash_table_size * sizeof(struct node *));
    for (int i = 0; i < hash_table_size; i++)
    {
        arr[i] = NULL;
    }
    int prime = 100003;
    int len_text = strlen(text);
    int len_pat = pattern_len;

    int N = 0;
    int power = 1;
    for (int i = 0; i < len_pat; i++)
    {
        N = (2 * N + text[i] - '0') % prime;
        power *= 2;
    }
    power = power / 2;

    for (int i = 0; i < len_text - len_pat + 1; i++)
    {
        if (arr[N] == NULL)
        {
            push(&arr[N], i);
        }
        else
        {
            struct node *ref = malloc(sizeof(struct node));
            ref = arr[N];
            while (ref != NULL)
            {
                int j = 0;
                for (j = 0; j < len_pat; j++)
                {
                    if (text[i + j] != text[ref->start + j])
                        break;
                }

                if (j == len_pat)
                {
                    ref->count++;
                }

                if (ref->count == k)
                {
                    return 1;
                }

                ref = ref->next;
            }
            push(&arr[N], i);
        }

        if (i < len_text - len_pat)
        {
            N = ((N - (text[i] - '0') * power) * 2 + text[i + len_pat] - '0') % prime;
            if (N < 0)
            {
                N = (N + prime);
            }
        }
    }
    return 0;
}

void BinarySearch(int i, int j, int k, char *text, int *ans)
{
    int len;
    if (i <= j)
    {
        len = (i + j) / 2;
        // printf("i = %d j = %d len = %d\n", i, j, len);
        if (SubStringMatching(text, len, k) == 1)
        {
            if (len >= *ans)
            {
                *ans = len;
            }

            // printf("found atleast k matches for len = %d\n", len);
            BinarySearch(len + 1, j, k, text, ans);
        }
        else
        {
            // printf("No K matches found for len = %d\n", len);
            BinarySearch(i, len - 1, k, text, ans);
        }
    }
}

int main()
{
    int n, k;
    printf("Enter String Length: ");
    scanf("%d", &n);
    char *text = malloc(n * sizeof(char));
    printf("Enter String: ");
    scanf("%s", text);
    printf("Enter k: ");
    scanf("%d", &k);
    // char *text = "101101010110";
    int ans = 0;
    BinarySearch(0, strlen(text), k, text, &ans);
    printf("Max Len: %d", ans);
    return 0;
}