#include "funcs.h"


int main()
{

    Coeffs coefficients = {0};

    ReadCoeffs(&coefficients);

    double discriminant = discriminant = CalculateDiscriminant(&coefficients);

    Solutions solutions = {0};
    RootsCount solutions_count = SolveEquasion(&coefficients,
                                               &discriminant,
                                               &solutions);

    PrintOutput(&coefficients,
                &discriminant,
                &solutions,
                &solutions_count);

    return 0;
}
