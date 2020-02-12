#include<stdio.h>
#include<stdlib.h>

void RadixSort(int*arr,int k,int n)
{
    int b = 1;
    while(k > 0)
    {
        int* temp = calloc(10,sizeof(int));
        int* sorted = calloc(n,sizeof(int));
        
        for(int i =0;i<n;i++)
            temp[(arr[i]/b)%10]++;
        
        for(int i=0;i<10;i++)
            printf("%d ",temp[i]);
        printf("\n");
        
        for(int i =1;i<10;i++)
            temp[i] += temp[i-1];  
        
        for(int i=0;i<10;i++)
            printf("%d ",temp[i]);
        printf("\n");    
        
        for(int i = n-1;i>=0;i--)
            sorted[--temp[(arr[i]/b)%10]] = arr[i];
        for(int i=0;i<n;i++)
            arr[i] = sorted[i];
        b = b*10;
        k--;
    }   
 for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
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
    printf("\n");    
    RadixSort(arr,2,n);

    return 0;   
}