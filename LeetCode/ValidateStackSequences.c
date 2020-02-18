#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define swap(a, b) {char (temp); temp = a; a = b; b = temp;}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    
    if(pushedSize == 0)
        return true;
    int l =0;
    int r = 0;
    int *Stack = calloc(2000,sizeof(int));
    int top = -1;
    Stack[++top] = pushed[0];
    l++;
    // for(int i=0;i<5;i++)
    //         printf("%d ",Stack[i]);
    // printf("\n");
    while(l<pushedSize)
    {
        if(top >=0 && Stack[top] == popped[r])
        {
            top--;
            r++;            
        }
        else
        {
            Stack[++top] = pushed[l++];  
        }
//     for(int i=0;i<5;i++)
//             printf("%d ",Stack[i]);
//     printf("\ntop:%d\n",top);
    
    }
    while(top >= 0)
    {
        if(Stack[top] == popped[r])
        {
            top--;
            r++;
        }
        else
        {
            free(Stack);
            return false;
        }
    //     for(int i=0;i<5;i++)
    //         printf("%d ",Stack[i]);
    // printf("\ntop:%d\n",top);
    }
    
    // for(int i=0;i<5;i++)
    //         printf("%d ",Stack[i]);
    // printf("\n%d\n",top);
    free(Stack);
    return true;
    
}

int main()
{
    int a[] = {4,0,1,2,3};
    int b[] = {4,2,3,0,1};
    int n1 = 5;
    int n2 = 5;
    bool ans = validateStackSequences(a,n1,b,n2);
    printf("%d\n",ans);

    return 0;
}