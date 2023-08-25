#include <stdio.h>
#include <string.h>
#include "types.h"
#include "input.h"
#include "algorithm.h"
#include "output.h"
#include "debug.h"
#include "test.h"

void CallInputInterface(Coeffs *ptr_coefficients, Solutions *ptr_solutions);

int main()
{
    PrintWelcome();

    Coeffs coefficients = {0};
    Solutions solutions = {0};

    InputResults status = kInputSuccess;

    printf("#/ Write the command or type 'help' to invoke list of commands.\n#/ ");

    while ((status = GetInput(stdin, &coefficients)) != kQuit &&
            status != kEofError &&
            status != kInputFileError)
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
                printf("#/ Hey, buddy, try to write a command one more time! Or write 'help'.\n#/ ");
                break;
            }

            case kBufferOverflowError:
            {
                printf("#/ Hey, buddy, program spotted buffer overflow.\n#/ ");
                break;
            }

            case kInputSuccess:
            {

                SolveEquation(&coefficients,
                              &solutions);

                PrintOutput(&coefficients,
                            &solutions);


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

            case kTestFileError:
            {
                printf("#/ Hey, buddy, we got a problem with test file.\n#/");
                break;
            }

            case kQuit:

            case kEofError:

            case kInputFileError:

            default:
            {
                CHECK(0);

                printf("#/ What the fuck!?\n");

                break;
            }
        }
    }

    switch (status)
    {
        case kEofError:
        {
            printf("#/ Hey, buddy, we were blinded by EOF.\n");
            break;
        }

        case kInputFileError:
        {
            printf("#/ Hey, buddy, something went wrong with input file.\n#/ ");
            break;
        }

        case kQuit:
        {
            printf("#/ Have a good evening.");
            break;
        }

        case kInputError:

        case kInputSuccess:

        case kBufferOverflowError:

        case kTestFileError:

        case kHelp:

        case kMeow:

        case kTest:

        case kZeroStr:

        default:
        {
            CHECK(0);

            printf("#/ what the fuck?");

            break;
        }
    }

    return 0;
}


