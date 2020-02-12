#include<stdio.h>
#include<stdlib.h>

//O(n),Uses Stack

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
        ans[stack[top--]] = -1;
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
        //printf("max => %d ,%d\n",max,(R[i] - L[i] - 2)*(A[i]));
        printf("(%d-%d-2)*%d = max\n",R[i],L[i],A[i]);
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
    for(int i=0;i<n;i++)
        printf("%d ",R[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",L[i]);
    printf("\n");
    int ans;
    ans = LargestRectangle(arr,L,R,n);
    printf("%d\n",ans);

    return 0;   
}