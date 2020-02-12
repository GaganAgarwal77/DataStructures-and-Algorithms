// Input
// The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.
// Output
// Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int w;
    scanf("%d",&w);
    if(w%2 ==0 && w>3)
        printf("YES");
    else
        printf("NO");
}