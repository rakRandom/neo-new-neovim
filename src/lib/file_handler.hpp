#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>

int readFile(char * buffer, const size_t b_size, const char * path);
int writeFile(char * buffer, const size_t b_size, const char * path);

#endif // FILE_HPP
