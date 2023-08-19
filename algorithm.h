double CalculateDiscriminant(Coeffs *ptr_coefficients);

RootsCount SolveQuadCase(Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions);

RootsCount SolveLinearCase(Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);

RootsCount SolveEquation(Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions);
