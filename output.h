#ifndef output
#define output

//! Sets color in cmd
//!
//! @param color_code code of color you need to set in cmd
//!
//! @see types.h
void SetColor(const int color_code);

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


//! Colorful printf
//!
//! @param color_code code of color defined in types.h
//! @param str needed string to print
//!
//! @see types.h

void cPrintf(const int color_code, const char *str);

#endif


