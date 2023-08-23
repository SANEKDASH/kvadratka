#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "types.h"
#include "algorithm.h"

void Test()
{
    Coeffs coefficients;



    FILE *ptr_file = fopen("test.txt", "r");

    for (int i = 0; GetInput(ptr_file))
}

int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions,
                  RootsCount real_roots_count)
{
    Solutions solutions = {0};

    RootsCount roots_count = SolveEquation(ptr_coefficients,
                                           &solutions);

    if (ptr_real_solutions->x1 < ptr_real_solutions->x2)
    {
        double tmp_number = ptr_real_solutions->x1;
        ptr_real_solutions->x1 = ptr_real_solutions->x2;
        ptr_real_solutions->x2 = tmp_number;
    }

    if (AreEqual(solutions.x1, ptr_real_solutions->x1) != 0 ||
        AreEqual(solutions.x2, ptr_real_solutions->x2) != 0 ||
        roots_count != real_roots_count)
    {
        printf("#/ Test failed: x1 = %lf, x2 = %lf.\n"
               "#/ Expected: x1 = %lf, x2 = %lf", solutions.x1,
                                                  solutions.x2,
                                                  ptr_real_solutions->x1,
                                                  ptr_real_solutions->x2);
        return 0;
    }
    else
    {
        printf("#/ Test succeed!\n");
        return 1;
    }
}

InputResults GetInput(FILE *ptr_file, Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);

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


