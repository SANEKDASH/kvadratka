#include "types.h"
#include "algorithm.h"
#include "math.h"
#include "debug.h"

#define DEBUG 1

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

double CalculateDiscriminant(Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);
    return ptr_coefficients->b*ptr_coefficients->b - 4 * ptr_coefficients->a * ptr_coefficients->c;
}

RootsCount SolveQuadCase(Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    double D = sqrt(discriminant);

    ptr_solutions->x1 = (-ptr_coefficients->b + D) / (2 * ptr_coefficients->a);
    ptr_solutions->x2 = (-ptr_coefficients->b - D) / (2 * ptr_coefficients->a);

    if (ptr_solutions->x1 == ptr_solutions->x2)
    {
        return kOneRoot;
    }
    else
    {
        return kTwoRoots;
    }
}

RootsCount SolveLinearCase(Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;

    return kOneRoot;
}

RootsCount SolveEquation(Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    if (discriminant < 0)
    {
        return kZeroRoots;
    }
    else if (ptr_coefficients->a < 0 || ptr_coefficients->a > 0)
    {
        return SolveQuadCase(ptr_coefficients, discriminant, ptr_solutions);
    }
    else
    {
        if (ptr_coefficients->b < 0 || ptr_coefficients->b > 0)
        {
            return SolveLinearCase(ptr_coefficients, ptr_solutions);
        }
        else
        {
            if (ptr_coefficients->c < 0 || ptr_coefficients->c > 0)
            {
                return kZeroRoots;
            }
            else
            {
                return kInfRoots;
            }
        }
    }
}
