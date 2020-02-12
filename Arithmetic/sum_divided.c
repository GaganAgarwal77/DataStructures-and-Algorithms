// Question: Add two large numbers represented as strings by dividing them into parts of 4 and storing them individually as integers.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int main()
{
    char *num1 = malloc(100000*sizeof(char));
    char *num2 = malloc(100000*sizeof(char));
    char *ans = malloc(1000000*sizeof(int));
    scanf("%s %s",num1,num2);
    if(strlen(num1)>strlen(num2))
        addLargeNos(num1,num2,ans);
    else
        addLargeNos(num2,num1,ans);
    printf("\n%s\n",ans);
    return 0;
}
