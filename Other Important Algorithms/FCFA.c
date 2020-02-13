//Question : Check whether the given linked list is circular or not
//Time Complexity : O(n)

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};



void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void makeitCircular(struct Node** head_ref,int n)
{
    struct Node* node = malloc(sizeof(struct Node));
    struct Node* point = malloc(sizeof(struct Node));
    node = *head_ref;
    int i =0;
        while(node->next!=NULL)
        {
            if(i==n)
                point = node;
            node = node ->next;
            i++;
            
        }
        node ->next = point;
}

int checkIfCircular(struct Node** head_ref)
{
    struct Node* p1 = malloc(sizeof(struct Node));
    struct Node* p2 = malloc(sizeof(struct Node));
    p1 = *head_ref;
    p2 = *head_ref;
    while(p2 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
        if(p2 != NULL)
            p2 = p2->next;
        else
            return 0;
        if(p1 == p2)
            return 1;
    }
    return 0;

}
int main()
{   
    struct Node* head = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0;i<10;i++)
        push(&head,arr[i]);
    int ans;
    ans = checkIfCircular(&head);
    printf("%d\n",ans);

    return 0;
}
