#include "array.h"


struct IntArray * new_IntArray(size_t size) 
{
    struct IntArray * int_array = (struct IntArray*) malloc(sizeof(struct IntArray));

    if (int_array == NULL) {
        return NULL;
    }

    int_array->i_pos = 0;
    int_array->size = size;

    int_array->buffer = (size_t *) calloc(size, sizeof(size_t));
    if (int_array->buffer == NULL) {
        free(int_array);
        return NULL;
    }

    return int_array;
}

void free_IntArray(struct IntArray *int_array) 
{ 
    if (int_array != NULL) { 
        free(int_array->buffer); 
        free(int_array); 
    } 
} 

int push_IntArray(struct IntArray *int_array, size_t value) 
{
    if (int_array->i_pos > int_array->size) {
        return 1;
    }

    int_array->buffer[int_array->i_pos] = value;
    int_array->i_pos++;
    return 0;
}

int pop_IntArray(struct IntArray *int_array)
{
    if (int_array->i_pos == int_array->size) {
        return 1;
    }

    int_array->buffer[int_array->i_pos] = 0;
    int_array->i_pos--;

    return 0;
}
