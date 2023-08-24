#ifndef output
#define output

/*!
 *Functions in this header print some information
 */

/*!
 * Displays the value of coefficients, roots, number of roots, discriminant of the quadratic equation
 *
 * @param ptr_coeffients pointer to the structure with coefficients of the quadratic equation
 * @param solutions_count variable equal to the constant corresponding to the number of roots of the square unit.
 * @param ptr_solutions pointer to the structure with the roots of the quadratic equation
 */
void PrintOutput(const Coeffs *coefficients,
                 const Solutions *solutions,
                 const RootsCount solutions_count);
/*!
 * Displays a greeting with the user.
 */
void PrintWelcome();
/*!
 * Displays a list with the functionality of the program.
 */
void PrintHelpList();
/*!
 * Displays a kitty on the screen.
 */
void PrintKitty();

#endif


