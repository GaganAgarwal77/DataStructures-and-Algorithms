//Question: Given an array , find all such pairs , A[i] and A[j]  A[i] > A[j] where j>i
// Time Complexity : O(nlogn)

#include<stdio.h>
#include<stdlib.h>

int merge(int *A,int i,int k,int j)
{
    int l=i,r=k+1,p=0;
    int num_ip=0;
    int *B = malloc((j+1)*sizeof(int));
    while(l<=k && r<=j)
    {
        if(A[l]<= A[r])
            B[p++] = A[l++];
        else
        {
            B[p++] = A[r++];
            num_ip += k-l+1;
        }
    }
    while(l<=k)
        B[p++] = A[l++];
    while(r<=j)
        B[p++] = A[r++];
    p = 0;
    l = i;
    while(l<=j)
        A[l++] = B[p++];
    return num_ip;
}
int MergeSort(int *A,int i,int j)
{
    if(i<j)
    {
        int k = (i+j)/2;
        return (MergeSort(A,i,k) + MergeSort(A,k+1,j) + merge(A,i,k,j));
    }
    return 0;
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
    int num_of_IP = MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n%d\n",num_of_IP);
    return 0;   
}
