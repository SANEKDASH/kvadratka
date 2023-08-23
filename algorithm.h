#ifndef algorithm
#define algorithm

double CalculateDiscriminant(const Coeffs *ptr_coefficients);

RootsCount SolveQuadCase(const Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions);

RootsCount SolveLinearCase(const Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);

RootsCount SolveEquation(const Coeffs *ptr_coefficients,
                         Solutions *ptr_solutions);

int AreEqual(double number_1, double number_2);

#endif
