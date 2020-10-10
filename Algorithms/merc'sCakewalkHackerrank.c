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
int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

// Complete the marcsCakewalk function below.
long marcsCakewalk(int calorie_count, int* calorie) 
{
    long int i,sum = 0,n;
    n = calorie_count;
    qsort(calorie,n,sizeof(int),cmpfunc);
    for(i=n-1;i>=0;i--)
    {
        sum = sum + (pow(2,(n-1-i))*calorie[i]);
    }
    return sum;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** calorie_temp = split_string(readline());

    int* calorie = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* calorie_item_endptr;
        char* calorie_item_str = *(calorie_temp + i);
        int calorie_item = strtol(calorie_item_str, &calorie_item_endptr, 10);

        if (calorie_item_endptr == calorie_item_str || *calorie_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(calorie + i) = calorie_item;
    }

    int calorie_count = n;

    long result = marcsCakewalk(calorie_count, calorie);

    fprintf(fptr, "%ld\n", result);

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
