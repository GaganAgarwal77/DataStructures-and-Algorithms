#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
};


void push(struct node** head_ref, int new_data) 
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data; 
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

char* text = "10111010111011001110101110110011110101110110011101111010111011101011101100111010111011001111010111011";
char* patterns ="11101011101100111010111011001111";
int patternMatching(int len_pat)
{
    int hash_table_size = 10000;
    struct node**arr = malloc(hash_table_size*sizeof(struct node*));
    
    for(int i=0;i<hash_table_size;i++)
    {
        arr[i] = NULL;  
    }

    int prime = 10003;

    for (int i = 0; i <= strlen(patterns) - len_pat; i++)
    {
        int N=0;
        int a =0;
        for(int j =0;j<len_pat;j++)
        {
            N =  (2*N + (patterns[i+j]-'0'))%prime;
        }
        push(&arr[N],i);
        //printf("%d %d %d\n",a,N,arr[N]->data);
    }

    int len_text = strlen(text);


    int y = 0;
    int match = 0;
    int j =0;
    long long int power = 1;

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
                        if(text[i+j] != patterns[ref->data + j])
                        {    
                            break;
                        }
                    }
                    if(j == len_pat)
                    {
                        //printf("Pattern match found at %d index of pattern of index %d \n",i,ref->data);
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

    if(match >= 2)
        return 1;
    else
        return 0;
        
}
int BinarySearch(int l,int r)
{
    if(l<=r)
    {
        int m = (l+r)/2;
        if(patternMatching(m)==1)
        {  
            printf("Found pattern match for length l %d\n",m);
            return BinarySearch(m+1,r);
        }
        else
            return BinarySearch(l,m-1);
    }
    
}


int main()
{

    BinarySearch(1,strlen(patterns));
    return 0;
}

