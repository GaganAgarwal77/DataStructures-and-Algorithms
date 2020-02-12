#include<stdio.h>
#include<stdlib.h>


int GetDecimalValue(char*num,int l,int r)
{
    int ans=0;
    for(int i=l;i<r;i++)
        ans = 2*ans +(num[i]-'0'); //Getting the Decimal Value by looping through the given number in given constraints
    return ans;
}
int ConvertIntoGivenBase(char*binary,int N,int base,char*value)
{
    char *temp = malloc(N*sizeof(char)); //creating a temporary array to store the values obtained 
    int j=0;
    for(j=0;j<N/base;j++)
    {
        temp[j] = GetDecimalValue(binary,(N-base)-(base*j),N-(base*j)) +'0';  //running through the number and obtaing the decimal values by dividing the string into base parts(3 for octal and 4 for hexadecimal)
    }
    if(base*j < N)
    {
        temp[j] = GetDecimalValue(binary,0,N%base) +'0'; //when there are numbers left in the given binary number,we find the decimal value of the leftover numbers(0's/1's)
        j++;                                                
    }
    int i=0;
    for(i =0;i<j;i++)
    {   
        if(temp[j-i-1] >= 58)
            temp[j-i-1] += 7; //For hexadecimal when ascii value >58 we have to add 7 to get >A
        value[i] =temp[j-i-1]; //reversing the temp string to get the final answer
    }
    value[i+1] ='\0'; //ending the string
    free(temp);//freeing dynamically allocated memory
}
int main()
{
    int N;
    char* binary = malloc(N*sizeof(char)); 
    scanf("%d %s",&N,binary);//taking input
    int decimal_value = GetDecimalValue(binary,0,N);
    char * octal_value = malloc(N*sizeof(char)); 
    //allocating memory dynamically to store the obtained answer
    char * hex_value = malloc(N*sizeof(char));
    ConvertIntoGivenBase(binary,N,3,octal_value);//calling the functions to store value in octal_value and hex_value strings
    ConvertIntoGivenBase(binary,N,4,hex_value);
    printf("%d,%s,%s",decimal_value,octal_value,hex_value); //printing the final answers
    free(binary);
    free(octal_value);//freeing dynamically allocated memory after printing the final answers.
    free(hex_value);
    return 0;
}