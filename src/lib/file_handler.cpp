#include "file_handler.hpp"


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
