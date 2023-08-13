#include <stdio.h>
#include <math.h>

typedef enum
{
    kZeroRoots,
    kOneRoot  ,
    kTwoRoots ,
    kInfRoots ,
} RootsCount_t;


typedef struct
{
    double a;
    double b;
    double c;
} Coeffs;


typedef struct
{
    double x1;
    double x2;
} Solutions;

typedef enum
{
    kReadError
} ReadCases;

double CalculateDiscriminant(Coeffs *ptr_coefficients)
{
    return pow(ptr_coefficients->b, 2) - 4 * ptr_coefficients->a * ptr_coefficients->c;
}


void SolveQuadEquasion(Coeffs *ptr_coefficients, double discriminant, Solutions* solutions)
{
    solutions->x1 = (-ptr_coefficients->b + sqrt(discriminant)) / (2 * ptr_coefficients->a);
    solutions->x2 = (-ptr_coefficients->b - sqrt(discriminant)) / (2 * ptr_coefficients->a);
}


void SolveLinearEquasionCase(Coeffs *ptr_coefficients, Solutions* ptr_solutions)
{
    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;
}


int ReadCoeffs(Coeffs* coeffs)
{
    printf("enter A coeff. value: ");
    while(scanf("%lf", &coeffs->a) < 0 )
        printf("enter A coeff. value: ");

    printf("enter B coeff. value: ");
    while(scanf("%lf", &coeffs->b) < 0 )
        printf("enter A coeff. value: ");

    printf("enter C coeff. value: ");
    while(scanf("%lf", &coeffs->c) < 0 )
        printf("enter A coeff. value: ");
}


RootsCount_t solve_equasion(Coeffs *ptr_coefficients,
                            double discr,
                            Solutions* ptr_solutions)
{
    if (discr < 0)
    {
        return kZeroRoots;
    }
    else if (ptr_coefficients->a != 0)
    {

        SolveQuadEquasion(ptr_coefficients, discr, ptr_solutions);

        if (ptr_solutions->x1 == ptr_solutions->x2)
        {
            return kOneRoot;
        }
        else
        {
            return kTwoRoots;

        }
    }
    else
    {
        if (ptr_coefficients->b == 0)
        {
            if (ptr_coefficients->c == 0)
            {
                return kInfRoots;
            }
            else
            {
                return kZeroRoots;
            }
        }
        else
        {
            SolveLinearEquasionCase(ptr_coefficients, ptr_solutions);

            return kOneRoot;
        }
    }


}


void PrintOutput(Coeffs coefficients,
                  double discriminant,
                  Solutions solutions,
                  RootsCount_t solutions_count)
{
    printf("____________________________________\n");
    printf("\nA = %0.2lf | B = %0.2lf | C = %0.2lf\n", coefficients.a,
                                                       coefficients.b,
                                                       coefficients.c);
    printf("\tD = %.2lf\n", discriminant);
    printf("____________________________________\n");

    switch (solutions_count)
    {
        case kZeroRoots:
            printf("there are no any solutions\n");
            break;

        case kOneRoot:
            printf("there is one solution:\n");
            printf("\tx = %.2lf\n", solutions.x1);
            break;

        case kTwoRoots:
            printf("there are two roots:\n");
            printf("\tx1 = %.2lf\n\tx2 = %.2lf\n", solutions.x1, solutions.x2);
            break;

        case kInfRoots:
            printf("there are a lot of roots :)\n");
            break;

        default:
            printf("what the fuck!?\n");
            break;
    }

    printf("____________________________________\n");
}



int main()
{

    Coeffs coefficients;
    coefficients = {0};
;
    ReadCoeffs(&coefficients);

    double discriminant = 0;
    discriminant = CalculateDiscriminant(&coefficients);

    RootsCount_t output_print_mode;
    Solutions solutions;

    solutions = {0};

    RootsCount_t solutions_count;
    solutions_count = solve_equasion(&coefficients, discriminant, &solutions);

    PrintOutput(coefficients, discriminant, solutions, solutions_count);

    return 0;
}
