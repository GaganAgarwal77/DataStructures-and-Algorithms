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


