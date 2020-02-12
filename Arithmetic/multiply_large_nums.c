// Question: Multiply two large numbers represented as strings,and outputting the final answer in a string.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define swap(a, b) {char (temp); temp = a; a = b; b = temp;}

void addLarge(char* num1, char* num2, char* num)
{
    char *rev_num1 = malloc(100000*sizeof(char));
    char *rev_num2 = malloc(100000*sizeof(char));
    char *rev_num = malloc(1000000*sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    for(int i = num1_len-1;i>=0;i--)
    {   
        rev_num1[num1_len-1-i] = num1[i];
    }
    for(int i = num2_len-1;i>=0;i--)
    {
        rev_num2[num2_len-1-i] = num2[i];
    }
        int a=0,i=0;
        for(i = 0; i<num2_len;i++)
        {
            int c = (((rev_num1[i]-48)+(rev_num2[i]-48))%10);
            if( c + a != 10)
            {  
                rev_num[i] = (c + a + 48 );
                a = (((rev_num1[i]-48)+(rev_num2[i]-48))/10);

            }
            else 
            {
                rev_num[i] = (c + a + 48 - 10);
                a =1;
            } 
        }
        for(int i = num2_len; i<num1_len;i++)
        {
            int c = (((rev_num1[i]-48)+(rev_num2[i]))%10);
            if( c +a != 10)
            {  
                rev_num[i] = (c + a + 48 );
                a = (((rev_num1[i]-48)+(rev_num2[i]))/10);
            }
            else
            {
                rev_num[i] = (c + a + 48 - 10);
                a =1;
            }         
        }
        if( a != 0)
        {
            rev_num[num1_len] = a+48;
        }
    for(int i = 0;i<strlen(rev_num);i++)
    {   
        num[i] = rev_num[strlen(rev_num)-i-1];
    }
}

void multi_large_nos(char *num1,char*num2,char*num)
{
    char *buff = calloc(100000,sizeof(char));
    char *temp = calloc(100000,sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);

    // if (num1_len >= num2_len)
    // {
    for(int j=0;j<num2_len;j++)
    {
       int i =0;
       for( i =0;i<num2[num2_len-1 -j]-48;i++)
       {
           if (strlen(num1) > strlen(buff))
            {
                // printf("%s-%s\n",num1,buff);
                addLarge(num1,buff,temp);
            }
           else
           {
               //printf("%s-%s\n",num1,buff);
               addLarge(buff,num1,temp);
           }
           strcpy(buff,temp);
       } 
       //printf("%s\n",buff);
       int ab = strlen(buff);
       for(int k=0;k<j;k++)
        {
           buff[ab+k] = '0';
        //    printf("%s\n",buff);
        }   
        //printf("%s\n",buff);
        if (strlen(num) > strlen(buff))
        {
            addLarge(num,buff,temp);
        }
        else
        {
            addLarge(buff,num,temp);
        }
        strcpy(num,temp);
        free(buff);
        free(temp); 
        char *buff = calloc(100000,sizeof(char));
        char *temp = calloc(100000,sizeof(char));    
    }   
    printf("%s\n",num);
}
int main()
{
    clock_t begin = clock();
    char *num1 = calloc(100000,sizeof(char));
    char *num2 = calloc(100000,sizeof(char));
    char *num = calloc(1000000,sizeof(char));
    scanf("%s %s",num1,num2);
    if (strlen(num1) >= strlen(num2))
        multi_large_nos(num1,num2,num);
    else
        multi_large_nos(num2,num1,num);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);
    return 0;
}
