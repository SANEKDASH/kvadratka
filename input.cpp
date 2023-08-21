#include "types.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "debug.h"

#define DEBUG 1

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

void PrintInputErrorMessage()
{
        printf("________________________________________________________________\n");
        printf("Have troubles with entering a number?");
        printf("\nCall your mom  or shut down your computer, maybe it will help.");
        printf("\nAfter doing that you will have a chance to do it once more.\n");
        printf("________________________________________________________________\n");
}

ReadingResults CheckBuf(char buf[])
{
    char *number_end;

    strtod(buf, &number_end);

    if(*number_end == '\0')
    {
        return kReadingSucces;
    }
    else
    {
        return kReadingError;
    }
}

const int kMaxBuf = 256;

InputResults GetOneCoeff(double *coeff)
{
    CHECK(coeff);

    char buf[kMaxBuf];
    int i = 0;
    char c;

    buf[0] = '\0';

    while ((c = getchar()) != '\n')
    {
        if (i > kMaxBuf - 1)
        {
            printf("buffer overflow\n");
            abort();
        }
        else if (c != EOF)
        {
            buf[i++] = c;
        }
        else
        {
            printf("Reached EOF\n");  //sho?
            abort();
        }
    }

    if (i > 0)
    {
        buf[i] = '\0';
    }

    if (CheckBuf(buf) != kReadingSucces)
    {
        return kInputError;
    }
    else
    {
        *coeff = atof(buf);
        return kInputSucces;
    }
}

InputResults ReadCoeffs(Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);

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

