#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void merge(int *A,int i,int k,int j)
{
    int l=i,r=k+1,p=0;
    int *B = malloc((j+1)*sizeof(int));
    while(l<=k && r<=j)
    {
        if(A[l]<= A[r])
            B[p++] = A[l++];
        else
            B[p++] = A[r++];
    }
    while(l<=k)
        B[p++] = A[l++];
    while(r<=j)
        B[p++] = A[r++];
    p = 0;
    l = i;
    while(l<=j)
        A[l++] = B[p++];
}
void MergeSort(int *A,int i,int j)
{
    if(i<j)
    {
        int k = (i+j)/2;
        MergeSort(A,i,k);
        MergeSort(A,k+1,j);
        merge(A,i,k,j);
    }
}

bool FindAiAjX(int*A,int n,int x)
{
    int l =0,r=n-1;
    while(l<=r)
    {
        if(A[l] + A[r] == x )
            return true;
        else if(A[l]+ A[r] >x)
            r--;
        else
            l++;
    }
    return false;
}


int main()
{
    int n;
    scanf("%d",&n);
    int *arr = calloc(n,sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",arr+i);
    int x;
    scanf("%d",&x);
    MergeSort(arr,0,n-1);
    printf("%d\n",FindAiAjX(arr,n,x));
    return 0;
}