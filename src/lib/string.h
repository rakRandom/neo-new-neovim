#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>


/* 
  ## Definition
  Strucuture to hold a buffer and a size.
  Defines a String. 

  ## Important
  If you allocate memory into the buffer, free it before the end of the program
*/
struct String {
    char * buffer;
    size_t size;
};


/*
  ## Usage 
  Allocates memory to the String buffer using `calloc()` 

  ## Important
  Free the String buffer before the end of the program

  ## Parameters
  - `str: struct String *` - String where the buffer will be resized;
  - `size: size_t` - new size of the buffer;

  ## Return values
  - `0` - Default OK;
  - `1` - Fail in allocating memory;
*/
int str_resize(struct String * str, size_t size); 


/* 
  ## Usage
  Prints the String into the terminal using `putchar()` on each character of the buffer

  ## Parameters
  - `str: struct String *` - String to be printed;

  ## Return values
  None
*/
void print_str(struct String * str); 


#endif // STRING_H
