#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the acmTeam function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* acmTeam(int topic_count, char** topic, int* result_count) {
int len = strlen(topic[0]);
int* result = malloc(1000*sizeof(int));
int prev_max = 0;
int max = 0; 
int max_count = 0;
for(int i =0; i<topic_count; i++)
{
    for(int j =i+1; j<topic_count; j++)
    {
        int max = 0;
        for(int k =0; k<len; k++)
        {
            if(topic[i][k] == '1' || topic[j][k] == '1')
            {
                max++;
            }
        }
        if(max > prev_max)
        {
            prev_max = max;
            max_count = 1;
        }
        else if(max == prev_max)
        {
            max_count++;
        }
    }
}
result[0] = prev_max;
result[1] = max_count;
*result_count = 2;
return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** topic = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* topic_item = readline();

        *(topic + i) = topic_item;
    }

    int topic_count = n;

    int result_count;
    int* result = acmTeam(topic_count, topic, &result_count);

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

