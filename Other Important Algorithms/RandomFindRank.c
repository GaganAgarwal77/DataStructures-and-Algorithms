#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) {int (temp);temp =a;a=b;b=temp;}

int Partition(int *A,int i, int j,int pivot)
{
    int l = i;
    int r =j;
    while(l<=r)
    {
        while(l<=r && A[l] <=pivot) 
            l++;
        while(l<=r && A[r] > pivot) 
            r--;
        if(l<=r)
        {
            swap(A[l],A[r]);
            l++;
            r--;
        }
    }
    int k = l-1;
    A[i-1] = A[k];
    A[k] = pivot;
    return k;
}
int RFR(int* A,int i,int j,int r)
{
    if(i<=j)
    {
        int p = (rand() % (j-i+1)) +i;
        swap(A[p],A[i]);
        int k = Partition(A,i+1,j,A[i]);
        if(r == j-k+1)
            return A[k];
        else if(r<j-k+1)
            RFR(A,k+1,j,r);
        else
            RFR(A,i,k-1,r-j+k-1);
    }
    else
        return -1;
}

int Replicate(int*A,int i,int j,int r)
{   
    int *sec = malloc((j-i+1)*sizeof(int));
    for(int k = 0; k < (j-i+1); k++)
	{
        sec[k] = A[k];
    }
    int ans;
    int value = RFR(A,0,j-i,r);
    //printf("%d %d\n",value,j-i+1);
    for(int a = 0 ; a < j-i+1 ; a++)
	{
        //printf("%d ",sec[a]);
        if(sec[a] == value)
        {    
            ans = a;
        }
    }
    return ans;
    
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));   
    //int *sec = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
	{
	    scanf("%d",arr+i);
        //sec[i] = arr[i];
    }
    int rank;
    //int ans;
    scanf("%d",&rank);
    int value = Replicate(arr,0,n-1,rank);
    for(int a = 0 ; a < n ; a++)
	{
        printf("%d ",arr[a]);
        // if(sec[a] == value)
        //     ans = a;
	}
    printf("\n%d\n",value);
    return 0;
}