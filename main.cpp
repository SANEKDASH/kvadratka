#include <stdio.h>
#include <string.h>
#include "types.h"
#include "input.h"
#include "algorithm.h"
#include "output.h"
#include "debug.h"
#include "test.h"

int main()
{
    PrintWelcome();

    Coeffs coefficients = {0};
    Solutions solutions = {0};

    CallInputInterface(&coefficients, &solutions);

    return 0;
}
