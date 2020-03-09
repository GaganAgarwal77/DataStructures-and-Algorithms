#include<stdio.h>
#include<stdlib.h>

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