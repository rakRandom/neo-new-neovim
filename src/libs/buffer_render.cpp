#include "buffer_render.hpp"
#include <iostream>
#include <cstring>

#define LINE_QT   32
#define COLUMN_QT 32


inline int countLines(char * str)
{
    int lines = 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '\n')
            lines++;

    return lines;
}


inline void splitLines(char dest[LINE_QT][COLUMN_QT], char * source, const char * sep)
{
    int line = 0;
    int column = 0;

    for (int i = 0; i < LINE_QT - 1; i++)
        for (int j = 0; j < COLUMN_QT - 1; j++)
            dest[i][j] = (char) 32;

    for (int i = 0; i < strlen(source); i++)
    {
        if (source[i] < (char) 32)
        {
            if (source[i] == (char) 10)
            {
                line++;
                column = 0;
            }
            else
                break; // EOF character
        }
        else
        {
            dest[line][column] = source[i];
            column++;
        }
    }
}


int renderBuffer(char * buffer) 
{
    int linesToRender = 12;
    int bufferLines = countLines(buffer);
    char lines[LINE_QT][COLUMN_QT];
    splitLines(lines, buffer, "\n");

    if (bufferLines > linesToRender)
        linesToRender = bufferLines;
    
    for (int i = 0; i < linesToRender; i++)
    {
        if (i > bufferLines)
            std::wcout << "~ \n";
        else
        {
            std::wcout << i + 1 << " " << lines[i] << std::endl;
        }
    }

    return 0;
}
