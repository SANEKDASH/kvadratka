#ifndef test
#define test
/*!
 * Functions in this header are responsible for tests
 */

/*!
 * Displays the test results on the screen
 *
 * @see TesrAlgorithm() ConvertBuf_test() GetInput_test() GetCoeffsAndSolutions
 */
void Test();
/*!
 * Checks whether the values of the roots obtained from the file are equal test.txt , with the values of the roots obtained by the algorithm of the program
 *
 * @param ptr_coeffients pointer to the structure with the coefficients of the quadratic equation
 * @param ptr_real_solutions pointer to a structure with solutions of sq.ur. obtained from test.txt
 */
int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions);

/*!
 * Records the coefficients, the real roots of the square.ur from file to buffer.
 *
 * @param ptr_file pointer to the file being read
 * @param solutions_count variable equal to the constant corresponding to the number of roots of sq.ur.
 * @param ptr_solutions pointer to the structure with the roots of the quadratic equation
 *
 * @note In case of incorrect entry returns the kInputError error
 *
 *@see types.h
 */

InputResults GetInput_test(FILE *ptr_file,
                           Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);
/*!
 * Reads the coefficients, the real roots of the equation from the buffer
 *
 * @param buf buffer
 * @param solutions_count variable equal to the constant corresponding to the number of roots of the square unit.
 * @param ptr_solutions pointer to the structure with the roots of the quadratic equation
 *
 */
InputResults GetCoeffsAndSolutions(char *buf,
                                   Coeffs *ptr_coefficients,
                                   Solutions *ptr_solutions);

#endif