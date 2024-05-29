#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

/* Saves `n_char` characters of the content from a file at `path` to the buffer `buffer`
 * Returns:
 * 0 - successful
 * 1 - could not open the file
 */
int readFile(char * buffer, const size_t n_char, const char * path);

/* Saves a `buffer` with certain `b_size` to the file localized in `path`
 * Returns:
 * 0 - successful
 * 1 - could not open the file
 * 2 - write operation failed (file corruption)
 */
int writeFile(char * buffer, const size_t b_size, const char * path);

#endif // FILE_HANDLER_HPP
