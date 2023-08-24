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

const int kMaxBuf = 257;

InputResults GetInput(FILE *ptr_file,
                      Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_file);

    static char buf[kMaxBuf] = {0};
    buf[0] = '\0';

    int i = 0;

    int c = 0;

    bool BufferOverflowStatus = false;

    if (ferror(ptr_file))
    {
        return kInputFileError;
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

    if (buf[0] == '\0')
    {
        return kZeroStr;
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
    CHECK(buf);
    CHECK(ptr_coefficients);

    static const int kMaxCommand = 257;

    for (int i = 0; i < kCommandArraySize; ++i)
    {
        char command[kMaxCommand];

        if (strcmp(buf, CommandArray[i].command_name) == 0)
        {
            return CommandArray[i].result;
        }
    }

    return ConvertBufToCoeffs(buf,
                              ptr_coefficients);
}

InputResults ConvertBufToCoeffs(char *buf,
                                Coeffs *ptr_coefficients)
{
    CHECK(buf);
    CHECK(ptr_coefficients);

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
        return kInputSuccess;
    }
    else
    {
        return kInputError;
    }
}

bool GetCommand(const char *buf, char *command)
{
    CHECK(buf);
    CHECK(command);

    int i = 0;
    while(isspace(buf[i++]))
        ;

    int j = 0;
    while(!isspace(buf[i++]))
    {
        command[j++] = buf[i];
    }

    command[j] = '\0';

    while(isspace(buf[i++]))
        ;

    return buf[i] == '\0';
}

