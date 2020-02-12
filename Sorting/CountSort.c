#include<stdio.h>
#include<stdlib.h>

void CountSort(int*arr,int k,int n)
{
    int* temp = calloc(k,sizeof(int));
    int* sorted = calloc(n,sizeof(int));
    for(int i =0;i<n;i++)
        temp[arr[i]]++;
    for(int i=0;i<=k;i++)
        printf("%d ",temp[i]);
    printf("\n");
    for(int i =1;i<=k;i++)
        temp[i] += temp[i-1];  
    for(int i=0;i<=k;i++)
        printf("%d ",temp[i]);
    printf("\n");    
    for(int i = n-1;i>=0;i--)
        sorted[--temp[arr[i]]] = arr[i];
    for(int i=0;i<n;i++)
        printf("%d ",sorted[i]);
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr= malloc(n*sizeof(int));
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    int max = arr[0];
    for(int i= 0;i<n;i++)
    {
        if(arr[i]>=max)
            max = arr[i];
    }
    printf("\n%d\n",max);
    CountSort(arr,max,n);

    return 0;   
}