#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

int kMaxBuf = 256;

typedef enum
{
    kZeroRoots,
    kOneRoot,
    kTwoRoots,
    kInfRoots,
} RootsCount;

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
} InputResults;

typedef enum
{
    kReadingError,
    kReadingSucces,
} ReadingResults;


double CalculateDiscriminant(Coeffs *ptr_coefficients)
{
    return ptr_coefficients->b*ptr_coefficients->b - 4 * ptr_coefficients->a * ptr_coefficients->c;
}

RootsCount SolveQuadCase(Coeffs *ptr_coefficients,
                         double *ptr_discriminant,
                         Solutions *ptr_solutions)
{
    double D = sqrt(*ptr_discriminant);

    ptr_solutions->x1 = (-ptr_coefficients->b + D) / (2 * ptr_coefficients->a);
    ptr_solutions->x2 = (-ptr_coefficients->b - D) / (2 * ptr_coefficients->a);

    if (ptr_solutions->x1 == ptr_solutions->x2)
    {
        return kOneRoot;
    }
    else
    {
        return kTwoRoots;
    }
}

RootsCount SolveLinearCase(Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions)
{
    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;

    return kOneRoot;
}

RootsCount SolveEquasion(Coeffs *ptr_coefficients,
                         double *ptr_discriminant,
                         Solutions *ptr_solutions)
{
    if (*ptr_discriminant < 0)
    {
        return kZeroRoots;
    }
    else if (ptr_coefficients->a < 0 || ptr_coefficients->a > 0)
    {
        return SolveQuadCase(ptr_coefficients, ptr_discriminant, ptr_solutions);
    }
    else
    {
        if (ptr_coefficients->b < 0 || ptr_coefficients->b > 0)
        {
            return SolveLinearCase(ptr_coefficients, ptr_solutions);
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

void PrintOutput(Coeffs *coefficients,
                 double *discriminant,
                 Solutions *solutions,
                 RootsCount *solutions_count)
{
    printf("____________________________________\n");
    printf("\nA = %0.2lf | B = %0.2lf | C = %0.2lf\n", coefficients->a,
                                                       coefficients->b,
                                                       coefficients->c);
    printf("\tD = %.2lf\n", *discriminant);
    printf("____________________________________\n");

    switch (*solutions_count)
    {
        case kZeroRoots:
        {
            printf("there are no any solutions\n");
            break;
        }

        case kOneRoot:
        {
            printf("there is one solution:\n");
            printf("\tx = %.2lf\n", solutions->x1);
            break;
        }

        case kTwoRoots:
        {
            printf("there are two roots:\n");
            printf("\tx1 = %.2lf\n\tx2 = %.2lf\n", solutions->x1, solutions->x2);
            break;
        }

        case kInfRoots:
        {
            printf("there are a lot of roots :)\n");
            break;
        }

        default:
        {
            printf("what the fuck!?\n");
            break;
        }
    }

    printf("____________________________________\n");
}

void PrintInputErrorMessage()
{
        printf("________________________________________________________________\n");
        printf("Have troubles with entering a number?");
        printf("\nCall your mom  or shut down your computer, maybe it will help.");
        printf("\nAfter doing that you will have a chance to do it once more.\n");
        printf("________________________________________________________________\n");
}

int debug_printf(const char *fmt, ...)
{
    va_list arg_list;
    va_start(arg_list, fmt);

    return vprintf( fmt, arg_list);

    va_end(arg_list);

    return 0;
}

ReadingResults CheckBuf(char buf[])
{
    int i = 0;

    while (buf[i] == ' ' || buf[i] == '\t')
    {
        ++i;
    }

    if (buf[i] != '+' && buf[i] != '-' && !isdigit(buf[i]))
    {
        return kReadingError;
    }

    while (isdigit(buf[i]))
    {
        ++i;
    }

    if (buf[i] == '.')
    {
        ++i;

        while (isdigit(buf[i]))
        {
            ++i;
        }
    }

    if (buf[i] == 'e' || buf[i] == 'E' )
    {
        ++i;

        if (buf[i] == '+' || buf[i] == '-' || isdigit(buf[i]))
        {
            ++i;

            while (isdigit(buf[i]))
            {
                ++i;
            }
        }
    }

    while (buf[i] == ' ' || buf[i] == '\t')
    {
        ++i;
    }

    if (buf[i] == '\0')
    {
        return kReadingSucces;
    }
    else
    {
        return kReadingError;
    }
}

InputResults GetOneCoeff(double *a)
{
    static char buf[256];
    int i = 0;
    char c;

    buf[0] = '\0';

    while ((c = getchar()) != '\n')
    {
        if (c != EOF)
        {
            buf[i++] = c;
        }
        else
        {
            printf("Reached EOF\n");
            abort();
        }
    }

    buf[i] = '\0';

    if (CheckBuf(buf) != kReadingSucces)
    {
        return kInputError;
    }
    else
    {
        *a = atof(buf);
        return kInputSucces;
    }
}

InputResults ReadCoeffs(Coeffs *ptr_coefficients)
{
    char buf[100];

    printf("enter A value: ");
    while (GetOneCoeff(&ptr_coefficients->a) != kInputSucces)
    {
        PrintInputErrorMessage();
        printf("enter A value: ");
    }

    printf("enter B value: ");
    while (GetOneCoeff(&ptr_coefficients->b) != kInputSucces)
    {
        PrintInputErrorMessage();
        printf("enter B value: ");
    }

    printf("enter C value: ");
    while (GetOneCoeff(&ptr_coefficients->c) != kInputSucces)
    {
        PrintInputErrorMessage();
        printf("enter C value: ");
    }

    return kInputSucces;
}

void CheckPointer(void *pointer, int line)
{
    if (pointer == NULL)
    {
        printf("pointer is equal to zero in line - %d", line);
        abort();
    }
}
