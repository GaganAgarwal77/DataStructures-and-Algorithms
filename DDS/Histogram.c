// Question: The Histogram Problem using Stack
// Time Complexity : O(n)

#include<stdio.h>
#include<stdlib.h>


void NextMinArray(int *A,int n,int *ans)
{
    int *stack = malloc(n*sizeof(int));

    int top = -1;
    for(int i =0;i<n;i++)
    {
        if(top < 0)
            stack[++top] = i;
        else if(A[stack[top]] < A[i])
            stack[++top] = i;
        else if(A[stack[top]] > A[i])
        {
            while(top >= 0 && A[stack[top]] > A[i])
                ans[stack[top--]] = i;
            stack[++top] = i;
        }
    }
    while(top >=0)
        ans[stack[top--]] = n;
}
void LeftMinArray(int *A,int n,int *ans)
{
    int *stack = malloc(n*sizeof(int));

    int top = -1;
    for(int i =n-1;i>-1;i--)
    {
        if(top < 0)
            stack[++top] = i;
        else if(A[stack[top]] < A[i])
            stack[++top] = i;
        else if(A[stack[top]] > A[i])
        {
            while(top >= 0 && A[stack[top]] > A[i])
                ans[stack[top--]] = i;
            stack[++top] = i;
        }
    }
    while(top >=0)
        ans[stack[top--]] = -1;
}

int LargestRectangle(int*A,int*L,int*R,int n)
{
    int max =0;
    for (int i = 0; i < n; i++)
    {
        if(max <= (R[i] - L[i] - 1)*(A[i]))
            max = (R[i] - L[i] - 1)*(A[i]);
    }
    return max;    
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr= malloc(n*sizeof(int));
    int *R = malloc(n*sizeof(int));
    int *L = malloc(n*sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);
    NextMinArray(arr,n,R);
    LeftMinArray(arr,n,L);
    int ans;
    ans = LargestRectangle(arr,L,R,n);
    printf("%d\n",ans);

    return 0;   
}
