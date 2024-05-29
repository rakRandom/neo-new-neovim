#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP

/* Verify if the arguments have erros
 * Returns:
 * 0 - no error
 * 1 - missing arguments
 * ... (options verification)
 */
int verifyArgs(int argc);

/* Returns a pointer, remember to free it
 */
char **getValues(int argc, char** argv);

/* Returns a pointer, remember to free it
 */
char **getOptions(int argc, char** argv);

#endif // ARGS_PARSER_HPP
