#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <assert.h>

long size_onegin(FILE* fp);
int n_string(char* poem_buffer, long count);
void output(const char** indicator_poem_buffer, FILE* output_onegin, int counter_string);

int main(void) // TODO argc argv, аргументы командной строки
{
    FILE* file_of_onegin = fopen("onegin.txt", "r");
    if (file_of_onegin == NULL)
    {
        fprintf(stderr, "ERROR\n");
        return 0;
    }

    long size_file = size_onegin(file_of_onegin);

    char* poem_buffer = (char*)calloc((size_t)size_file + 1, sizeof(char));

    fprintf(stderr, "poem_buffer: [%p, %p]", poem_buffer, poem_buffer + size_file);

    long count = fread(poem_buffer, sizeof(char), (size_t)size_file, file_of_onegin);
    fclose(file_of_onegin);

    size_t counter_string = n_string(poem_buffer, count);
    const char** indicator_poem_buffer = (const char**)calloc((size_t)counter_string + 1, sizeof(char*));
    int pointer = 1;
    indicator_poem_buffer[0] = &(poem_buffer[0]);
    for (int i = 0; i < count; i++)
    {
        assert(&(poem_buffer[i]) != NULL);
        if (poem_buffer[i] == '\n')
        {
            poem_buffer[i] = '\0';
            indicator_poem_buffer[pointer] = &(poem_buffer[i + 1]);
            pointer++;
        }
    }

    sort(indicator_poem_buffer, counter_string, sizeof(char*), compare_str_reserse);
    FILE* output_onegin = fopen("output.txt", "w");
    output(indicator_poem_buffer, output_onegin, counter_string);

    fclose(output_onegin);

    free(indicator_poem_buffer);
    free(poem_buffer);

    return 0;
}

long size_onegin(FILE* file_onegin)
{
    assert(file_onegin != NULL);

    fseek(file_onegin, 0, SEEK_END);
    long size_oneg = ftell(file_onegin);
    fseek(file_onegin, 0, SEEK_SET);
    
    return size_oneg;
}

int n_string(char* poem_buffer, long count)
{
    assert(poem_buffer != NULL);

    int counter_string = 0;
    for (int pointer = 0; pointer < count; pointer++)
    {
        if (poem_buffer[pointer] == '\n')
        {
            counter_string++;
        }
    }
    return counter_string;
}

void output(const char** indicator_poem_buffer, FILE* output_onegin, int counter_string)
{
    assert(indicator_poem_buffer != NULL);

    for (int i = 0; i < counter_string; i++)
    {
        fputs((indicator_poem_buffer[i]), output_onegin);
        fputs("\n", output_onegin);
    }
}

