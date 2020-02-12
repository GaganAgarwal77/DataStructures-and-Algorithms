#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *binary = "1001001100";
    // we have to find the index where ,number of zeroes on left(including the partition)  = number of ones on right
    int count=0;
    int l =0;
    int r = strlen(binary) -1;
    int ans;
    while(l<r)
    {   if(r-l <= 1)
            break;
        if(binary[l] != binary[r])
        {
            l++;
            r--;
        }
        else if(binary[l] == '0' && binary[r] == '0')
            r--;
        else if(binary[l] == '1' && binary[r] == '1')
            l++;
    }
    if(l == r)
    {
        if(binary[l] == '1')
            ans = l;
        else
            ans = l-1;
    }
    else
    {
        if(binary[l] != binary[r])
            ans = l;
        else
        {
            if(binary[l] == '1')
                ans = r;
            else
                ans = l-1;
        }
    }
    printf("%d %d\n%d\n",l,r,ans);
    return 0;
}