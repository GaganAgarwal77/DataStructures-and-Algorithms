#include<stdio.h>
#include<stdlib.h>


void BuildSegmentTree(int*Array,int*SegmentTree, int n)
{
    for(int i = 0;i<n;i++)
        SegmentTree[n + i-1] = i;

    for(int i = n-2; i >=0;i--)
    {
        if(Array[SegmentTree[2*i+1]] > Array[SegmentTree[2*i+2]])
            SegmentTree[i] = SegmentTree[2*i+2];
        else
            SegmentTree[i] = SegmentTree[2*i+1];
    }
}

void UpdateInSegmentTree(int*Array,int*SegmentTree, int i, int x, int n)
{
    Array[i] = x;
    i = (n+i-2)/2;
    while(i>0)
    {
        if(Array[SegmentTree[2*i+1]] > Array[SegmentTree[2*i+2]])
        { 
            SegmentTree[i] = SegmentTree[2*i+2];
        }
        else
        {
            SegmentTree[i] = SegmentTree[2*i+1];
        }
        
        i = (i-1)/2;
    }

    if(Array[SegmentTree[1]] > Array[SegmentTree[2]])
        SegmentTree[0] = SegmentTree[2];
    else
        SegmentTree[0] = SegmentTree[1];
}

int ReturnMinimumQueryUtility(int*Array,int*SegmentTree, int i, int j, int s,int e,int p, int n)
{
    if(j < s || i > e)
        return n;
    if(i <= s && e <= j)
        return SegmentTree[p];
    
    int m = (s+e)/2;    
    
    int left = ReturnMinimumQueryUtility(Array,SegmentTree,i,j,s,m,2*p+1,n);
    int right = ReturnMinimumQueryUtility(Array,SegmentTree,i,j,m+1,e,2*p+2,n);
    
    if(Array[left] < Array[right])
        return left;
    else
        return right;
}

int ReturnMinimumQuery(int*Array,int*SegmentTree, int i, int j, int n)
{
    int min  = ReturnMinimumQueryUtility(Array,SegmentTree,i,j,0,n-1,0,n);
    printf("%d\n",min);
}


int main()
{
    int n;
    scanf("%d",&n);
    int* array = calloc(n+1,sizeof(int));
    int* SegmentTree = calloc(2*n-1,sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&array[i]); //4 7 3 2 8 12 1 16
    }
    array[n] = 1073741824; //2^30;
    
    BuildSegmentTree(array,SegmentTree,n);
    UpdateInSegmentTree(array,SegmentTree,6,14,n);
    ReturnMinimumQuery(array,SegmentTree,4,7,n);
    
    for(int i = 0;i<2*n-1;i++)
        printf("%d ", SegmentTree[i]);

}