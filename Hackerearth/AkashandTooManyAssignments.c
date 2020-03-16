#include<stdio.h>
#include<stdlib.h>


int BITS[26][1000000];
char String[1000000];

void Update(int i, int x, int n,int pos)
{
    while(i <= n)
    {
        BITS[pos][i] += x;
        i += i&(-i);
    }
}


void BuildBITS(int n)
{
    for(int i =0;i<n;i++)
        Update(i+1,1,n,String[i]-'a');
}

int PrefixSum(int i,int pos)
{
    int sum = 0;
    while(i > 0)
    {
        sum += BITS[pos][i];
        i-= i&(-i);
    }
    return sum;
}

int RangeSumQuery(int i , int j, int pos)
{
    int ans = PrefixSum(j,pos) - PrefixSum(i-1,pos);
    return ans;
    //printf("%d\n",ans);
}

int ReturnKthSmallestCharacter(int s , int e, int k)
{
    int total =0;
    for(int i =0;i<26;i++)
    {
        total += RangeSumQuery(s,e,i);
        if(total>=k)
            break;
    }
    return (total + 'a');
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",String);
    printf("%s\n",String);

    BuildBITS(n);
    // for(int i =0;i<26;i++)
    // {
    //     for(int j=1;j<n+1;j++)
    //     {
    //         printf("%d",BITS[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%c",ReturnKthSmallestCharacter(2,5,3));
    return 0;
}


















// #include<stdio.h>
// #include<stdlib.h>


// int BITS[26][1000000];
// char String[1000000];

// void Update(int i, int x, int n,int pos)
// {
//     while(i < n)
//     {
//         BITS[pos][i] += x;
//         i += i&(-i);
//     }
// }


// void BuildBIT(int n)
// {
//     for(int i =0;i<n;i++)
//         Update(i+1,1,n,String[i]-'a');
// }

// int PrefixSum(int Array[], int i)
// {
//     int sum = 0;
//     while(i > 0)
//     {
//         sum += Array[i];
//         i-= i&(-i);
//     }
//     return sum;
// }

// void RangeSumQuery(int Array[], int i , int j, int n)
// {
//     int ans = PrefixSum(Array, j) - PrefixSum(Array,i-1);
//     printf("%d\n",ans);
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     scanf("%s",String);
//     printf("%s\n",String);
//     BuildBIT(n);
//     for(int i =0;i<26;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             printf("%d",BITS[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }