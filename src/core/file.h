#ifndef FILE_H
#define FILE_H

#include "main.h"

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
void f_read(char * buffer, size_t f_len, FILE *f); 




// ==================== Code ====================

size_t f_length(FILE *f) 
{
    size_t size = 0;

    // Get file size
    fseek(f, 0L, SEEK_END);
    size = ftell(f) * 2 + 1;
    fseek(f, 0L, SEEK_SET);

    return size;
}

void f_read(char * buffer, size_t f_len, FILE *f) 
{
    fread(buffer, sizeof(char), f_len , f);
    buffer[f_len] = '\0';
}

#endif // FILE_H
