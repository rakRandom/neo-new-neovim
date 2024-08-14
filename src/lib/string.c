#include "string.h"


int str_copy(struct String * str, char * other_str, size_t size) 
{
    if (other_str == NULL)
        return 1;
    
    str->buffer = (char*) calloc(size, sizeof(char));
    if (str->buffer == NULL)
        return 1;

    for (size_t i = 0; i < size; i++)
        str->buffer[i] = other_str[i];

    str->size = size;
    return 0;
}

int print_str(struct String * str, int pos_x, int pos_y) 
{
    printf("\033[%d;%dH", pos_x, pos_y);
    for (size_t i = 0; i < str->size; i++) {
        putchar(str->buffer[i]);

        if (str->buffer[i] == '\n')
            break;
    }
    return 0;
}

size_t count_char(struct String * str, char c) 
{
    size_t count = 0;

    for (size_t i = 0; i < str->size; i++) 
        if (str->buffer[i] == c)
            count++; 

    return count;
}
