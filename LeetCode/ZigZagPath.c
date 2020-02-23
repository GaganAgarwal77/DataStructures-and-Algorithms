#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Log2n(int n) 
{ 
    return (n > 1) ? 1 + Log2n(n / 2) : 0; 
} 
int* pathInZigZagTree(int label,int*return_size)
{
    int level = Log2n(label);
    int* path = malloc(level*sizeof(int));    
    int current = 0;
    int number = 1;
    int count = 0;
    path[count++] = number;
    int a = pow(2,level);
    int b = 2*a - 1;
    int index = 0;
    int max = 1;
    int min = 1;
    while(number != label)
    {
        min = 2*min;
        max = 2*max +1;
        int median = (a  + b)/2;
        printf("a = %d b = %d median = %d\n",a,b,median);
        if(level%2 !=0)
        {
            if(label > median)
            {
                if(current%2 == 0)
                    path[count++] = max - 2*index;
                else
                    path[count++] = min + 2*index;
                
                index = 2*index;
                a = median + 1;
            }
            else
            {
                if(current%2 == 0)
                    path[count++] = max - 2*index -1;
                else
                    path[count++] = min + 2*index +1;
                
                index = 2*index +1;
                b = median;
            }
        }
        else
        {
            if(label <= median)
            {  
                if(current%2 == 0)
                    path[count++] = max - 2*index;
                else
                    path[count++] = min + 2*index;
                index = 2*index;
                b = median;
            }
           else
           {
                if(current %2 == 0)
                    path[count++] = max - 2*index -1;
                else
                    path[count++] = min + 2*index +1;
               index = 2*index +1;
               a = median+1;
           }
        }
        current += 1;
        number = path[count-1];
    }
    *return_size = count;
    return path;
}

int main()
{

    int* ans = malloc(1000*sizeof(int));
    int n = 0;
    int*ref = &n;
    ans = pathInZigZagTree(22,ref);
    for(int i=0;i<*ref;i++)
        printf("%d ",ans[i]);
}