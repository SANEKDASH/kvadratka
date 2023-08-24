#ifndef algorithm
#define algorithm

//! Calculates the discriminant, returns its value based on the values of the coefficients of the quadratic equation
//!
//! @param ptr_coeffients    pointer to the structure with the coefficients of the quadratic equation
double CalculateDiscriminant(const Coeffs *ptr_coefficients);

//!Calculates the roots of a quadratic equation, writes their value into a structure with roots.
//!Returns a constant corresponding to two or one root
//!
//! @param ptr_coeffients    pointer to a structure with coefficients of a quadratic equation
//! @param discriminant    discriminant value
//! @param ptr_solutions    pointer to the structure with the roots of the quadratic equation
//!
//! @note if the root of the square equation is one, then both roots in the solution structure are equal
//! @see types.h
static RootsCount SolveQuadCase(const Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions);

//! Calculates the values of the single root of the equation with the coefficient A = 0
//! Returns a constant corresponding to one root
//!
//! @param ptr_coeffients    pointer to a structure with coefficients of a quadratic equation
//! @param ptr_solutions    pointer to a structure with roots of a quadratic equation
//!
//! @note both roots in the structure become equal to each other *
//! @see types.h
static RootsCount SolveLinearCase(const Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);

//! Solves a quadratic equation. Returns a constant corresponding to the number of roots.
//!
//! @param ptr_coefficients    pointer to a structure with quadratic equation coefficients
//! @param ptr_solutions    pointer to a structure with roots of a quadratic equation
//!
//! @note If two roots are present, first root is greater.
//! @see types.h
void SolveEquation(const Coeffs *ptr_coefficients,
                         Solutions *ptr_solutions);
//! Determines if two numbers are equal
//! @param number_1    the first number
//! @param number_2    the second number
bool AreEqual(double number_1,
              double number_2);

#endif
