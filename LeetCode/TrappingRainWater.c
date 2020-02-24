#include<stdio.h>
#include<stdlib.h>

int trapping(int* height, int heightSize){
    int sum = 0;
    int ans =0;
    int t =0;
    int temp;
    int k = 0;
    int l =0;
    //while(i < heightSize)
    while(height[t+1] >= height[t])
    {   
        t++;
    }
    for(int i =k;i<heightSize;i++)
    {
        temp = height[t];
        // sum += height[i];
        l = t+1;
        int max = height[l];
        int a =0;
        while(l < heightSize)
        {
            if(height[l] >= max && height[l] <= temp)
            {
                max = height[l];
                a = l;
            }
            //sum += height[l];
            l++;
        }
        
        int k = t +1;
        while(k<a)
        {
            sum += height[k++];
        }
        printf("max = %d ,temp = %d, sum = %d\n",max,temp,sum);
        
        if(max <= temp)
            ans += max*(a-t-1) -sum; 
        else
            ans += temp*(a-t-1)- sum;
        
        t = a;
        sum =0;
        i = t;  
    }   
    return ans;
}

int trap(int* height, int heightSize){
    int sum = 0;
    int ans =0;
    int t =0;
    int temp;
    for(int i =1;i<heightSize;i++)
    {
        temp = height[t];
        sum += height[i];
        
        if(height[i] >= temp)
        { 
            if (i-t > 1)
            {
            sum -= height[i];
            ans += temp*(i-t-1) - sum;

                t =i;
                sum = 0;
            }
            // printf("t = %d sum = %d\n",t,sum);
            else
            {
                t = i;
                sum = 0;
            }
        }
        if(i == heightSize-1 && temp > height[i] && i-t>1)
        {
            int *arr = malloc(1000*sizeof(int));
            for(int j=t;j<heightSize;j++)
                arr[j-t] = height[j];
            
            ans += trapping(arr,heightSize-t);
            // if(height[i-1] > height[i])
            // {
            //     sum -= height[i];
            //     i = i-1;
            // }  
            // sum -= height[i]; 
            // ans += height[i]*(i-t-1) - sum;
            // i += 1;
            // //break;
        } 
    }
    return ans;
}


int main()
{
    int t;
    int height[] = {3,0,0,2,0,4};
    // int height[] = {5,4,1,2};
    // int height[] = {3,0,2,0,4,0,1,2};
    // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int height[] = {9,6,8,8,5,6,3};
    int heightSize = sizeof(height)/sizeof(int);
    t = trap(height,heightSize);
    printf("%d\n",t);
    return 0;
}