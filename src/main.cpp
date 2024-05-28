#include "core/main.hpp"
#include "libs/file_handler.hpp"


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
            std::cout << buffer;
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
