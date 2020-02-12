#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char* text = "10111010111011001110101110110011110101110110011101111010111011101011101100111010111011001111010111011";
    char* pattern ="11101011101100111010111011001111";

    int len_pat = strlen(pattern);
    int len_text = strlen(text);

    long long int power = pow(2,len_pat-1);
    long long int N = (pattern[0]-'0')*power;
    long long int y = (text[0]-'0')*power;
    int match = -1;

    for(int i = 1; i<len_pat; i++)
    {
        N +=  (pattern[i]-'0')*pow(2,len_pat-1-i);
        y +=  (text[i]-'0')*pow(2,len_pat-1-i);
    }
    printf("%lld %lld\n",N,y);
    if(N==y)
    {
        printf("Pattern match found at 0 index\n");
        match++;
    }

    for(int i =1; i<len_text-len_pat+1; i++)
    {
        y = (y-(text[i-1]-'0')*power)*2 +text[i+len_pat -1] -'0';

        if(y == N)
        {
            printf("Pattern match found at %d index\n",i);
            match++;
        }
    }

    if(match == -1)
        printf("No match found\n");

    return 0;
}

