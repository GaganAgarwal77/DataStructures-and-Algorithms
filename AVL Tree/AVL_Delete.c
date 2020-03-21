#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node *newNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

int getBalanceFactor(struct Node *node)
{
    if (node == NULL)
        return 0;

    return (height(node->left) - height(node->right));
}

struct Node *LeftRotate(struct Node *node)
{

    struct Node *temp = node->right;
    struct Node *temp2 = temp->left;
    temp->left = node;
    node->right = temp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

struct Node *RightRotate(struct Node *node)
{

    struct Node *temp = node->left;
    struct Node *temp2 = temp->right;
    temp->right = node;
    node->left = temp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

struct Node *Insert(struct Node *node, int val)
{
    if (node == NULL)
        return (newNode(val));

    if (val < node->data)
        node->left = Insert(node->left, val);
    else if (val > node->data)
        node->right = Insert(node->right, val);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalanceFactor(node);

    if (balance > 1 && val < (node->left)->data)
        return RightRotate(node);

    if (balance < -1 && val > (node->right)->data)
        return LeftRotate(node);

    if (balance > 1 && val > (node->left)->data)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }
    if (balance < -1 && val < (node->right)->data)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
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
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return RightRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return LeftRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
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

void LevelOrder(struct Node *root)
{
    struct Node *Queue[1000];
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
        scanf("%d", &arr[i]); //9 5 10 0 6 11 -1 1 2

    root = Insert(root, arr[0]);

    for (int i = 1; i < n; i++)
        root = Insert(root, arr[i]);

    root = Delete(root, 10);

    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\nLevelorder Traversal: ");
    LevelOrder(root);

    return 0;
}
