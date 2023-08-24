#include "types.h"
#include "output.h"
#include "debug.h"
#include "algorithm.h"
#include <stdio.h>

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

void PrintWelcome()
{
    printf("#/ Hello! This program does many things.\n");
}

void PrintHelpList()
{
    printf("#/ type 3 numbers to solve quadratic equation with this coefficients.\n");
    for(int i = 0; i < kCommandArraySize; i++)
        printf("#/ '%s' - %s.\n",command_array[i].command_name,
                                command_array[i].help_text);
    printf("#/ ");

}

void PrintOutput(const Coeffs *ptr_coefficients,
                 const Solutions *ptr_solutions,
                 const RootsCount solutions_count)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    printf("____________________________________\n");
    printf("\nA = %0.2lf | B = %0.2lf | C = %0.2lf\n", ptr_coefficients->a,
                                                       ptr_coefficients->b,
                                                       ptr_coefficients->c);

    double discriminant = CalculateDiscriminant(ptr_coefficients);

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

    printf("____________________________________\n"
           "#/ ");
}

void PrintKitty()
{
    printf("  /\\_/\\  \n"
           " ( o.o ) \n"
           "  > U <  \n");
    printf("#/ ");
}


