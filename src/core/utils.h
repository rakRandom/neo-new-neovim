#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <stdlib.h>


/*
free the pointer

the return array has 2 elements
the first is the n. of columns
the second is the n. of rows
*/
int *get_terminal_width_and_height();


//

int *get_terminal_width_and_height() 
{
    int * r_val = (int*) calloc(2, sizeof(int));

    if (r_val == NULL)
        return NULL;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    r_val[0] = columns;
    r_val[1] = rows;

    return r_val;
}


#endif // UTILS_H
