#ifndef algorithm
#define algorithm

//! Calculates the discriminant, returns its value based on the values of the coefficients of the quadratic equation
//!
//! @param ptr_coeffients    pointer to the structure with the coefficients of the quadratic equation
double CalculateDiscriminant(const Coeffs *ptr_coefficients);

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
