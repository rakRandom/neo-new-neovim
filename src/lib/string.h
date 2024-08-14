#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
  ## Definition
  Strucuture to hold a buffer and a size.
  Defines a String. 

  ## Important
  If you allocate memory into the buffer, free it before the end of the program
*/
struct String {
    char * buffer;
    size_t length;
    size_t capacity;
};


/*

*/
struct String * new_String(size_t initial_size); 


/*
if you get a pointer of it, you need to free it, isn't?
*/
void free_String(struct String * str); 


/*
*/
int str_alloc(struct String * str, size_t new_capacity);


/*
returns the length of the String and also stores it
*/
size_t str_length(struct String * str);


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
int str_copy(struct String * str, char * other_str, size_t size); 


/* 
  ## Usage
  Prints the String into the terminal using `putchar()` on each character of the buffer

  ## Parameters
  - `str: struct String *` - String to be printed;

  ## Return values
  None
*/
int print_str(struct String * str, int pos_x, int pos_y); 


/*

*/
size_t count_char(struct String * str, char c); 


#endif // STRING_H
