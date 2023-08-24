#ifndef input
#define input
/*!
 * The functions in this header are responsible for the user's interaction with the program.
 */

/*!
 * Writes the characters read from the file to the buffer, outputs a constant corresponding to the command written to the buffer.
 * @param ptr_file pointer to a readable file.
 * @param ptr_coeffients pointer to the structure of coefficients.
 *
 * @note if there are three coefficients in the buffer, they are written to the structure pointed to by ptr_coeffients.
 *
 * @see ConvertBuf() ConvertBufToCoeffs()input.h
 */
InputResults GetInput(FILE *ptr_file, Coeffs *ptr_coefficients);

/*!
 * Causes interference
 * @param ptr_coeffisients pointer to the structure of the coefficients of the quadratic equation.
 * @param solutions pointer to a structure with solutions of a quadratic equation.
 *
 * @note when entering certain commands, outputs the corresponding text
 *
 * @see GetInput() ConvertBuf() ConvertBufToCoeffs() input.h
 */
void CallInputInterface(Coeffs *ptr_coefficients, Solutions *solutions);

/*!
 * Checks whether the string written in the buffer is a command. Outputs the constant corresponding to the command.
 * @param buf buffer
 * @param ptr_coeffients pointer to the coefficient structure
 *
 * @note if there are three coefficients in the buffer, they are written to the structure pointed to by ptr_coeffients.
 *
 * @see ConvertBufToCoeffs() input.h
 */
InputResults ConvertBuf(char *buf, Coeffs *ptr_coefficients);

/*!
 * Writes the values of the coefficients specified in the buffer to the coefficient structure
 *
 * @param buf buffer
 * @param ptr_coeffients pointer to the structure of coefficients
 *
 * @note if coefficients are written incorrectly in the buffer, returns the kInputError error
 *
 * @see input.h
 */

InputResults ConvertBufToCoeffs(char *buf, Coeffs *ptr_coefficients);

#endif


