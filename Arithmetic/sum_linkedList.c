#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node* next;
};

struct node* head1 = NULL;
struct node* head2 = NULL;

void createLinkedList(struct node **head,int n)
{
    struct node *prev,*p; //declaring two structure pointers

    for(int i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node)); //assigning memoring required to store a node
        //scanf("%d",&p->data); //taking user input into node
		p->data = 0;
        p->next=NULL; //pointing the node to the next node which is currently NULL
        if(*head==NULL) //if the head is null(at the beginning) then we make it point to the first node p
            *head=p;
        else
            prev->next=p;       //in further iterations we make prev point to our p node
		prev=p; //then for the next run of the loop changing prev to p 
    }
}

void divide_number(char *num,struct node *ref_head)
{
    char *temp = malloc(100000*sizeof(char));
    int num_len = strlen(num);

    int i=0,count=1,flag=0;
    for(i = num_len-1;i>=0;i--)
    {
        char *temp = calloc(100000,sizeof(char));
        
        if(count%4 == 0 && count > 0)
        {
            
            for(int j=0; j<4;j++)
            {
                temp[j] = num[j + i];
            }
            ref_head->data = atoi(temp);
            ref_head = ref_head->next;
            flag++;
        } 
        count++;
    }
    for(int k = 0;k<num_len%4;k++)
    {
        temp[k] = num[k];
    }
    ref_head->data = atoi(temp);
}
void addLargeNos(char *num1,char *num2, char*ans)
{
    char *num = calloc(1000000,sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    divide_number(num1,head1);
    divide_number(num2,head2);    
    int a,b,c=0,index=0;
    if(num1_len%4 == 0)
        a = 0;
    else
        a = 1;
    for(int i =0;i<num1_len/4 + a;i++)
    {
        b = head1->data + head2->data + c;
        c = b/10000;
        head1 = head1->next;
        head2 = head2->next;
        
        int number = b %10000;
        while(number>0)
        {
            num[index] = number%10 +'0';
            number = number/10;
            index++;
        }
    }
    for(int m =strlen(num)-1;m>=0;m--)
    {
        ans[strlen(num)-1-m] = num[m];
    }
}
int main() 
{ 
	char *num1 = malloc(100000*sizeof(char));
    char *num2 = malloc(100000*sizeof(char));
    char *ans = malloc(1000000*sizeof(int));
    scanf("%s %s",num1,num2);
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int n1 = num1_len/2;
    int n2 = num2_len/2;
    createLinkedList(&head1,n1);
	createLinkedList(&head2,n2);
    if(num1_len>num2_len)
        addLargeNos(num1,num2,ans);
    else
        addLargeNos(num2,num1,ans);
    printf("%s\n",ans);
}