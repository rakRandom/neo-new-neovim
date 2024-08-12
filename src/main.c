#include "core/main.h"
#include "core/terminal.h"
#include "core/file.h"
#include "lib/string.h"


int main(int argc, char** argv) 
{
    char *filename = argv[1];
    FILE *f;

    tc_enter_alt_screen();
    tc_clear_screen();
    tc_move_cursor(0, 0);
    
    if(fopen_s(&f, filename, "r, ccs=UTF-8") == 0) 
    {
        struct String str;
        size_t f_len;

        // Get file length
        str.size = f_len = f_length(f);
        
        // Alloc memory to the buffer
        if (str_resize(&str, f_len)) {
            printf("Error: not enough memory (%lib)", str.size);
        } else {
            // Read the file
            r_file(str.buffer, f_len, f);
            // Print the result
            print_str(&str);
        }
        free(str.buffer);
        fclose(f);
    }

    printf("\033[8m");
    getchar();
    printf("\033[0m");
    tc_exit_alt_screen();

    return 0;
}
