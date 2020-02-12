#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) {int (temp);temp =a;a=b;b=temp;}

int Partition(int *A,int i, int j,int pivot)
{
    int l = i,r =j;
    while(l<=r)
    {
        while(l<=r && A[l] <=pivot) l++;
        while(l<=r && A[r] > pivot) r--;
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
            return k;
        else if(r<j-k+1)
            RFR(A,k+1,j,r);
        else
            RFR(A,i,k-1,r-j+k-1);
    }
    else
        return -1;
}



void RQS(int *A,int i,int j)
{
    if(i<j)
    {
        int p = RFR(A,i,j,(j-i+1)/2);
        swap(A[i],A[p]);
        int k = Partition(A,i+1,j,A[i]);
        RQS(A,i,k-1);
        RQS(A,k+1,j);    
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
	{
	    scanf("%d",arr+i);
	}
    RQS(arr,0,n-1);
    for(int a = 0 ; a < n ; a++)
	{
    	printf("%d ",arr[a]);//printing the sorted array using for loop
	}

    return 0;
}
