#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "types.h"
#include "algorithm.h"
#include "test.h"
#include "debug.h"

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

void Test()
{
    Coeffs coefficients = {0};
    Solutions real_solutions = {0};

    FILE *ptr_file = fopen("test.txt", "r");

    InputResults result = kInputSucces;

    for (int i = 1; (result = GetInput_test(ptr_file,
                                    &coefficients,
                                    &real_solutions)) != kEofError;)
    {
        switch (result)
        {
            case kInputSucces:
            {
                printf("#/ Test %d: ", i++);

                TestAlgorithm(&coefficients,
                              &real_solutions);
                break;
            }

            case kInputError:
            {
                printf("#/ Please, check spelling of coefficients and roots in test: %d.\n", i);
                break;
            }

            case kZeroStr:
            {
                break;
            }

            case kBufferOverflowError:
            {
                printf("#/ Spotted buffer overflow in test: %d.\n", i++);
                break;
            }
            case kFileError:
            {
                printf("#/ Got problem with opening file.\n");
                break;
            }
            case kMeow:

            case kQuit:

            case kHelp:

            case kTest:

            case kEofError:

            default:
            {
                printf("#/ I don't know.\n");
                break;
            }
        }

    }

    if("#/ There is nothing to test in 'test.txt.\n'")

    fclose(ptr_file);
    printf("#/ ");
}

int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions)
{
    Solutions solutions = {0};

    if (ptr_real_solutions->x1 < ptr_real_solutions->x2)
    {
        double tmp_number = ptr_real_solutions->x1;
        ptr_real_solutions->x1 = ptr_real_solutions->x2;
        ptr_real_solutions->x2 = tmp_number;
    }

    SolveEquation(ptr_coefficients,
                  &solutions);

    if (AreEqual(solutions.x1, ptr_real_solutions->x1) != 0 ||
        AreEqual(solutions.x2, ptr_real_solutions->x2) != 0)
    {
        printf("Test failed: x1 = %lf, x2 = %lf.\n"
               "   Expected: x1 = %lf, x2 = %lf\n", solutions.x1,
                                                  solutions.x2,
                                                  ptr_real_solutions->x1,
                                                  ptr_real_solutions->x2);
        return 0;
    }
    else
    {
        printf("Test succeed!\n");
        return 1;
    }
}

const int kMaxBuf = 257;

InputResults GetInput_test(FILE *ptr_file,
                           Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    static char buf[kMaxBuf] = {0};
    buf[0] = '\0';

    int i = 0;

    int c = 0;

    bool BufferOverflowStatus = false;

    if (ferror(ptr_file))
    {
        return kFileError;
    }

    while ((c = getc(ptr_file)) != '\n')
    {
        if (i < kMaxBuf - 1)
        {
            if (c != EOF)
            {
                buf[i++] = (char) c;
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

    return GetCoeffsAndSolutions(buf, ptr_coefficients, ptr_solutions);
}

InputResults GetCoeffsAndSolutions(char *buf,
                                   Coeffs *ptr_coefficients,
                                   Solutions *ptr_solutions)
{
    if (buf[0] == '\0')
    {
        return kZeroStr;
    }

    char *number_end = nullptr;

    ptr_coefficients->a = strtod(buf, &number_end);

    if (buf != number_end)
    {
        buf = number_end;
        ptr_coefficients->b = strtod(buf, &number_end);
    }

    if (buf != number_end)
    {
        buf = number_end;
        ptr_coefficients->c = strtod(buf, &number_end);
    }

    if (buf != number_end)
    {
        buf = number_end;
        ptr_solutions->x1 = strtod(buf, &number_end);
    }

    if (buf != number_end)
    {
        buf = number_end;
        ptr_solutions->x2 = strtod(buf, &number_end);
    }

    while (isspace(*number_end))
    {
        ++number_end;
    }

    if (*number_end == '\0' && buf[0] != '\0')
    {
        return kInputSucces;
    }
    else
    {
        return kInputError;
    }
}


