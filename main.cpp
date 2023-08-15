#include "funcs.h"


int main()
{

    Coeffs coefficients ={0};

    while(ReadCoeffs(&coefficients) != kInputSucces)
    {
        PrintInputErrorMessage();
    }

    double discriminant = 0;
    discriminant = CalculateDiscriminant(&coefficients);

    Solutions solutions = {0};
    RootsCount solutions_count;
    solutions_count = SolveEquasion(&coefficients, &discriminant, &solutions);


    PrintOutput(coefficients, discriminant, solutions, solutions_count);

    return 0;
}
