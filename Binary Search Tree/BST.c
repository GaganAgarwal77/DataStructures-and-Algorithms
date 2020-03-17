#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int val)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node *InsertNode(struct Node *node, int val)
{
    if (node == NULL)
        return newNode(val);

    if (val < node->data)
        node->left = InsertNode(node->left, val);
    else if (val > node->data)
        node->right = InsertNode(node->right, val);

    return node;
}

struct Node *Search(struct Node *root, int val)
{
    if (root == NULL || root->data == val)
        return root;

    if (root->data < val)
        return Search(root->right, val);
    else
        return Search(root->left, val);
}

struct Node *MinValueNode(struct Node *node)
{
    struct Node *temp = node;
    while (temp != NULL && temp->left != NULL)
        temp = temp->left;

    return temp;
}

struct Node *Delete(struct Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = Delete(root->left, val);
    else if (val > root->data)
        root->right = Delete(root->right, val);
    else
    {
        struct Node *temp = NULL;
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = MinValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }

    return root;
}

void Inorder(struct Node *node)
{
    if (node != NULL)
    {
        Inorder(node->left);
        printf("%d ", node->data);
        Inorder(node->right);
    }
}

void Preorder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Postorder(struct Node *node)
{
    if (node != NULL)
    {
        Postorder(node->left);
        Postorder(node->right);
        printf("%d ", node->data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Node *Queue[MAX];
    int head = 0, tail = 0;
    Queue[tail] = root;
    while (head <= tail)
    {
        root = Queue[head];
        head++;
        printf("%d ", root->data);
        if (root->left)
        {
            Queue[++tail] = root->left;
        }
        if (root->right)
        {
            Queue[++tail] = root->right;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Node *root = NULL;

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    root = InsertNode(root, arr[0]);

    for (int i = 1; i < n; i++)
        InsertNode(root, arr[i]);

    root = Delete(root, 7);
    printf("\nInorder Traversal: ");
    Inorder(root);
    printf("\nPreorder Traversal: ");
    Preorder(root);
    printf("\nPostorder Traversal: ");
    Postorder(root);
    printf("\nLevelorder Traversal: ");
    LevelOrder(root);
    printf("\n");
    struct Node *temp = NULL;
    temp = Search(root, 7);
    if (temp != NULL)
        printf("%d\n", (temp->right)->data);

    return 0;
}