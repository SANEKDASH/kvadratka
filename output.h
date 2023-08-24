#ifndef output
#define output

//! Displays the value of coefficients, roots, number of roots, discriminant of the quadratic equation
//!
//! @param ptr_coeffients    pointer to the structure with coefficients of the quadratic equation
//! @param ptr_solutions    pointer to the structure with roots and number of roots in quadratic equation

void PrintOutput(const Coeffs *coefficients,
                 const Solutions *solutions);

//! Displays a greeting with the user.
void PrintWelcome();

//! Displays a list with the functionality of the program.
void PrintHelpList();

//! Displays a kitty on the screen.
void PrintKitty();

#endif


