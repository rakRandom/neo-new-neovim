#include "core/main.hpp"
#include "libs/args_parser.hpp"
#include "libs/file_handler.hpp"
#include "libs/buffer_render.hpp"

int main(int argc, char** argv) 
{
    // Arguments verification
    do {
        int verifyVal = verifyArgs(argc);
        
        if (!verifyVal) 
            break;
        
        switch (verifyVal)
        {
        case 1:
            std::cout << "Too few arguments\n";
            break;
        default:
            std::cout << "Arguments error\n";
            break;
        }
        return verifyVal;
    } while(0);

    char path[256] = { 0 };
    strcpy_s(path, argv[1]);

    // Print file at console
    if (argc == 2) {
        char buffer[BUFFER_SIZE];
        
        if (!readFile(buffer, BUFFER_SIZE, path))
            renderBuffer(buffer);
        else
            return 1;
    }

    // Writes third argument to the file
    else if (argc == 3) {
        char * buffer = argv[2];
        if (writeFile(buffer, strlen(buffer), path))
            return 1;
    }

    return 0;
}
