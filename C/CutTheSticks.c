#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) {int (temp); temp = a; a = b; b = temp;}

char* readline();
char** split_string(char*);

int Partition(int numbers[], int i, int j, int pivot)
{
    int left = i;
    int right = j;

    while(left <= right)
    {
        while(left <= right && numbers[left] <= pivot)
            left++;
        while(left <= right && numbers[right] > pivot)
            right--;
        if(left <= right)
        {
            swap(numbers[left], numbers[right]);
            left++;
            right--;
        }
    }

    int p_index = left-1;
    numbers[i-1] = numbers[p_index];
    numbers[p_index] = pivot; 
    return p_index;
}

void RQuickSort(int numbers[], int left, int right)
{
    if (left<right)
    {
        int pivot = (rand()%(right-left+1)) + left;
        swap(numbers[pivot],numbers[left]);
        int p_index = Partition(numbers, left+1, right, numbers[left]);
        RQuickSort(numbers, left, p_index-1);
        RQuickSort(numbers, p_index+1, right);
    }
}

// Complete the cutTheSticks function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* cutTheSticks(int arr_count, int* arr, int* result_count) {
RQuickSort(arr, 0, arr_count-1);
int* result = malloc(1000*sizeof(int));
int min = arr[0];
int i = 0;
while(arr[arr_count-1] != 0)
{
    int count = 0;
    int k =0;
    while(arr[k]==0)
        k++;
    min = arr[k];
    result[i] = arr_count-k;
    for(int j = 0; j<arr_count; j++)
    {
        if(arr[j]!=0)
            arr[j]-= min;
    }
    i++;
}

*result_count = i;
return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    int result_count;
    int* result = cutTheSticks(arr_count, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

