#include "types.h"
#include "input.h"
#include "algorithm.h"
#include "output.h"
#include "debug.h"

int main()
{
    Coeffs coefficients = {0};
    ReadCoeffs(&coefficients);

    double discriminant = CalculateDiscriminant(&coefficients);

    Solutions solutions = {0};
    RootsCount solutions_count = SolveEquation(&coefficients,
                                               discriminant,
                                               &solutions);

    PrintOutput(&coefficients,
                discriminant,
                &solutions,
                solutions_count);

    return 0;
}
