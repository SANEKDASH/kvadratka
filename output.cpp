#include "types.h"
#include "output.h"
#include "debug.h"
#include "algorithm.h"
#include <stdio.h>

void PrintWelcome()
{
    printf("#/ Hello! This program does many things.\n");
}

void PrintHelpList()
{
    printf("#/ type 3 numbers to solve quadratic equation with this coefficients.\n");
    for(int i = 0; i < kCommandArraySize; i++)
        printf("#/ '%s' - %s.\n",CommandArray[i].command_name,
                                 CommandArray[i].help_text);
    printf("#/ ");

}

void PrintOutput(const Coeffs *ptr_coefficients,
                 const Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    printf("__________________________________________\n");
    printf("\nA = %0.4lf | B = %0.4lf | C = %0.4lf\n", ptr_coefficients->a,
                                                       ptr_coefficients->b,
                                                       ptr_coefficients->c);

    double discriminant = CalculateDiscriminant(ptr_coefficients);

    printf("\tD = %.4lf\n", discriminant);
    printf("__________________________________________\n");

    switch (ptr_solutions->roots_count)
    {
        case kZeroRoots:
        {
            printf("there are no any solutions\n");
            break;
        }

        case kOneRoot:
        {
            printf("there is one solution:\n");
            printf("\tx = %.4lf\n", ptr_solutions->x1);
            break;
        }

        case kTwoRoots:
        {
            printf("there are two roots:\n");
            printf("\tx1 = %.4lf\n\tx2 = %.4lf\n", ptr_solutions->x1, ptr_solutions->x2);
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

    printf("__________________________________________\n"
           "#/ ");
}

void PrintKitty()
{
    printf("  /\\_/\\  \n"
           " ( o.o ) \n"
           "  > U <  \n");
    printf("#/ ");
}


