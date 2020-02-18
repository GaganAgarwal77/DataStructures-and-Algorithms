#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {char (temp); temp = a; a = b; b = temp;}

void TopDownHeapify(int i,int n, int*Heap)
{
    int l =0;
    while(2*i+2 < n)
    {
        if( Heap[2*i+1] > Heap[2*i+2])
            l = 2*i+1;
        else
            l = 2*i+2;
        if(Heap[i] < Heap[l])
        {
            int temp = Heap[i];
            Heap[i] = Heap[l];
            Heap[l] = temp;
            i = l;
        }
        else
            break;
    }
    if(2*i+1<n && Heap[i] < Heap[2*i+1])
    {
        int temp = Heap[i];
        Heap[i] = Heap[2*i+1];
        Heap[2*i+1] = temp;
    }
}
void BottomUpHeapify(int i,int* Heap)
{
    int p = (i-1)/2;
    while(p>=0 && Heap[p] < Heap[i])
    {
        int temp = Heap[i];
        Heap[i] = Heap[p];
        Heap[p] = temp;
        i = p;
        p = (i-1)/2;
    }
}
void BuildMaxHeap(int* Heap, int n)
{
    for(int i =n/2;i>=0;i--)
        TopDownHeapify(i,n,Heap);
}

int DeleteMax(int*Heap,int *n)
{
    int a = Heap[0];
    Heap[0] = Heap[--(*n)];
    TopDownHeapify(0,*n,Heap);
    return a;
}

void Add(int data,int*Heap,int *n)
{
    Heap[(*n)++] = data;
    BottomUpHeapify(*n-1,Heap);
}

int lastStoneWeight(int* stones, int stonesSize){

    BuildMaxHeap(stones,stonesSize);
    int*count_ref = &stonesSize;
    while(*count_ref > 1)
    {
        int max1 = DeleteMax(stones,count_ref);
        int max2 = DeleteMax(stones,count_ref);
        if (max1- max2 > 0)
            Add(max1-max2,stones,count_ref);
    }
    if(*count_ref == 1)
        return stones[0];
    else
        return 0;
}


int main()
{
    int n;
    scanf("%d",&n);
    int a = n;
    int* count_ref = &n;
    int *arr= malloc(1000*sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);    
    int ans = lastStoneWeight(arr,n);
    printf("\n%d\n",ans); 
    return 0;

}