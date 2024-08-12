#ifndef FILE_H
#define FILE_H

#include "main.h"

// ====================  ====================

size_t f_length(FILE *f); 
void r_file(char * buffer, size_t f_len, FILE *f); 


// ====================  ====================

size_t f_length(FILE *f) 
{
    size_t size = 0;

    // Get file size
    fseek(f, 0L, SEEK_END);
    size = ftell(f) * 2 + 1;
    fseek(f, 0L, SEEK_SET);

    return size;
}

void r_file(char * buffer, size_t f_len, FILE *f) 
{
    fread(buffer, sizeof(char), f_len , f);
    buffer[f_len] = '\0';
}


#endif // FILE_H