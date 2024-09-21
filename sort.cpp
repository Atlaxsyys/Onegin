#include "sort.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

enum str
{
    smaller = -1,
    equality,
    bigger
};

void sort(void* indicator_poem_buffer, size_t counter, size_t size_element, int (*compare_str_reserse)(void*, void*))
{ //TODO sort(void*, size_t, size_t, comparetor);
    assert(indicator_poem_buffer != NULL);
    int x = 0;
    fprintf(stderr, "counter : %lld\n", counter);
    for (size_t j = 0; j < counter; j++)
    {
        for (size_t i = 0; i < counter - 1; i++)
        {
            void* element_first = (char*) indicator_poem_buffer + i * size_element;
            void* element_second = (char*) element_first + (i + 1) * size_element;
            fprintf(stderr, "element_first : %p     element_second : %p \n", *(char**)element_first, *(char**)element_second);
            fprintf(stderr, "%d ", x);
            x++;
            // int biger_or_shorter = compare_str_reserse(element_first, element_second);
            // //fprintf(stderr, "idi nahui");
            // if (biger_or_shorter > 0)
            // {
            //     swap(element_first, element_second);
            // }
        }
    }
}

int my_strcmp(const char* str_first, const char* str_second)
{
    while (*str_first == *str_second && *str_first != '\0')
    {
        str_first++;
        str_second++;
    }

    if (*str_first == '\0' && *str_second == '\0')
    {
        return equality;
    }
    else if (*str_first > *str_second)
    {
        return bigger;
    }
    else
    {
        return smaller;
    }
}

int my_strcmp_reverse(const char* str_first, const char* str_second)
{
    assert(str_first != NULL);
    assert(str_second != NULL);
    size_t len_first = strlen(str_first);
    // const char* check_str = str_second;
    // int i = 0;
    // while (*check_str != '\0') {
    //     fprintf(stderr, "check_str[%d]: %x\n", i, *check_str);
    // }
    size_t len_second = strlen(str_second);
    
    const char* str_first_copy = str_first;
    const char* str_second_copy = str_second;
    
    str_first += len_first;
    str_second += len_second;
    while ((str_first > str_first_copy) && (str_second > str_second_copy))
    {
        //fprintf(stderr, "str_second : %p \n", str_second);
        if (tolower(*str_first) > tolower(*str_second))
        {
            return bigger;
        }
        else if (tolower(*str_first) < tolower(*str_second))  
        {
            return smaller;
        }
        str_first -= sizeof(char*);
        str_second -= sizeof(char*);
    }
    //fprintf(stderr, "privet \n");
    return equality;
}

void swap(void* str1, void* str2)
{
    char* str_first = (char*)str1;
    char* str_second = (char*)str2;
    char* temp = 0;
    temp = str_second;
           str_second = str_first;
                        str_first = temp; 
}

int compare_str_reserse(void* str1, void* str2)
{
    return my_strcmp_reverse(*(char**)str1, *(char**)str2);
    
}