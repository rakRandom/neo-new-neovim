#include "string.h"


int str_resize(struct String * str, size_t size) 
{
    str->buffer = (char*) calloc(size, sizeof(char));
    if (str->buffer == NULL)
        return 1;
    return 0;
}

void print_str(struct String * str) 
{
    for (size_t i = 0; i < str->size; i+=2) 
    {
        putchar(str->buffer[i]);
    }
}