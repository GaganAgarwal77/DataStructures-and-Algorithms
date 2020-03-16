#include<stdio.h>
#include<stdlib.h>

void Update(int* Array, int i, int x, int n)
{
    while(i < n)
    {
        Array[i] += x;
        i += i&(-i);
    }
}

void BuildBIT(int* Array, int* BIT,int n)
{
    for(int i =1;i<n;i++)
        Update(BIT,i,Array[i],n);
}

int PrefixSum(int*Array, int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += Array[i];
        i-= i&(-i);
    }
    return sum;
}

int FindKthOne(int* Array, int n, int k)
{
    int s = 0;
    int e = n;
    while( s < e)
    {
        int m = (s+e)/2;
        if(PrefixSum(Array,m) == k)
        {
                return m;
        }
        else if(PrefixSum(Array,m) > k)
        {
            e = m;
        }
        else
        {
            s = m+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int* array = calloc(n+1,sizeof(int));
    int* BinaryIndexTree = calloc(n+1,sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&array[i]); 
    }
    BuildBIT(array,BinaryIndexTree,n);

    //Update(BinaryIndexTree,2,-1,n);
    // Update(BinaryIndexTree,2,-BinaryIndexTree[2],n);
    //Update(BinaryIndexTree,2,0,n);
    printf("%d\n",FindKthOne(BinaryIndexTree,n,5));
    
    for(int i = 0;i<n;i++)
        printf("%d ", BinaryIndexTree[i]);
}