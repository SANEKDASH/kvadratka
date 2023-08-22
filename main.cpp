#include "types.h"
#include "input.h"
#include "algorithm.h"
#include "output.h"
#include "debug.h"

int main()
{
    PrintWelcome();

    Coeffs coefficients = {0};
    ReadCoeffs(&coefficients);

    Solutions solutions = {0};
    RootsCount solutions_count = SolveEquation(&coefficients,
                                               &solutions);

    PrintOutput(&coefficients,
                &solutions,
                solutions_count);

    return 0;
}
