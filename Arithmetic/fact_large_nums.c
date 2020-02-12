// Question: Find Factorial of a Numbers, whose factorial needs to be stored in a string due to size constraints.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

void swap(char *x, char *y) 
{
	char t = *x; *x = *y; *y = t;
}
char* reverse(char *buffer, int i, int j)
{

	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

char* itoa(int value, char* buffer)
{
    int base =10;
	int n = value;
	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}
	if (i == 0)
		buffer[i++] = '0';

	buffer[i] = '\0';

	return reverse(buffer, 0, i - 1);
}

void multi_large_nos(char *num1,char*num2,char*num)
{
    char *buff = calloc(100000,sizeof(char));
    char *temp = calloc(100000,sizeof(char));
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);

    for(int j=0;j<num2_len;j++)
    {
       int i =0;
       for( i =0;i<num2[num2_len-1 -j]-48;i++)
       {
           if (strlen(num1) > strlen(buff))
            {
                addLarge(num1,buff,temp);
            }
           else
           {
               addLarge(buff,num1,temp);
           }
           strcpy(buff,temp);
       } 
       int ab = strlen(buff);
       for(int k=0;k<j;k++)
        {
           buff[ab+k] = '0';
        }   
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
}

int main()
{
    clock_t begin = clock();
    char *num1 = calloc(100000,sizeof(char));
    char *fact = calloc(1000000,sizeof(char));
    char *tmp = calloc(1000000,sizeof(char));
    char *tmp2 = calloc(1000000,sizeof(char));
    scanf("%s",num1);
    int number =atoi(num1);
    strcpy(fact,num1);
    for(int i =number;i>1;i--)
    {
        char *tmp2 = calloc(1000000,sizeof(char));
        multi_large_nos(fact,itoa(number-1,tmp),tmp2);
        strcpy(fact,tmp2);
        number = number-1;
    }
    printf("%s\n",fact);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);

    return 0;
}
