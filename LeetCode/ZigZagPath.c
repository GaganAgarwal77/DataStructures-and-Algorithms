#include<stdio.h>
#include<stdlib.h>

int* pathInZigZagTree(int label, int* returnSize)
{
        int level = -1;
        int m = label;
        while(m > 0)
        {
            m = m/2;
            level +=1;
        }
        int* path = calloc(level+1,sizeof(int));    
        int current = 0;
        int number = 1;
        int count = 0;
        path[count++] = number;
        int power = level;
        int a = 1;
        while(power >0)
        {
            a = 2*a;
            power--;
        }
        int b = 2*a - 1;
        int index = 0;
        int max = 1;
        int min = 1;
        while(number != label)
        {
            min = 2*min;
            max = 2*max +1;
            int median = (a  + b)/2;
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
        *returnSize = count;
        return path;
}

int main()
{

    int* ans = malloc(1000*sizeof(int));
    int n = 0;
    int*ref = &n;
    ans = pathInZigZagTree(16,ref);
    for(int i=0;i<*ref;i++)
        printf("%d ",ans[i]);
}
