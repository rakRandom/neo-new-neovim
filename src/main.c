#include "core/main.h"
#include "core/terminal.h"
#include "core/file.h"
#include "lib/string.h"


int main(int argc, char** argv) 
{
    char *filename = argv[1];
    FILE *f;
    
    if(fopen_s(&f, filename, "r, ccs=UTF-8") == 0) 
    {
        struct String str;
        size_t f_len;

        // Get file length
        str.size = f_len = f_length(f);
        
        // Alloc memory to the buffer
        if (str_resize(&str, f_len)) 
        {
            printf("Error: not enough memory (%lib)", str.size);
            free(str.buffer);
            fclose(f);
            return 1;
        }

        // Read the file
        r_file(str.buffer, f_len, f);
        
        // Print the result
        print_str(&str);
        free(str.buffer);

        fclose(f);
    }

    return 0;
}
