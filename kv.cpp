#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

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
    kInputError,
    kInputSucces,
} InputResults_t;

double CalculateDiscriminant(Coeffs *ptr_coefficients);

void SolveQuadCase(Coeffs *ptr_coefficients,
                       double discriminant,
                       Solutions* solutions);

void SolveLinearCase(Coeffs *ptr_coefficients, Solutions* ptr_solutions);

InputResults_t ReadCoeffs(Coeffs* ptr_coefficients);

RootsCount_t SolveEquasion(Coeffs *ptr_coefficients,
                            double discr,
                            Solutions* ptr_solutions);

void PrintOutput(Coeffs coefficients,
                  double discriminant,
                  Solutions solutions,
                  RootsCount_t solutions_count);

void PrintInputErrorMessage();

int debug_printf( const char* fmt, ...);

int main()
{

    Coeffs coefficients;
    coefficients = {0};

    while(ReadCoeffs(&coefficients) != kInputSucces)
    {
        PrintInputErrorMessage();
    }

    double discriminant = 0;
    discriminant = CalculateDiscriminant(&coefficients);

    Solutions solutions;
    solutions = {0};

    RootsCount_t solutions_count;
    solutions_count = SolveEquasion(&coefficients, discriminant, &solutions);


    PrintOutput(coefficients, discriminant, solutions, solutions_count);

    return 0;
}

double CalculateDiscriminant(Coeffs *ptr_coefficients)
{
    return pow(ptr_coefficients->b, 2) - 4 * ptr_coefficients->a * ptr_coefficients->c;
}

void SolveQuadCase(Coeffs *ptr_coefficients,
                       double discriminant,
                       Solutions* solutions)
{
    solutions->x1 = (-ptr_coefficients->b + sqrt(discriminant)) / (2 * ptr_coefficients->a);
    solutions->x2 = (-ptr_coefficients->b - sqrt(discriminant)) / (2 * ptr_coefficients->a);
}

void SolveLinearCase(Coeffs *ptr_coefficients, Solutions* ptr_solutions)
{
    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;
}

InputResults_t ReadCoeffs(Coeffs* ptr_coefficients)
{
    char buf[100];

    printf("enter A value: ");
    scanf("%s", buf);
    if (sscanf(buf, "%lf", &ptr_coefficients->a) < 1.f)
        return kInputError;


    printf("enter B value: ");
    scanf("%s", buf);
    if (sscanf(buf, "%lf", &ptr_coefficients->b) < 1.f)
        return kInputError;

    printf("enter C value: ");
    scanf("%s", buf);
    if (sscanf(buf, "%lf", &ptr_coefficients->c) < 1.f)
        return kInputError;

    return kInputSucces;
}

RootsCount_t SolveEquasion(Coeffs *ptr_coefficients,
                            double discr,
                            Solutions* ptr_solutions)
{
    if (discr < 0)
    {
        return kZeroRoots;
    }
    else if (ptr_coefficients->a < 0 || ptr_coefficients->a > 0)
    {

        SolveQuadCase(ptr_coefficients, discr, ptr_solutions);

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
        if (ptr_coefficients->b < 0 || ptr_coefficients->b > 0)
        {
            SolveLinearCase(ptr_coefficients, ptr_solutions);

            return kOneRoot;
        }
        else
        {
            if (ptr_coefficients->c < 0 || ptr_coefficients->c > 0)
            {
                return kZeroRoots;
            }
            else
            {
                return kInfRoots;
            }
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

void PrintInputErrorMessage()
{
        printf("____________________________________\n");
        printf("Have troubles with entering a number?");
        printf("\nCall your mom  or shut down your computer, maybe it will help.");
        printf("\nAfter doing that you will have a chance to do it once more.\n");
        printf("____________________________________\n");
}

int debug_printf( const char* fmt, ...)
{
    va_list arg_list;
    va_start(arg_list, fmt);
    return vprintf( fmt, arg_list);
    va_end(arg_list);

    return 0;
}

