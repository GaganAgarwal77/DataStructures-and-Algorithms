// Question: Multiply two large numbers represented as strings by dividing them into parts of 4 and storing them individually as integers.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void divide_number(char *num,int*nums)
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

            nums[(count/4) -1] = atoi(temp);
            flag++;
        } 
        count++;
    }
    for(int k = 0;k<num_len%4;k++)
    {
        temp[k] = num[k];
    }
    nums[flag] = atoi(temp);
}

void addLargeNos(char *num1,char *num2, char*ans)
{
    char *num = calloc(1000000,sizeof(char));
    int *nums1 = malloc(100000*sizeof(int));
    int *nums2 = malloc(100000*sizeof(int));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    divide_number(num1,nums1);
    divide_number(num2,nums2);
    int a,b,c=0,index =0;
    if(num1_len%4 == 0)
        a = 0;
    else
        a = 1;
    for(int i =0;i<num1_len/4 + a;i++)
    {
        b = nums1[i] + nums2[i] + c;
        c = b/10000;
        int number = b%10000;
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
    }

    for(int m =strlen(num)-1;m>=0;m--)
    {
        ans[strlen(num)-1-m] = num[m];
    }
}

void multipyDivided(char *num1,char *num2,char*nums)
{
    int *nums1 = calloc(100000,sizeof(int));
    int *nums2 = calloc(100000,sizeof(int));
    char *num = malloc(100000*sizeof(char));

    divide_number(num1,nums1);
    divide_number(num2,nums2);
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    
    int a,c,b,index=0;
    if(num1_len%4 == 0)
        a = 0;
    else
        a = 1;
    
    if(num2_len%4 == 0)
        c = 0;
    else
        c = 1;
    
    for(int i =0;i<num2_len/4 + c;i++)
    {
        char *temp = calloc(100000,sizeof(char));
        
        for(int j =0;j<num1_len/4+a;j++)
        {
            int index =0;
            char *num = calloc(100000,sizeof(char));
            char *rev_num = calloc(100000,sizeof(char));
            b = nums2[i]*nums1[j];
            while(b > 0)
            {
                num[index] = b%10 +'0';
                b = b/10;
                index++;
            }
            for(int m =0;m<index;m++)
            {
                rev_num[m] = num[strlen(num)-m-1];
            }
            for(int k =0;k < 4*i + 4*j;k++)
            {
                rev_num[index +k] = '0';
            }
            if(strlen(rev_num)> strlen(nums))
                addLargeNos(rev_num,nums,temp);
            else
                addLargeNos(nums,rev_num,temp);
            strcpy(nums,temp);
        }
    }
}
int main()
{
    char *num1 = malloc(100000*sizeof(char));
    char *num2 = malloc(100000*sizeof(char));
    char *nums = calloc(100000000,sizeof(char));
    scanf("%s %s",num1,num2);
    multipyDivided(num1,num2,nums);
    printf("%s * %s = %s\n",num1,num2,nums);
    return 0;
}
