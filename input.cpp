#include <string.h>
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "debug.h"
#include "algorithm.h"
#include "output.h"
#include "test.h"



#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;

#endif

void CallInputInterface(Coeffs *ptr_coefficients, Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);

    InputResults status = kInputSucces;

    printf("#/ Write the command or type 'help' to invoke list of commands.\n"
           "#/ ");

    while ((status = GetInput(stdin, ptr_coefficients)) != kQuit && status != kEofError)
    {
        switch (status)
        {
            case kHelp:
            {
                PrintHelpList();
                break;
            }
            case kInputError:
            {
                printf("#/ Hey, buddy, try to write a command one more time! Or write 'help'.\n"
                       "#/ ");
                break;
            }
            case kBufferOverflowError:
            {
                printf("#/ Hey, buddy, program spotted buffer overflow.\n"
                       "#/ ");
                break;
            }
            case kEofError:
            {
                printf("#/ Hey, buddy, we reached so called EOF.\n");
                break;
            }
            case kInputSucces:
            {

                RootsCount roots_count = SolveEquation(ptr_coefficients,
                                                       ptr_solutions);

                PrintOutput(ptr_coefficients,
                            ptr_solutions,
                            roots_count);

                break;
            }
            case kMeow:
            {
                PrintKitty();
                break;
            }
            #ifdef DEBUG
            case kTest:
            {
                Test();
                break;
            }
            #endif
            case kZeroStr:
            {
                printf("#/ ");
                break;
            }
            case kFileError:
            {
                printf("#/ Hey, buddy, we got a problem while opening file for tests.\n#/ ");
            }
            case kQuit:

            default:
            {
                CHECK(0);
                printf("#/ What the fuck!?\n");
                printf("#/ Write the command or type 'help' to invoke list of commands.\n");
                break;
            }
        }
    }

    printf("#/ Have a good evening.");
}

const int kMaxBuf = 257;

InputResults GetInput(FILE *ptr_file,
                      Coeffs *ptr_coefficients)
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

    return ConvertBuf(buf, ptr_coefficients);
}

InputResults ConvertBuf(char *buf,
                        Coeffs *ptr_coefficients)
{
    for (int i = 0; i < kCommandArraySize; ++i)
    {
        if (strcmp(buf, command_array[i].command_name) == 0)
            return command_array[i].result;
    }

    return ConvertBufToCoeffs(buf,
                              ptr_coefficients);

}

InputResults ConvertBufToCoeffs(char *buf,
                                Coeffs *ptr_coefficients)
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



