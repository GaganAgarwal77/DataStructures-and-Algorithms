#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};



void push(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
   
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
   
    /* 4. move the head to point to the new node */
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
// void printList(struct Node *first) 
// { 
//     struct Node *temp = first;  
  
//     // If linked list is not empty 
//     if (first != NULL)  
//     { 
//         // Keep printing nodes till we reach the first node again 
//         do
//         { 
//             printf("%d ", temp->data); 
//             temp = temp->next; 
//         } 
//         while (temp != first); 
//     } 
//} 
// void printList(struct Node *node) 
// { 
//   while (node != NULL) 
//   { 
//      printf(" %d ", node->data); 
//      node = node->next; 
//   } 
// }
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
    //makeitCircular(&head,4);
    int ans;
    ans = checkIfCircular(&head);
    printf("%d\n",ans);
    //printList(head);


    return 0;
}