// Question: Given a Large Decimal Number in the form of a string, find the floor of the Log of the Number.
// Time Complexity: O(logn)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LogOfLargeNums(char * num)
{
    char * ans1 = malloc(10000*sizeof(char));
    int  count =-1;
    while(strlen(num)>0)
    {
        //printf("len:%ld\n",strlen(num));
        char *ans = malloc(10000*sizeof(char));
        char *temp = malloc(10000*sizeof(char));
        int len_num = strlen(num);
        for(int i =len_num-1;i>=0;i--)
        {
            int carry =0;
            if(i<=len_num -2 && (num[i]-'0')%2 == 1)
            {
                temp[i+1] +=  5;
                if(temp[i+1] >=58)
                {
                    temp[i+1] = '0';
                    carry = 1;
                } 
            }
            temp[i] = ((num[i] -'0')/2) + '0' + carry;
        }
        int k =0;
        while(temp[k] == '0')
            k++;
        for(int i =0;i<strlen(temp)-k;i++)
            ans[i] = temp[i+k];
        num = ans;
        //printf("%s-",num);
        count++;
    }
    return count;
}


int main()
{
    char * num = malloc(1000*sizeof(char));
    scanf("%s",num);
    int ans = LogOfLargeNums(num);
    printf("%d\n",ans);
    return 0;
}




