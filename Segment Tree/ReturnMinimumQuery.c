#include<stdio.h>
#include<stdlib.h>


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

