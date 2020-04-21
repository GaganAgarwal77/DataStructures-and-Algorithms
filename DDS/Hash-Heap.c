#include <stdio.h>
#include <stdlib.h>

struct HashNode
{
    int num;
    int count;
    int index;
    struct HashNode *next;
    struct HashNode *prev;
};

struct HeapNode
{
    int frequency;
    struct HashNode *pointer;
};
int index_count = 0;
int hash(int n, int p)
{
    return n % p;
}

void push(struct HashNode **head_ref, int new_data)
{
    struct HashNode *new_node = (struct HashNode *)malloc(sizeof(struct HashNode));

    new_node->num = new_data;
    new_node->count = 1;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}
void Swap(struct HeapNode **Heap, int i, int p)
{
    int a = i;
    int b = p;
    int temp = Heap[i]->frequency;
    Heap[i]->frequency = Heap[p]->frequency;
    Heap[p]->frequency = temp;

    struct HashNode *temp_node = Heap[i]->pointer;
    Heap[i]->pointer = Heap[p]->pointer;
    Heap[p]->pointer = temp_node;

    Heap[i]->pointer->index = a;
    Heap[p]->pointer->index = b;
}
void BottomUpHeapify(struct HashNode **HashTable, struct HeapNode **Heap, int i)
{
    int p = (i - 1) / 2;
    while (p >= 0 && Heap[p]->frequency < Heap[i]->frequency)
    {
        Swap(Heap, i, p);
        i = p;
        p = (i - 1) / 2;
    }
}
void Add(struct HashNode **HashTable, struct HeapNode **Heap, int n, int data, int prime)
{
    int hash_value = hash(data, prime);
    struct HashNode *temp = HashTable[hash_value];
    while (temp != NULL)
    {
        if (temp->num == data)
        {
            // printf("temp->num == data = %d\n", data);
            temp->count += 1;
            Heap[temp->index]->frequency += 1;
            // printf("temp->index = %d, num= %d, frequency = %d \n", temp->index, Heap[temp->index]->pointer->num, Heap[temp->index]->frequency);
            BottomUpHeapify(HashTable, Heap, temp->index);
            // printf("Hello ->%d %d\n", Heap[0]->pointer->index, Heap[1]->pointer->index);

            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        // printf("index_count = %d\n", index_count);
        push(&HashTable[hash_value], data);
        // HashTable[hash_value]->count = 1;
        Heap[index_count]->frequency = 1;
        Heap[index_count]->pointer = HashTable[hash_value]; //How to add to heap?
        HashTable[hash_value]->index = index_count;
        // printf("index_count = %d, num= %d, frequency = %d \n", index_count, Heap[index_count]->pointer->num, Heap[index_count]->frequency);
        // BottomUpHeapify(HashTable, Heap, index_count);
        index_count++;
    }
}

void TopDownHeapify(int i, struct HeapNode **Heap)
{
    int l = 0;
    while (2 * i + 2 < index_count)
    {
        if (Heap[2 * i + 1]->frequency > Heap[2 * i + 2]->frequency)
            l = 2 * i + 1;
        else
            l = 2 * i + 2;
        if (Heap[i]->frequency < Heap[l]->frequency)
        {
            Swap(Heap, i, l);
            i = l;
        }
        else
            break;
    }
    if (2 * i + 1 < index_count && Heap[i]->frequency < Heap[2 * i + 1]->frequency)
    {
        // printf("%d %d %d \n", i, Heap[i], Heap[2 * i + 1]);
        int c = 2 * i + 1;
        Swap(Heap, i, c);
    }
}
void deleteNode(struct HashNode **head_ref, struct HashNode *del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
    {
        *head_ref = del->next;
    }
    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

void Delete(struct HashNode **HashTable, struct HeapNode **Heap, int prime)
{
    int max = Heap[0]->frequency;
    while (Heap[0]->frequency == max)
    {
        // printf("Hi\n");
        int c = Heap[0]->pointer->num;
        int hash_value = hash(c, prime);
        int i = 0;
        int p = --index_count;
        Swap(Heap, i, p);
        TopDownHeapify(i, Heap);

        deleteNode(&HashTable[hash_value], Heap[index_count]->pointer);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); //1 2 1 5 2 4 10 6 6 10 10 4 6 2 1 4 10 6
    }
    // int arr[] = {1, 2, 1, 4, 2, 4, 10, 6, 6, 10, 10, 4, 6, 2, 1, 4, 10, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int prime = 100003;
    int hash_table_size = 1000000;
    struct HashNode **HashTable = malloc(hash_table_size * sizeof(struct HashNode *));
    for (int i = 0; i < hash_table_size; i++)
    {
        HashTable[i] = NULL;
    }

    struct HeapNode **Heap = malloc(n * sizeof(struct HeapNode *));
    for (int i = 0; i < n; i++)
    {
        Heap[i] = (struct HeapNode *)malloc(sizeof(struct HeapNode));
        Heap[i]->frequency = 0;
        Heap[i]->pointer = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        Add(HashTable, Heap, n, arr[i], prime);
    }
    printf("After Addition: ");
    for (int i = 0; i < index_count; i++)
    {
        printf("num= %d, frequency = %d | ", Heap[i]->pointer->num, Heap[i]->frequency);
    }
    printf("\nAfter Deletion: ");
    Delete(HashTable, Heap, prime);
    for (int i = 0; i < index_count; i++)
    {
        printf("num= %d, frequency = %d | ", Heap[i]->pointer->num, Heap[i]->frequency);
    }
    printf("\n");

    return 0;
}