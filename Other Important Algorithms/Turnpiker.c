// Question: Turnpike Reconstruction Problem

// We want to maintain a multy set
// LinkedList{1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10}
// ABS(x)− returns absolute value of x.
// FindMax(L)− returns the maximum element in the List L.
// Insert(L, x)− Inserts x into the List L.
// Delete(L, x)−Deletes x from the List L.
// Search(L, x)− returns true if x ∈ L else returns false.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node **head_ref) 
{ 
  struct Node* node =malloc(sizeof(struct Node));
  node = *head_ref;
  while (node != NULL) 
  { 
     printf("%d ", node->data); 
     node = node->next; 
  } 
  printf("\n");
}

int ABS(int x)
{
    if(x>=0)
        return x;
    else
        return -x;
}

int FindMax(struct Node* node)
{
    int max = node->data;
    while (node != NULL)
    {
        if (node->data > max)
        {
            max = node->data;
        }
        node = node->next;        
    }
    return max;
}

void Insert(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    new_node->data  = new_data; 
   
    new_node->next = (*head_ref); 
   
    (*head_ref)    = new_node; 
}

void Delete(struct Node **head_ref, int key) 
{ 
    struct Node* temp = *head_ref, *prev; 
      if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   
        free(temp);              
        return; 
    } 
  
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) return; 
  
    prev->next = temp->next; 
  
    free(temp);  
} 

bool Search(struct Node* node, int x)
{
    while (node != NULL)
    {
        if (node->data == x)
        {
            return true;
        }
        node =node->next;
    }
    return false;
}

bool Possible(int X[],struct Node **D,int max,int left,int right,int n)
{

    int count = 0;
    for(int i =0;i<left;i++)
    {
        if(Search(D,ABS(max-X[i])))
            Delete(D,ABS(max -X[i]));
        else    
            return false;
    }
    for(int j =right+1;j<n;j++)
    {
        if(Search(*D,ABS(max-X[j])))
            Delete(D,ABS(max- X[j]));
        else
            return false;
    }
    for(int k = 0;k<left;k++)
    {
        Insert(D,ABS(max-X[k]));
    }
    for(int m = right+1;m<n;m++)
    {
        Insert(D,ABS(max-X[m]));
    }
    return true;    
}


bool Try(int X[],struct Node **D,int n,int left,int right)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node = *D;
    bool found = false; 
    if(D == NULL) 
        return true;
    int max = FindMax(&D); 
    if(Possible(X,D,max,left,right,n))
    {
        X[right]=max;
        for(int i=0;i<left;++i) 
        {
                Delete(&D,ABS(X[i]-X[right]));
        }
        for(int i=right+1;i<n;++i)
        {
            Delete(&D,ABS(X[i]-X[right]));
        }
        found=Try(X,D,n,left,right-1);
        if (found==false) 
        {
            for(int i=0;i<left;++i) 
                Insert(&D,ABS(X[i]-X[right]));
            for(int i=right+1;i<n;++i) 
                Insert(&D,ABS(X[i]-X[right]));
        }
    }
    if(Possible(X,D,X[n-1]-max,left,right,n) && found==false)
    {
        X[left]=X[n-1]-max;
        for(int i=0;i<left;++i) 
            Delete(&D,ABS(X[i]-X[left]));
        for(int i=right+1;i<n;++i) 
            Delete(&D,ABS(X[i]-X[left]));
        found = Try(X,D,n,left+1,right);
        if (found==false) 
        {
            for(int i=0;i<left;++i) 
                Insert(&D,ABS(X[i]-X[left]));
            for(int i=right+1;i< n;++i) 
                Insert(&D,ABS(X[i]-X[left]));
        }    
    }
    return found;
}

bool ProAss1(int X[],struct Node *D,int n)
{
    X[0] = 0;
    
    X[n-1] = FindMax(&D);
    Delete(&D,FindMax(&D));
    
    X[n-2] = FindMax(&D);
    Delete(&D,FindMax(&D));   
    if (Search(&D,X[n-1]-X[n-2])) 
    {
        Delete(&D,X[n-1]-X[n-2]);
        return Try(X,D,n,1,n-3);
    }
    else return false;
}

int main()
{
    struct Node* head = NULL;
    int arr[] = {1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10};
    int X[6];
    int m = 15;
    int n = 6;
    for(int i = 14;i>=0;i--)
        Insert(&head,arr[i]); 
    
    if(ProAss1(X,head,n))
        printf("True\n");
    else
        printf("False\n");

    for(int i =0;i<6;i++)
        printf("%d ",X[i]);

    return 0;
}
