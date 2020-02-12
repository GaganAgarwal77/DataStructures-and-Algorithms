// Question: Multiply two large numbers represented as strings by using linked lists instead of arrays.
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
void printList(struct node *node) 
{ 
    while (node != NULL) //untill we reach the end of the linked list ,we print the data stored in each node and move to next node
    { 
        printf("%d-->", node->data); 
        node = node->next; 
    } 
	printf("NULL"); //we print null to mark the end of the linked list
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
    printf("Addition of %s\n             %s is called\n",num1,num2);
    char *num = calloc(1000000,sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    struct node* number1 = NULL;
    struct node* number2 = NULL; 
    createLinkedList(&number1,num1_len/2 + 1);
    createLinkedList(&number2,num1_len/2 + 1);
    divide_number(num1,number1);
    divide_number(num2,number2);
    // printList(number1);
    // printf("\n");
    // printList(number2);
    // printf("\n");
    //printf("%s %s %d\n",num1,num2,num1_len);
    int a,b,c=0,index=0;
    if(num1_len%4 == 0)
        a = 0;
    else
        a = 1;
    for(int i =0;i<num1_len/4 + a;i++)
    {
        b = number1->data + number2->data + c;
        printf("%d = %d + %d + %d\n",b,number1->data,number2->data,c);
        c = b/10000;
        number1 = number1->next;
        number2 = number2->next;
        int number = b %10000;
        printf("%d\n",number);
        if(i !=num1_len/4 +a-1 )
        {
            for(int j =0;j<4;j++)
            {
                num[index] = number%10 +'0';
                number = number/10;
                index++;
            }
        }
        else
        {
            while(number>0)
            {
                num[index] = number%10 +'0';
                number = number/10;
                index++;
            }
        }
        if(c!=0)
        {
            num[index] = c +'0'; 
        }
        printf("%s\n",num);
        //num[index] = '\0';
        printf("%s\n",num);
    }
    for(int m =strlen(num)-1;m>=0;m--)
    {
        ans[strlen(num)-1-m] = num[m];
    }
    printf("%s\n",ans);
}

void multipyDivided(char *num1,char *num2,char*nums)
{
    char *num = malloc(100000*sizeof(char));
    divide_number(num1,head1);
    printList(head1);
    printf("\n");
    divide_number(num2,head2);
    printList(head2);
    printf("\n");
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    
    struct node*temp2 = malloc(sizeof(struct node));
    struct node*temp1 = malloc(sizeof(struct node));
    temp2 = head2;
    temp1 = head1;
    int a,c,b,index=0;
    if(num1_len%4 == 0)
        a = 0;
    else
        a = 1;
    
    if(num2_len%4 == 0)
        c = 0;
    else
        c = 1;
    //printf("Hello %d\n",num2_len);
    for(int i =0;i<num2_len/4 + c;i++)
    {
        //printf("Hello\n\n");
        
        temp1 = head1;
        char *temp = calloc(100000,sizeof(char));

        //printf("Hello %d\n\n",num1_len);
        for(int j =0;j<num1_len/4+a;j++)
        {
            //printf("Hello\n\n");
            int index =0;
            char *num = calloc(100000,sizeof(char));
            char *rev_num = calloc(100000,sizeof(char));
            //b = nums2[i]*nums1[j];
            b = (temp2->data)*(temp1->data);
            printf("%d = %d*%d\n",b,temp2->data,temp1->data);
            temp1 = temp1->next;
            printf("%d ",b);
            while(b > 0)
            {
                num[index] = b%10 +'0';
                b = b/10;
                index++;
            }
            printf(" --%d-- ",index);
            for(int m =0;m<index;m++)
            {
                rev_num[m] = num[strlen(num)-m-1];
            }
            for(int k =0;k < 4*i + 4*j;k++)
            {
                rev_num[index +k] = '0';
            }
            printf(" %s\n\n\n",rev_num);
            if(strlen(rev_num)> strlen(nums))
                addLargeNos(rev_num,nums,temp);
            else
                addLargeNos(nums,rev_num,temp);
            
            printf("%s\n\n",temp);
            strcpy(nums,temp);
        }
        temp2 = temp2->next;
    }
}

int main() 
{ 
	char *num1 = malloc(100000*sizeof(char));
    char *num2 = malloc(100000*sizeof(char));
    char *ans = calloc(1000000,sizeof(int));
    scanf("%s %s",num1,num2);
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int n1 = num1_len/2;
    int n2 = num2_len/2;
    //printf("%d %d\n",n1,n2);
    createLinkedList(&head1,n1);
	createLinkedList(&head2,n1);
    //printf("%d %d\n",n1,n2);
    if(num1_len>num2_len)
        multipyDivided(num1,num2,ans);
    else
        multipyDivided(num2,num1,ans);
    printf("%s",ans);

    return 0;
}
