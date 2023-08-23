#include <stdio.h>
#include <string.h>
#include "types.h"
#include "input.h"
#include "algorithm.h"
#include "output.h"
#include "debug.h"


int main(int argc, const char *argv[])
{
    PrintWelcome();

    Coeffs coefficients = {0};
    Solutions solutions = {0};

    CallReadingInterface(&coefficients, &solutions);

    return 0;
}
