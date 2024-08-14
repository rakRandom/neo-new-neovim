#ifndef FILE_H
#define FILE_H

#include <stdlib.h>

// ==================== Definition ====================


/*
  ## Usage 
  None 

  ## Important 
  None 

  ## Parameters 
  - ` ` - ; 

  ## Return values 
  - ` ` - ; 
*/
size_t f_length(FILE *f); 


/*
  ## Usage 
  None 

  ## Important 
  None 

  ## Parameters 
  - ` ` - ; 

  ## Return values 
  - ` ` - ; 
*/
char * f_read(size_t f_len, FILE *f); 


// ==================== Code ====================

size_t f_length(FILE *f) 
{
    size_t size = 0;

    // Get file size
    fseek(f, 0L, SEEK_END);
    size = ftell(f) * 2 + 1;
    fseek(f, 0L, SEEK_SET);

    return (size_t) (size / 2) + 1;
}

char * f_read(size_t f_len, FILE *f) 
{
    // Why "f_len * 2"? Because f_len return the actual amount of characters in the file, but it also have '\0' between the characters, making it the double size
    size_t actual_file_size = f_len * 2;

    char * buffer = (char*) malloc(actual_file_size);
    if (buffer == NULL)
        return NULL;

    fread(buffer, sizeof(char), actual_file_size, f);
    
    for (size_t i = 0; i < f_len; i++) {
        buffer[i] = buffer[i * 2];
    }

    buffer[f_len] = '\0';
    return buffer;
}

#endif // FILE_H
