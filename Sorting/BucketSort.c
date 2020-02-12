#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {int (temp); temp = a; a = b; b = temp;}

struct Node 
{
    int data;
    struct Node* next;
};

void printList(struct Node *node) 
{ 
    while (node != NULL) //untill we reach the end of the linked list ,we print the data stored in each node and move to next node
    { 
        printf("%d-->", node->data); 
        node = node->next; 
    } 
	printf("NULL\n"); //we print null to mark the end of the linked list
}

  
// A function to implement bubble sort 
void bubbleSort(struct Node** head_ref) 
{ 
    struct Node *temp1;
    struct Node *temp2;
    for(temp1=*head_ref;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          { 
            if(temp2->data < temp1->data)
                swap(temp1->data,temp2->data);
           }
    }
} 

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

void BucketSort(int*arr,int n)
{
    int* sorted = calloc(n,sizeof(int));
    struct Node**buckets = malloc(100000*sizeof(struct Node*));
    for(int i=0;i<100000;i++)
    {
        buckets[i] = NULL;
    }

    for(int i =0;i<n;i++)
    {
        push(&buckets[arr[i]/10000],arr[i]);
    }
    for(int i =0;i<100000;i++)
    {
        if(buckets[i] != NULL)
        {
            printList(buckets[i]);
            bubbleSort(&buckets[i]);
        }
    }
    int count=0;
    for(int i =0;i<100000;i++)
    {
        if(buckets[i] != NULL)
        {
            printf("NOT NULL\n");
            struct Node* temp =buckets[i];
            printList(temp);
            while(temp != NULL)
            {
                arr[count] = temp->data;
                printf("%d\n",arr[count]);
                temp = temp->next;
                count++;
            }
        }
    }
       
 for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr= malloc(n*sizeof(int));
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");    
    BucketSort(arr,n);
    // struct Node * head = NULL;
    // push(&head,5);
    // push(&head,4);
    // push(&head,6);
    // push(&head,2);
    // push(&head,9);
    // printf("List is : ");
    // printList(head);
    // bubbleSort(&head);
    // printf("after sorting list is : ");
    // printList(head);
    return 0;   
}