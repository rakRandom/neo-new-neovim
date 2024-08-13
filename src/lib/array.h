#ifndef ARRAY_H
#define ARRAY_H

#include "stdlib.h"


/*

*/
struct IntArray {
    size_t i_pos;
    size_t size;
    size_t *buffer;
};


/*

*/
struct IntArray * new_IntArray(size_t size); 


/*

*/
void free_IntArray(struct IntArray *int_array); 


/*

*/
int push_IntArray(struct IntArray *int_array, size_t value); 


/*

*/
int pop_IntArray(struct IntArray *int_array); 

 
#endif // ARRAY_H 
