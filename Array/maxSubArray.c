#include<stdio.h>
#include<stdlib.h>

int MaxSubArray(int*A,int n)
{
    int sum =0;
    int max = 0;
    for(int j = 0;j<n;j++)
    {
        sum += A[j];
        if( sum > max)
            max = sum;
        
        if(sum<0)
            sum =0;
    }
    return max;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *arr = calloc(n,sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",arr+i);    
    printf("%d\n",MaxSubArray(arr,n));
    return 0;
}