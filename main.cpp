#include <iostream>
#include <fstream>
#include <cstring>

#define BUFFER_SIZE 1024


/* Saves `b_size` character of the content from a file at `path` to the buffer `buffer`
 * Returns:
 * 0 - successful
 * 1 - could not open the file
 */
int readFile(char * buffer, const size_t b_size, const char * path)
{
    std::ifstream file(path);
    if (!file.is_open())
        return 1;

    file.read(buffer, b_size);
    file.close();
    return 0;
}

/* Saves a `buffer` with certain `b_size` to the file localized in `path`
 * Returns:
 * 0 - successful
 * 1 - could not open the file
 * 2 - write operation failed (file corruption)
 */
int writeFile(char * buffer, const size_t b_size, const char * path, int line = 0, int column = 0)
{
    std::ofstream file(path);
    
    if (!file.is_open())
        return 1;

    file.write(buffer, b_size);
    if (file.badbit)
        return 2;
    
    file.close();
    return 0;
}


int main(int argc, char** argv) 
{
    if (argc < 2) {
        std::cout << "Too few arguments" << std::endl;
        return 1;
    }

    char * path = argv[1];

    // Print file at console
    if (argc == 2) {
        char buffer[BUFFER_SIZE];
        
        if (!readFile(buffer, BUFFER_SIZE, path))
            std::cout << buffer << std::endl;
        else
            return 1;
    }

    // Writes third argument to the file
    else if (argc == 3) {
        char * buffer = argv[2];
        if (writeFile(buffer, strlen(buffer), path))
            return 1;
    }

    // Too many arguments
    else {
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }

    return 0;
}
