#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
};

// void createLinkedList(struct node **head,int n)
// {
//     struct node *prev,*p; //declaring two structure pointers

//     for(int i=0;i<n;i++)
//     {
//         p=malloc(sizeof(struct node)); //assigning memoring required to store a node
//         //scanf("%d",&p->data); //taking user input into node
// 		p->data = 0;
//         p->next=NULL; //pointing the node to the next node which is currently NULL
//         if(*head==NULL) //if the head is null(at the beginning) then we make it point to the first node p
//             *head=p;
//         else
//             prev->next=p;       //in further iterations we make prev point to our p node
// 		prev=p; //then for the next run of the loop changing prev to p 
//     }
// }
// void append(struct node** head_ref, int new_data) 
// { 
//     /* 1. allocate node */
//     struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
//     struct node *last = *head_ref;  /* used in step 5*/
   
//     /* 2. put in the data  */
//     new_node->data  = new_data; 
  
//     /* 3. This new node is going to be the last node, so make next  
//           of it as NULL*/
//     new_node->next = NULL; 
  
//     /* 4. If the Linked List is empty, then make the new node as head */
//     if (*head_ref == NULL) 
//     { 
//        *head_ref = new_node; 
//        return; 
//     }   
       
//     /* 5. Else traverse till the last node */
//     while (last->next != NULL) 
//         last = last->next; 
   
//     /* 6. Change the next of last node */
//     last->next = new_node; 
//     return;     
// } 

void push(struct node** head_ref, int new_data) 
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data; 
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    char* text = "10111010111011001110101110110011110101110110011101111010111011101011101100111010111011001111010111011";
    int num_patterns = 5;
    //int len_pattern = 100000;
    char**patterns = (char**)malloc(num_patterns*sizeof(char *));
    // for (int i=0; i<num_patterns; i++) 
    //     patterns[i] = (char*)malloc(len_pattern*sizeof(char));
    
    patterns[0] = "1110101110110011101011101100";
    patterns[1] = "0101110110011101111010111011";
    patterns[2] = "0101110110011101011101100111";
    patterns[3] = "0111010111011001111010111011";
    patterns[4] = "0110011101011101100111101011";

    int hash_table_size = 100000;
    struct node**arr = malloc(hash_table_size*sizeof(struct node*));
    for(int i=0;i<hash_table_size;i++)
    {
        arr[i] = NULL;  
    }

    int prime = 100003;
    int len_pat = strlen(patterns[0]);

    for (int i = 0; i < 5; i++)
    {
        int N=0;
        int a =0;
        for(int j =0;j<len_pat;j++)
        {
            N =  (2*N + (patterns[i][j]-'0'))%prime;
        }
        push(&arr[N],i);
        //printf("%d %d %d\n",a,N,arr[N]->data);
    }
    // for(int i=0;i<3;i++)
    // {
    //     printf("%d ",arr[2]->data);
    //     arr[2] =arr[2]->next;
    // }
    int len_text = strlen(text);


    int y = 0;
    int match = 0;
    int j =0;
    int power = 1;

    for(int i = 0; i<len_pat; i++)
    {
        y = (2*y +text[i]-'0')%prime;
        power *= 2;
        
    }
    power = power/2;

    for(int i =0; i<len_text-len_pat+1; i++)
    {
        for(int k =0;k<hash_table_size;k++)
        {
            struct node* ref = malloc(sizeof(struct node));
            if(y == k && arr[k] != NULL)
            {
                //printf("%d %d %d %s -- Loop Starts\n",i,y,k,patterns[arr[k]->data]);
                ref = arr[k];
                while(ref != NULL)
                {   
                    //printf("%d %s\n",i,patterns[ref->data]);
                    int j =0;
                    for(j =0;j<len_pat;j++)
                    {
                        // printf("%d %d\n\n",i,j);
                        if(text[i+j] != patterns[ref->data][j])
                        {    
                            break;
                        }
                    }
                    if(j == len_pat)
                    {
                        printf("Pattern match found at %d index of pattern %s \n",i,patterns[ref->data]);
                        match++;
                    }
                    ref = ref->next;
                }
            }
        }   
        if(i<len_text-len_pat)
        {
            y = ((y-(text[i]-'0')*power)*2 +text[i+len_pat] -'0')%prime;
            if (y<0)
            {
                y = (y+prime);
            }
        }
    }

    if(match == 0)
        printf("No match found\n");

    return 0;
}

