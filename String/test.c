#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
};

void append(struct node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    struct node *last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next  
          of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
   
    /* 6. Change the next of last node */
    last->next = new_node; 
    return;     
} 
int main()
{
    struct node* head =NULL;
    append(&head,4); 
    if(head->next == NULL)
        printf("null");
    else 
        printf("%d\n",head->data);
}