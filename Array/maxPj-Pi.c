#include<stdio.h>
#include<stdlib.h>

int MaxPjPi(int*P,int n)
{
    int i =0;
    int max = 0;
    for(int j = 1;j<n+1;j++)
    {
        if( P[j] - P[i] > max)
            max = P[j]-P[i];
        
        if(P[i] > P[j])
            i = j;
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
    int *parr = calloc(n+1,sizeof(int));
    parr[0] = 0;
    for(int i =1;i<n+1;i++)
        parr[i] = parr[i-1] + arr[i-1];
    for(int i =0;i<n+1;i++)
        printf("%d ",parr[i]);    
    printf("\n%d\n",MaxPjPi(parr,n));
    return 0;
}