#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "types.h"
#include "algorithm.h"
#include "test.h"
#include "debug.h"
#include "output.h"

//! Checks whether the values of the roots obtained from the file are equal test.txt , with the values of the roots obtained by the algorithm of the program
//!
//! @param ptr_coeffients    pointer to the structure with the coefficients of the quadratic equation
//! @param ptr_real_solutions    pointer to a structure with solutions of sq.ur. obtained from test.txt
static int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions);

//! Records the coefficients, the real roots of the square.ur from file to buffer.
//!
//! @param ptr_file    pointer to the file being read
//! @param solutions_count    variable equal to the constant corresponding to the number of roots of sq.ur.
//! @param ptr_solutions    pointer to the structure with the roots of the quadratic equation
//!
//! @note In case of incorrect entry returns the kInputError error
//!
//! @see types.h
static InputResults GetInputTest(FILE *ptr_file,
                          Coeffs *ptr_coefficients,
                          Solutions *ptr_solutions);

//! Reads the coefficients, the real roots of the equation from the buffer
//!
//! @param buf    buffer
//! @param solutions_count    variable equal to the constant corresponding to the number of roots of the square unit.
//! @param ptr_solutions    pointer to the structure with the roots and number of roots in quadratic equation
//!
//!@see types.h
static InputResults GetCoeffsAndSolutions(char *buf,
                                   Coeffs *ptr_coefficients,
                                   Solutions *ptr_solutions);

void Test()
{
    Coeffs coefficients = {0};
    Solutions real_solutions = {0};

    FILE *ptr_file = fopen("test.txt", "r");

    InputResults result = kInputSuccess;

    for (int i = 1; (result = GetInputTest(ptr_file,
                                           &coefficients,
                                           &real_solutions)) != kEofError;)
    {
        switch (result)
        {
            case kInputSuccess:
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
                SetColor(4);
                printf("#/ Spotted buffer overflow in test: %d.\n", i++);
                SetColor(7);
                break;
            }
            case kTestFileError:
            {
                SetColor(4);
                printf("#/ Got problem with opening file.\n");
                SetColor(7);
                break;
            }
            case kMeow:

            case kQuit:

            case kHelp:
            #ifdef DEBUG
            case kTest:
            #endif
            case kEofError:

            case kInputFileError:

            default:
            {
                CHECK(0);
                printf("#/ I don't know.\n");
                break;
            }
        }

    }

    fclose(ptr_file);
    printf("#/ ");
}

static int TestAlgorithm(Coeffs *ptr_coefficients,
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
    // Presumes that SolveEquation() gives sorted roots.
    CHECK(solutions.x1 >= solutions.x2);

    if (!AreEqual(solutions.x1, ptr_real_solutions->x1) ||
        !AreEqual(solutions.x2, ptr_real_solutions->x2) ||
        !AreEqual(solutions.roots_count, ptr_real_solutions->roots_count))
    {
        SetColor(4);
        printf("Test failed: x1 = %lf, x2 = %lf.\n"
               "              Expected: x1 = %lf, x2 = %lf\n", solutions.x1,
                                                               solutions.x2,
                                                               ptr_real_solutions->x1,
                                                               ptr_real_solutions->x2);

        SetColor(7);
        return 0;
    }
    else
    {
        SetColor(2);
        printf("Test succeed!\n");
        SetColor(7);
        return 1;
    }
}

const int kMaxBuf = 257;

static InputResults GetInputTest(FILE *ptr_file,
                                 Coeffs *ptr_coefficients,
                                 Solutions *ptr_solutions)
{
    CHECK(ptr_file);
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    static char buf[kMaxBuf] = {0};
    buf[0] = '\0';

    int i = 0;

    int c = 0;

    bool BufferOverflowStatus = false;

    if (ferror(ptr_file))
    {
        return kTestFileError;
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

static InputResults GetCoeffsAndSolutions(char *buf,
                                          Coeffs *ptr_coefficients,
                                          Solutions *ptr_solutions)
{
    CHECK(buf);
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

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

    if (buf != number_end)
    {
        buf = number_end;

        ptr_solutions->roots_count = (RootsCount) strtoul(buf, &number_end, 10);
    }

    while (isspace(*number_end))
    {
        ++number_end;
    }

    if (*number_end == '\0' && buf[0] != '\0')
    {
        return kInputSuccess;
    }
    else
    {
        return kInputError;
    }
}


