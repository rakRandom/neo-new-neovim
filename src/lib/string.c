#include "string.h"


struct String * new_String(size_t size) 
{
    struct String * new = (struct String*) malloc(sizeof(struct String));

    if (new == NULL)
        return NULL;

    new->buffer = (char*) malloc(size);
    if (new->buffer == NULL) {
        free(new);
        return NULL;
    }

    new->length = 0;
    new->capacity = size;

    return new;
}


void free_String(struct String * str) 
{ 
    if (str != NULL) { 
        free(str->buffer); 
        free(str); 
    } 
}


int str_alloc(struct String * str, size_t new_capacity)
{
    str->buffer = (char*) malloc(new_capacity);
    if (str->buffer == NULL)
        return 1;
    
    str->length = 0;
    str->capacity = new_capacity;

    return 0;
}


int str_copy(struct String * str, char * buffer, size_t buf_size) 
{
    if (buffer == NULL)
        return 1;
    
    // If the string doesn't have the necessary capacity, alloc more
    if (str->capacity < buf_size)
        if (str_alloc(str, buf_size))
            return 1;

    // Copying the characters, one by one
    for (size_t i = 0; i < buf_size; i++) {
        str->buffer[i] = buffer[i];
    }

    str->length = str_length(str);
    return 0;
}


size_t str_length(struct String * str) {
    size_t count = 0;

    for (size_t i = 0; i < str->capacity; i++) {
        if (str->buffer[i] == '\0')
            break;
        count++;
    }

    return count;
}


int print_str(struct String * str, int pos_x, int pos_y) 
{
    printf("\033[%d;%dH", pos_x, pos_y);
    for (size_t i = 0; i < str->length; i++) {
        putchar(str->buffer[i]);

        if (str->buffer[i] == '\n')
            break;
    }
    return 0;
}


size_t count_char(struct String * str, char c) 
{
    size_t count = 0;

    for (size_t i = 0; i < str->length; i++) 
        if (str->buffer[i] == c)
            count++; 

    return count;
}
