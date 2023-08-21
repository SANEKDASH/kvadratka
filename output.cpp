#include "types.h"
#include "output.h"
#include "debug.h"
#include <stdio.h>

#define DEBUG 1

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

void PrintOutput(Coeffs *ptr_coefficients,
                 double discriminant,
                 Solutions *ptr_solutions,
                 RootsCount solutions_count)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    printf("____________________________________\n");
    printf("\nA = %0.2lf | B = %0.2lf | C = %0.2lf\n", ptr_coefficients->a,
                                                       ptr_coefficients->b,
                                                       ptr_coefficients->c);

    printf("\tD = %.2lf\n", discriminant);
    printf("____________________________________\n");

    switch (solutions_count)
    {
        case kZeroRoots:
        {
            printf("there are no any solutions\n");
            break;
        }

        case kOneRoot:
        {
            printf("there is one solution:\n");
            printf("\tx = %.2lf\n", ptr_solutions->x1);
            break;
        }

        case kTwoRoots:
        {
            printf("there are two roots:\n");
            printf("\tx1 = %.2lf\n\tx2 = %.2lf\n", ptr_solutions->x1, ptr_solutions->x2);
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

