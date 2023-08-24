#ifndef debug
#define debug

/*!
 * Debug header
 */

/*!
 * Checks expr expression for falsity (used when debagging)
 *
 * @param expr expression being checked
 * @param line line number
 * @param func_name name of the function in which the check is performed
 * @param file_name name of the file in which the check is performed
 */

void CheckIt(bool expr,
             int line,
             const char* func_name,
             const char* file_name);

#endif
