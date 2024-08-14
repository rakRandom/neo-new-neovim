#include "core/main.h"
#include "core/terminal.h"
#include "core/file.h"
#include "core/utils.h"
#include "lib/string.h"


void print_filename(char *filename, int columns) 
{
    size_t len = strlen(filename);

    tc_move_cursor(1, 0);
    printf("\x1B[47;30m ");
    for (int i = 0; i < columns - 2; i++) {
        if (i < len) {
            printf("%c", filename[i]);
        }
        else {
            printf(" ");
        }
    }
    printf(" \x1B[0m");
}


int main(int argc, char** argv) 
{
    // Getting terminal size
    int *terminal_size;

    terminal_size = get_terminal_width_and_height();
    if (terminal_size == NULL) {
        printf("Error: not enough memory");
        return -1;
    }

    int columns = terminal_size[0];
    int rows = terminal_size[1];
    free(terminal_size);  // Note: don't forget to free the pointers ;)

    // Reading the file and copying it to a buffer
    char *filename = argv[1];
    FILE *f;

    struct String * file_buffer = new_String(0);
    if(fopen_s(&f, filename, "r, ccs=UTF-8") == 0) {
        // Get file length
        size_t f_len = f_length(f);
        
        // Alloc memory to the buffer
        char * buffer = f_read(f_len, f);
        if (buffer == NULL) { 
            printf("Error: not enough memory (%liB)", f_len * 2); 
            fclose(f); 
            return -1; 
        } 
        str_copy(file_buffer, buffer, f_len);
        free(buffer);
        
        fclose(f);
    }

    // Dividing the file buffer into separate strings
    size_t line_count = count_char(file_buffer, '\n');
    struct String * str_array = (struct String *) calloc(line_count + 1, sizeof(struct String));
    
    for (size_t i = 0; i < line_count + 1; i++) {
        if (str_alloc(&str_array[i], 256)) {
            printf("Error: not enough memory (256B)");
            return -1;
        }
    }

    size_t str_array_i = 0;  // Index of the array -> arr[str_array_i]
    size_t str_array_ipos = 0;  // Index of the last added char on a str_array element
    
    char fb_char = 0;
    for (size_t buf_ipos = 0; buf_ipos < file_buffer->capacity; buf_ipos++) {
        fb_char = file_buffer->buffer[buf_ipos];

        str_array[str_array_i].buffer[str_array_ipos] = fb_char;
        str_array[str_array_i].length++;
        str_array_ipos++;

        if (fb_char == '\n') {
            str_array_i++;
            str_array_ipos = 0;
        }
    }

    // Terminal config
    tc_enter_alt_screen();
    
    // Preparation to start printing
    char *line_count_as_string = (char*)malloc(64);
    int indentation = sprintf(line_count_as_string, "%li", line_count) + 2;
    if (line_count_as_string != NULL) {
        free(line_count_as_string);
    }
    
    size_t last_line_printed = 0;
    do {
        reset_cursor();
        print_filename(filename, columns);

        int current_row = 2;
        for (size_t i = last_line_printed; i < last_line_printed + rows - 2; i++) {
            printf("%li ", i + 1);
            print_str(&str_array[i], current_row, indentation);
            current_row++;

            if (i == line_count) { 
                putchar('\n'); 
                break; 
            }
        }
        last_line_printed += rows - 2;

        pause();
    } while(last_line_printed < line_count);
    
    // Program end
    tc_exit_alt_screen();
    free_String(file_buffer);

    for (size_t i = 0; i < line_count + 1; i++) 
        free(str_array[i].buffer);
    free(str_array);

    return 0;
}
