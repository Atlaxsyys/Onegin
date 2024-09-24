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
    fprintf(stderr, "counter : %lld\n", counter);
    for (size_t j = 0; j < counter; j++)
    {
        for (size_t i = 0; i < counter - 1; i++)
        {
            void* element_first = (char*) indicator_poem_buffer + i * size_element;
            void* element_second = (char*) element_first + size_element;
            void* element_first_copy = (char*) indicator_poem_buffer + i * size_element;
            void* element_second_copy = (char*) element_first + size_element;
            int biger_or_shorter = compare_str_reserse(element_first, element_second);
            if (biger_or_shorter > 0)
            {
                swap(element_first, element_second);
                if (element_first_copy == element_second && element_second_copy == element_first)
                {
                     fprintf(stderr, "OK");
                }

            }
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
    int len_first = strlen(str_first);
    int len_second = strlen(str_second);

    const char* p_first = str_first + len_first - 1;
    const char* p_second = str_second + len_second - 1;

    while (p_first >= str_first && p_second >= str_second)
    {
        if (tolower(*p_first) > tolower(*p_second)) {
            return bigger;
        } else if (tolower(*p_first) < tolower(*p_second)) {
            return smaller;
        }
        p_first--;
        p_second--;
    }

    if (len_first > len_second) 
    {
        return bigger;
    } 
    else if (len_first < len_second) 
    {
        return smaller;
    }
    return equality;
}

void swap(void* str1, void* str2)
{
    char** str_first = (char**) str1;
    char** str_second = (char**) str2;
    char* temp = 0;
    temp = *str_second;
           *str_second = *str_first;
                        *str_first = temp;
}

int compare_str_reserse(void* str1, void* str2)
{
    return my_strcmp_reverse(*(char**)str1, *(char**)str2);
}