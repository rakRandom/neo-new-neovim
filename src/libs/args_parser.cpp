#include "args_parser.hpp"
#include <cstdlib>

#define PTR_SIZE 64

int verifyArgs(int argc) 
{
    if (argc < 2)
        return 1;

    return 0;
}


char **getValues(int argc, char** argv) 
{
    char **values = (char**) calloc(PTR_SIZE , sizeof(char*));
    int addIndex = 0;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
        {
            values[addIndex] = argv[i];
            addIndex++;
        }
    }
    
    return values;
}


char **getOptions(int argc, char** argv) 
{
    char **options = (char**) calloc(PTR_SIZE, sizeof(char*));
    int addIndex = 0;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            options[addIndex] = argv[i];
            addIndex++;
        }
    }
    
    return options;
}
