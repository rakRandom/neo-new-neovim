#ifndef STRING_H
#define STRING_H

#include "../core/main.h"

// ====================  ====================

struct String;

int str_resize(struct String * str, size_t size); 
void print_str(struct String * str); 


// ====================  ====================

struct String {
    char * buffer;
    size_t size;
};

int str_resize(struct String * str, size_t size) 
{
    str->buffer = (char*) calloc(size, sizeof(char));
    if (str->buffer == NULL)
        return 1;
    return 0;
}

void print_str(struct String * str) 
{
    for (size_t i = 0; i < str->size; i++) 
    {
        putchar(str->buffer[i]);
    }
}


#endif // STRING_H
