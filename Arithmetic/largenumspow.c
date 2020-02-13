#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define swap(a, b) {char (temp); temp = a; a = b; b = temp;}

void addLarge(char* num1, char* num2, char* num)
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
        int a=0,i=0;
        for(i = 0; i<num2_len;i++)
        {
            int c = (((rev_num1[i]-48)+(rev_num2[i]-48))%10);
            if( c + a != 10)
            {  
                rev_num[i] = (c + a + 48 );
                a = (((rev_num1[i]-48)+(rev_num2[i]-48))/10);

            }
            else 
            {
                rev_num[i] = (c + a + 48 - 10);
                a =1;
            } 
        }
        for(int i = num2_len; i<num1_len;i++)
        {
            int c = (((rev_num1[i]-48)+(rev_num2[i]))%10);
            if( c +a != 10)
            {  
                rev_num[i] = (c + a + 48 );
                a = (((rev_num1[i]-48)+(rev_num2[i]))/10);
            }
            else
            {
                rev_num[i] = (c + a + 48 - 10);
                a =1;
            }         
        }
        if( a != 0)
        {
            rev_num[num1_len] = a+48;
        }
    for(int i = 0;i<strlen(rev_num);i++)
    {   
        num[i] = rev_num[strlen(rev_num)-i-1];
    }
}

void multi_large_nos(char *num1,char*num2,char*num)
{
    char *buff = calloc(100000,sizeof(char));
    char *temp = calloc(100000,sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);

    // if (num1_len >= num2_len)
    // {
    for(int j=0;j<num2_len;j++)
    {
       int i =0;
       for( i =0;i<num2[num2_len-1 -j]-48;i++)
       {
           if (strlen(num1) > strlen(buff))
            {
                // printf("%s-%s\n",num1,buff);
                addLarge(num1,buff,temp);
            }
           else
           {
               //printf("%s-%s\n",num1,buff);
               addLarge(buff,num1,temp);
           }
           strcpy(buff,temp);
       } 
       //printf("%s\n",buff);
       int ab = strlen(buff);
       for(int k=0;k<j;k++)
        {
           buff[ab+k] = '0';
        //    printf("%s\n",buff);
        }   
        //printf("%s\n",buff);
        if (strlen(num) > strlen(buff))
        {
            addLarge(num,buff,temp);
        }
        else
        {
            addLarge(buff,num,temp);
        }
        strcpy(num,temp);
        free(buff);
        free(temp); 
        char *buff = calloc(100000,sizeof(char));
        char *temp = calloc(100000,sizeof(char));    
    } 
    // strcpy(num1,num);
    //printf("%s\n",num);
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
char* power(char *x,char *n)
{
    char *power = malloc(1000000*sizeof(char));
    ConvertIntoBinary(n,power);
    //printf("%s\n",power);
    //printf("Hello\n\n");
    char* y = calloc(1000000,sizeof(char));
    //printf("Hello\n\n");
    y[0]= '1';
    y[1] = '\0';
    //printf("Hello\n\n");
    int count =strlen(power);
    //printf("Hello\n\n");
    
    //printf("Hello\n\n");
    while (count>0)
    {
        //printf("%d\n",count);
        //printf("Hello\n\n");
        char*temp = calloc(1000000,sizeof(char));
        char*temp2 = calloc(1000000,sizeof(char));
        //printf("%c\n",n[count-1]);
        if(power[count-1]%2 == 1)
            if (strlen(y) >= strlen(x))
            {   
                multi_large_nos(y,x,temp);
                strcpy(y,temp);
            }
            else
            {
                multi_large_nos(x,y,temp);
                strcpy(y,temp);
            }
    
        
        //printf("y:%s = %s\n",y,temp);
        multi_large_nos(x,x,temp2);
        strcpy(x,temp2);
        //printf("x:%s = %s\n",x,temp2);
        count--;
        free(temp);
        free(temp2);
    }
    return y;
}

int main()
{
    clock_t begin = clock();
    char *arr =  calloc(1000000,sizeof(char));
    char *num1 = calloc(1000000,sizeof(char));
    char *num2 = calloc(1000000,sizeof(char));
    scanf("%s",num1);
    scanf("%s",num2);
    arr = power(num1,num2);
    printf("\n%s\n",arr);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);
    return 0;
}
