#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void AddBinaryNumbers(char*num1,char*num2,char*num)
{
    char *rev_num1 = malloc(100000*sizeof(char));
    char *rev_num2 = malloc(100000*sizeof(char));
    char *rev_num = malloc(1000000*sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    for(int i = num1_len-1;i>=0;i--)
    {   
        rev_num1[num1_len-1-i] = num1[i];
    }
    for(int i = num2_len-1;i>=0;i--)
    {
        rev_num2[num2_len-1-i] = num2[i];
    }
    for(int i = num2_len;i<num1_len;i++)
        rev_num2[i] = '0';
    rev_num2[num1_len] = '\0';
    //printf("%s\n%s\n",rev_num1,rev_num2);
    int carry =0;
    int i;
    for(i =0;i<num1_len;i++)
    {
        int c = (rev_num1[i] -'0') + (rev_num2[i] - '0') + carry;
        carry =0;
        //printf("%c ",c+'0');
        if(c == 2)
        {
            c = 0;
            carry = 1;
        }
        else if( c == 3)
        {
            c = 1;
            carry =1;
        }
        rev_num[i] = c + '0';    
    }
    if(carry != 0)
        rev_num[i++] = carry + '0';
    rev_num[i] ='\0';
    //printf("%s\n",rev_num);
    for(int i = 0;i<strlen(rev_num);i++)
    {   
        num[i] = rev_num[strlen(rev_num)-i-1];
    }
}

void ConvertIntoBinary(char *num,char*answer)
{
    char*binary = malloc(10000*sizeof(char));
    int i =0;
    while(strlen(num)>0)
    {
        binary[i] = (num[strlen(num)-1] -'0')%2 +'0';  
        //printf("len:%ld\n",strlen(num));
        char *ans = malloc(10000*sizeof(char));
        char *temp = malloc(10000*sizeof(char));
        int len_num = strlen(num);
        for(int i =len_num-1;i>=0;i--)
        {
            int carry =0;
            if(i<=len_num -2 && (num[i]-'0')%2 == 1)
            {
                temp[i+1] +=  5;
                if(temp[i+1] >=58)
                {
                    temp[i+1] = '0';
                    carry = 1;
                } 
            }
            temp[i] = ((num[i] -'0')/2) + '0' + carry;
        }
        int k =0;
        while(temp[k] == '0')
            k++;
        for(int i =0;i<strlen(temp)-k;i++)
            ans[i] = temp[i+k];
        num = ans;
        //printf("%s\n",num);
        i++;
    }
    int k =0;
    for(k =0;k<strlen(binary);k++)
        answer[k] = binary[strlen(binary)-k-1];
    answer[k+1] = '\0';

}
char* SquaringBinaryNumber(char*num)
{
    int * indexes = calloc(1000,sizeof(int));
    char *sqnum = calloc(100000,sizeof(char));
    sqnum[0] = '0';
    sqnum[1] = '\0';
    int count = 0;
    //printf("%s\n",num);
    for(int i =strlen(num)-1;i>=0;i--)
    {    
        if(num[i] == '1')
        {
            indexes[count] = strlen(num)-i-1;
            //printf("%d\n",indexes[count]);  
            count++;
            
        }
    }
    // if(num[0] ='1')
    //     AddBinaryNumbers(num,sqnum,sqnum);
    //printf("%s %s\n",num,sqnum);
    for(int i =0; i < count;i++)
    {
    int l = strlen(num);
    //printf("%d ",indexes[i]);
    if(i==0)
    {
        for(int j=0;j<indexes[i];j++)
            num[l + j] = '0';
    }
    else
    {
        for(int j=0;j<indexes[i] -indexes[i-1];j++)
            num[l + j] = '0';
    }
    //printf("%s\n",num);

    if(strlen(num) > strlen(sqnum))
        AddBinaryNumbers(num,sqnum,sqnum);
    else
        AddBinaryNumbers(sqnum,num,sqnum);
    //printf("%s %s\n",num,sqnum);
    }
    return sqnum;
}
int CompareBinaryNumbers(char*num1,char*num2)
{
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);

    int index1;
    int index2;
    for(int i =0;i<num1_len;i++)
    {
        if(num1[i] != '0')
        {
            index1 = i;
            break;
        }
    }
    for(int i =0;i<num2_len;i++)
    {
        if(num2[i] != '0')
        {
            index2 = i;
            break;
        }
    }
    if(num1_len-index1 > num2_len-index2)
        return 1;
    else if(num1_len-index1 < num2_len-index2)
        return -1;
    else
    {
        int i =index1;
        int j =index2;
        while(i<num1_len && j<num2_len)
        {
            if(num1[i] > num2[j])
                return 1;
            else if(num1[i] < num2[j])
                return -1;
            i++;
            j++;
        }
        return 0;
    }
}
char* SquareRootofLargeNum(char*num)
{
    char *binary_num = malloc(10000*sizeof(char));
    ConvertIntoBinary(num,binary_num);
    int len_num = strlen(binary_num);
    char *sqrtnum = calloc(100000,sizeof(char));
    //printf("%d\n",len_num);
    char *k = calloc(100000,sizeof(char));
    k[0] = '1';
    for(int  i=1;i<len_num;i++)
    {
        k[i] = '0';
    }
    //printf("%s\n",binary_num);
    //printf("%s\n",k);
    for(int i =0;i<len_num;i++)
    {
        char *temp = calloc(10000,sizeof(char));
        strcpy(temp,k);
        temp = SquaringBinaryNumber(temp);
        //printf("%s\n",k);
        if(CompareBinaryNumbers(temp,binary_num) == 1)
        {    
            k[i] = '0';
            if(i != len_num-1)         
                k[i+1] ='1';
            //printf("if:%s\n",k);
        }
        else if(CompareBinaryNumbers(temp,binary_num) == -1)
        {
            k[i] ='1';
            if(i != len_num-1)         
                k[i+1] ='1';
            //printf("else if:%s\n",k);
        }
        else
            break;    
    }
    int index =0;
    for(int i =0;i<strlen(k);i++)
    {
        if(k[i] != '0')
            {
                index = i;
      //          printf("%d\n",index);
                break;
            }
    }
    for(int j = index;j<strlen(k);j++)
        sqrtnum[j-index] = k[j];   
    //printf("%ld %s\n",strlen(k),sqrtnum);
    return sqrtnum;
    
}
long long int GetDecimalValue(char*num,int l,int r)
{
    long long int ans=0;
    for(int i=l;i<r;i++)
        ans = 2*ans +(num[i]-'0'); 
    return ans;
}

int main()
{
    char *bin_ans = calloc(100000,sizeof(char));
    char *num = calloc(100000,sizeof(char));
    char *num2 = calloc(100000,sizeof(char));
    scanf("%s",num);
    bin_ans =SquareRootofLargeNum(num);
    printf("%s\n",bin_ans);
    long long int ans = GetDecimalValue(bin_ans,0,strlen(bin_ans));
    printf("%lld\n",ans);
    
    return 0;
}