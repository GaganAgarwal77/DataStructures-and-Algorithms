#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addLargeNums(char* num1, char* num2, char* num)
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

int main()
{
    char *num1 = malloc(100000*sizeof(char));
    char *num2 = malloc(100000*sizeof(char));
    char *num = malloc(1000000*sizeof(char));
    scanf("%s %s",num1,num2);
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    if(num1_len > num2_len)
        addLargeNums(num1,num2,num);
    else
        addLargeNums(num2,num1,num);
    printf("%s\n",num);
    return 0;
}