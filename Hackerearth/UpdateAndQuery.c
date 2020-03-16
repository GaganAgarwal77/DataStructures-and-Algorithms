#include<stdio.h>
#include<stdlib.h>


void BuildMinSegmentTree(int*Array,int*SegmentTree, int n)
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
void BuildMaxSegmentTree(int*Array,int*SegmentTree, int n)
{
    for(int i = 0;i<n;i++)
        SegmentTree[n + i-1] = i;

    for(int i = n-2; i >=0;i--)
    {
        if(Array[SegmentTree[2*i+1]] < Array[SegmentTree[2*i+2]])
            SegmentTree[i] = SegmentTree[2*i+2];
        else
            SegmentTree[i] = SegmentTree[2*i+1];
    }
}


void UpdateInMinSegmentTree(int*Array,int*SegmentTree, int i, int x, int n)
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
void UpdateInMaxSegmentTree(int*Array,int*SegmentTree, int i, int x, int n)
{
    Array[i] = x;
    i = (n+i-2)/2;
    while(i>0)
    {
        if(Array[SegmentTree[2*i+1]] < Array[SegmentTree[2*i+2]])
        { 
            SegmentTree[i] = SegmentTree[2*i+2];
        }
        else
        {
            SegmentTree[i] = SegmentTree[2*i+1];
        }
        
        i = (i-1)/2;
    }

    if(Array[SegmentTree[1]] < Array[SegmentTree[2]])
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
    //if(left < right)
    
    if(Array[left] < Array[right])
        return left;
    else
        return right;
}

int ReturnMinimumQuery(int*Array,int*SegmentTree, int i, int j, int n)
{
    int min  = ReturnMinimumQueryUtility(Array,SegmentTree,i,j,0,n-1,0,n);
    //printf("%d\n",min);
    return min;
}


int ReturnMaximumQueryUtility(int*Array,int*SegmentTree, int i, int j, int s,int e,int p, int n)
{
    if(j < s || i > e)
        return n+1;
    
    if(i <= s && e <= j)
        return SegmentTree[p];
    
    int m = (s+e)/2;    
    
    int left = ReturnMaximumQueryUtility(Array,SegmentTree,i,j,s,m,2*p+1,n);
    int right = ReturnMaximumQueryUtility(Array,SegmentTree,i,j,m+1,e,2*p+2,n);
    //if(left > right)
    if(Array[left] > Array[right])
        return left;
    else
        return right;
}

int ReturnMaximumQuery(int*Array,int*SegmentTree, int i, int j, int n)
{
    int max  = ReturnMaximumQueryUtility(Array,SegmentTree,i,j,0,n-1,0,n);
    //printf("%d\n",max);
    return max;
}

int Query(int* Array, int* MinSegmentTree, int* MaxSegmentTree, int n, int x, int c)
{
    int s = 0;
    int e = n;
    int m = (s+e)/2;
    while(s < e)
    {
        m = (s+e)/2;
        printf("x = %d m = %d\n",x,m);
        if(x + m < n)
        {
            printf("x+m<n\n");
            int max = ReturnMaximumQuery(Array,MaxSegmentTree,x,x+m,n);
            int min = ReturnMinimumQuery(Array,MinSegmentTree,x,x+m,n);
            printf("min = %d max =%d\n",min,max);   
            if(Array[min] >= (Array[x] -c) && Array[max] <= (Array[x] + c))
            {
                printf("len  = %d\n",m+1);    
                s = m+1;
            }
            else
            {
                e = m;
            }
        }
        else
        {
            e = m;
        }
    }
    return m+1;
}

int MinimumZ(int* Array, int* MinSegmentTree, int* MaxSegmentTree, int n, int x, int m)
{
    int max = ReturnMaximumQuery(Array,MaxSegmentTree,x,x+m,n);
    int minZ = Array[max] - Array[x];
} 



int main()
{
    int n;
    scanf("%d",&n);
    int* array = calloc(n+1,sizeof(int));
    int* MinSegmentTree = calloc(2*n-1,sizeof(int));
    int* MaxSegmentTree = calloc(2*n-1,sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&array[i]); //4 7 3 2 8 12 1 16
    }
    
    array[n] = 1073741824;
    array[n+1] = -1073741824; //2^30;

    BuildMinSegmentTree(array,MinSegmentTree,n);
    BuildMaxSegmentTree(array,MaxSegmentTree,n);
    
    for(int i = 0;i<2*n-1;i++)
        printf("%d ", MinSegmentTree[i]);

    printf("\n");

    for(int i = 0;i<2*n-1;i++)
        printf("%d ", MaxSegmentTree[i]);

    int len = Query(array,MinSegmentTree,MaxSegmentTree,n,0,6);
    printf("longest subarray len = %d\n",len);
    //UpdateInMaxSegmentTree(array,SegmentTree,5,18,n);
    // int max = ReturnMaximumQuery(array,MaxSegmentTree,0,6,n);
    // int min = ReturnMinimumQuery(array,MinSegmentTree,0,6,n);
    // printf("\nIn Main: min = %d max =%d\n",min,max);


}