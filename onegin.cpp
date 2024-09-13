#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(const char* indicator_poem_buffer[], int counter);
long size_onegin(FILE* fp);


int main(void)
{
    FILE* fp = (fopen("onegin.txt", "r"));

    long size_file = size_onegin(fp);

    char* poem_buffer = (char*)calloc((size_t)size_file + 1, sizeof(char));

    long count = fread(poem_buffer, 1, (size_t)size_file, fp);
    fclose(fp);
    printf("%s\n", poem_buffer);
    int counter_string = 0;
    for (int pointer = 0; pointer < count; pointer++)
    {
        if (poem_buffer[pointer] == '\n')
        {
            counter_string++;
        }
    }
    const char* indicator_poem_buffer[counter_string];
    int j = 1;
    indicator_poem_buffer[0] = &(poem_buffer[0]);
    for (int i = 0; i < count; i++)
    {
        if (poem_buffer[i] == '\n')
        {
            indicator_poem_buffer[j] = &(poem_buffer[i + 1]);
            poem_buffer[i] = '\0';
            j++;
        }
    }
    sort(indicator_poem_buffer, counter_string);
    for (int i = 0; i < counter_string; i++)
    {
        printf("%s \n", indicator_poem_buffer[i]);
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