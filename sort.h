#include <string.h>
void sort(void* indicator_poem_buffer, size_t counter, size_t size_element, int (*compare_str_reserse)(void*, void*));
int my_strcmp(const char* str_first, const char* str_second);
int my_strcmp_reverse(const char* str_first, const char* str_second);
void swap(void* str1, void* str2);
int compare_str_reserse(void* str1, void* str2);