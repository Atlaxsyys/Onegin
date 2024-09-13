#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(const char* indicator_poem_buffer[], int counter);
long size_onegin(FILE* fp);
int n_string(char* poem_buffer, long count);

int main(void)
{
    FILE* file_of_onegin = (fopen("onegin.txt", "r"));
    if (file_of_onegin == NULL)
    {
        printf("ERROR");
        return 0;
    }

    long size_file = size_onegin(file_of_onegin);

    char* poem_buffer = (char*)calloc((size_t)size_file + 1, sizeof(char));

    long count = fread(poem_buffer, 1, (size_t)size_file, file_of_onegin);
    fclose(file_of_onegin);
    printf("%s\n", poem_buffer);

    int counter_string = n_string(poem_buffer, count);
    printf("%d\n", counter_string);
    const char* indicator_poem_buffer[counter_string] = {};
    int pointer = 1;
    fprintf(stderr, "bebra: %p\n", &poem_buffer[0]);
    indicator_poem_buffer[0] = &(poem_buffer[0]);
    for (int i = 0; i < count; i++)
    {
        if (poem_buffer[i] == '\n')
        {
            poem_buffer[i] = '\0';
            indicator_poem_buffer[pointer] = &(poem_buffer[i + 1]);
            fprintf(stderr, "bebra: %p\n", &poem_buffer[i]);
            pointer++;
        }
    }

    //sort(indicator_poem_buffer, counter_string);

    for (int i = 0; i < counter_string; i++)
    {
        printf("%p \n", indicator_poem_buffer[i]);
    }
}

void sort(const char* indicator_poem_buffer[], int counter)
{
    for (int j = 0; j < counter; j++)
    {
        for (int i = 0; i < counter - 1; i++)
        {
            int biger_or_shorter = strcmp(indicator_poem_buffer[i], indicator_poem_buffer[i + 1]);

            if (biger_or_shorter < 0)
            {
                const char* temp = 0;
                temp = indicator_poem_buffer[i + 1];
                       indicator_poem_buffer[i + 1] = indicator_poem_buffer[i];
                                                      indicator_poem_buffer[i] = temp;
            }
        }
    }
}

long size_onegin(FILE* fp)
{
    if (!fp)
    {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long size_oneg = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    return size_oneg;
}

int n_string(char* poem_buffer, long count)
{       
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