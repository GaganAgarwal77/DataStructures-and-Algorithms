#include<stdio.h>
#include<stdlib.h>

int MaxAjAi(int*A,int n)
{
    int i =0;
    int max = -1000000000;
    for(int j = 1;j<n;j++)
    {
        if( A[j] - A[i] >= max)
            max = A[j] - A[i];
        
        if(A[i]> A[j])
            i =j;
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
    printf("%d\n",MaxAjAi(arr,n));
    return 0;
}