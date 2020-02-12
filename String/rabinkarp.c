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

    int power = pow(2,len_pat-1);
    int N = 0;
    int y = 0;
    int match = -1;
    int prime = 2;
    int i,j;

    for(int i = 0; i<len_pat; i++)
    {
        N =  (2*N + (pattern[i]-'0'))%prime;
        y = (2*y +text[i]-'0')%prime;
    }
    printf("%d %d\n",N,y);

    for(i =1; i<len_text-len_pat+1; i++)
    {

        //printf("%d %d\n",y,N);
        if(y == N)
        {
            for(j =0;j<len_pat;j++)
            {
                // printf("%d %d\n\n",i,j);
                if(text[i+j] != pattern[j])
                {    
                    break;
                }
            }
            // printf("%d\n\n",j);
            if(j == len_pat)
            {
                printf("Pattern match found at %d index\n",i);
                match++;
            }
        }

        if(i<len_text-len_pat)
        {
        y = ((y-(text[i-1]-'0')*power)*2 +text[i+len_pat -1] -'0')%prime;
        printf("%d %d\n",y,i);
            if (y<0)
            {
                y = (y+prime);
            }
        }
    }

    if(match == -1)
        printf("No match found\n");

    return 0;
}

