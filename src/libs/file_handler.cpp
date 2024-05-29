#include "file_handler.hpp"
#include <fstream>

int readFile(char * buffer, const size_t b_size, const char * path)
{
    std::ifstream file(path);
    if (!file.is_open())
        return 1;

    file.read(buffer, b_size);
    file.close();
    return 0;
}


int writeFile(char * buffer, const size_t b_size, const char * path)
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
