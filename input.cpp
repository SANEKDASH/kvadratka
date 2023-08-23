#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "types.h"
#include "input.h"
#include "debug.h"

#define DEBUG 1

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

const int kMaxBuf = 257;

InputResults GetOneCoeff(double *coeff)
{
    CHECK(coeff);

    static char buf[kMaxBuf];
    buf[0] = '\0';

    int i = 0;

    char c = 0;

    bool BufferOverflowStatus = false;

    while ((c = getchar()) != '\n')
    {
        if (i < kMaxBuf - 1)
        {
            if (c != EOF)
            {
                buf[i++] = c;
            }
            else
            {
                return kEofError;
            }
        }
        else
        {
            BufferOverflowStatus = true;
        }
    }

    if (BufferOverflowStatus)
    {
        return kBufferOverflowError;
    }

    if (i > 0)
    {
        buf[i] = '\0';
    }

    char *number_end;

    double num_copy = strtod(buf, &number_end);

    while (isspace(*number_end))
    {
        ++number_end;
    }

    if (*number_end == '\0' && buf[0] != '\0')
    {
        *coeff = num_copy;

        return kInputSucces;
    }
    else
    {
        return kInputError;
    }
}

void ReadCoeffs(Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);

    CallReadingInterface(&ptr_coefficients->a, "A");

    CallReadingInterface(&ptr_coefficients->b, "B");

    CallReadingInterface(&ptr_coefficients->c, "C");
}

void CallReadingInterface(double *ptr_coefficient, const char *coeff_name)
{

    CHECK(ptr_coefficient);

    InputResults status = kInputSucces;

    printf("#/ Enter %s value: ", coeff_name);

    while ((status = GetOneCoeff(ptr_coefficient)) != kInputSucces)
    {
        switch (status)
        {
            case kInputError:
            {
                printf("#/ Hey, buddy, try to write coefficient one more time!\n");
                printf("#/ Enter %s value: ", coeff_name);
                break;
            }
            case kBufferOverflowError:
            {
                printf("#/ Hey, buddy, program spotted buffer overflow.\n");
                printf("#/ Enter %s value: ", coeff_name);
                break;
            }
            case kEofError:
            {
                printf("#/ Hey, buddy, we reached so called EOF.\n");
                printf("#/ Enter %s value: ", coeff_name);
                break;
            }
            default:
            {
                printf("#/ What the fuck!?\n");
                printf("#/ Enter %s value: ", coeff_name);
                break;
            }
        }
    }
}

