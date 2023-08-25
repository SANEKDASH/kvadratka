#include <stdio.h>
#include <string.h>
#include <windows.h>
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
                cPrintf(kRed, "#/ Hey, buddy, try to write a command one more time! Or write 'help'.\n");
                printf("#/ ");

                break;
            }

            case kBufferOverflowError:
            {
                cPrintf(kRed, "#/ Hey, buddy, program spotted buffer overflow.\n");
                printf("#/ ");

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
                cPrintf(kRed, "#/ Hey, buddy, we got a problem with test file.\n");
                printf("#/ ");
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
            cPrintf(kRed, "#/ Hey, buddy, we were blinded by EOF.\n");
            break;
        }

        case kInputFileError:
        {
            cPrintf(kRed, "#/ Hey, buddy, something went wrong with input file.\n");
            break;
        }

        case kQuit:
        {
            cPrintf(kGold, "#/ Have a good evening.");
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


