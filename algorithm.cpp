#include "types.h"
#include "algorithm.h"
#include <math.h>
#include "debug.h"

#define DEBUG 1

#ifdef DEBUG
#define CHECK(expression) CheckIt(expression, __LINE__, __func__, __FILE__)
#else
#define CHECK(expression) ;
#endif

RootsCount SolveEquation(const Coeffs *ptr_coefficients,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    double discriminant = CalculateDiscriminant(ptr_coefficients);

    if (discriminant < 0)
    {
        return kZeroRoots;
    }
    else if (AreEqual(ptr_coefficients->a, 0) != 0)
    {
        return SolveQuadCase(ptr_coefficients, discriminant, ptr_solutions);
    }
    else
    {
        if (AreEqual(ptr_coefficients->b, 0) != 0)
        {
            return SolveLinearCase(ptr_coefficients, ptr_solutions);
        }
        else
        {
            if (AreEqual(ptr_coefficients->c, 0) != 0)
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

double CalculateDiscriminant(const Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);

    return ptr_coefficients->b * ptr_coefficients->b - 4 * ptr_coefficients->a * ptr_coefficients->c;
}

RootsCount SolveQuadCase(const Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    double D = sqrt(discriminant);

    ptr_solutions->x1 = (-ptr_coefficients->b + D) / (2 * ptr_coefficients->a);
    ptr_solutions->x2 = (-ptr_coefficients->b - D) / (2 * ptr_coefficients->a);

    if (AreEqual(ptr_solutions->x1, ptr_solutions->x2) == 0)
    {
        return kOneRoot;
    }
    else
    {
        return kTwoRoots;
    }
}

RootsCount SolveLinearCase(const Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;

    return kOneRoot;
}

int AreEqual(double number_1, double number_2)
{
    static const double kE = 1e-10;
    if (fabs(number_1 - number_2) > kE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
