#include "types.h"
#include "algorithm.h"
#include <math.h>
#include "debug.h"

void SolveEquation(const Coeffs *ptr_coefficients,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    double discriminant = CalculateDiscriminant(ptr_coefficients);

    if (discriminant < 0)
    {
        ptr_solutions->roots_count =  kZeroRoots;

        return;
    }
    else if (AreEqual(ptr_coefficients->a, 0))
    {
        ptr_solutions->roots_count = SolveQuadCase(ptr_coefficients, discriminant, ptr_solutions);

        return;
    }
    else
    {
        if (AreEqual(ptr_coefficients->b, 0))
        {
            ptr_solutions->roots_count = SolveLinearCase(ptr_coefficients, ptr_solutions);

            return;
        }
        else
        {
            if (AreEqual(ptr_coefficients->c, 0))
            {
                ptr_solutions->roots_count = kZeroRoots;

                return;
            }
            else
            {
                ptr_solutions->roots_count =  kInfRoots;

                return;
            }
        }
    }
}

double CalculateDiscriminant(const Coeffs *ptr_coefficients)
{
    CHECK(ptr_coefficients);

    return ptr_coefficients->b * ptr_coefficients->b - 4 * ptr_coefficients->a * ptr_coefficients->c;
}

static RootsCount SolveQuadCase(const Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    double sqrt_discr = sqrt(discriminant);

    ptr_solutions->x1 = (-ptr_coefficients->b + sqrt_discr) / (2 * ptr_coefficients->a);
    ptr_solutions->x2 = (-ptr_coefficients->b - sqrt_discr) / (2 * ptr_coefficients->a);

    if (AreEqual(ptr_solutions->x1, ptr_solutions->x2) == 0)
    {
        return kOneRoot;
    }
    else
    {
        return kTwoRoots;
    }
}

static RootsCount SolveLinearCase(const Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions)
{
    CHECK(ptr_coefficients);
    CHECK(ptr_solutions);

    ptr_solutions->x1 = ptr_solutions->x2 = -ptr_coefficients->c / ptr_coefficients->b;

    return kOneRoot;
}

bool AreEqual(double number_1, double number_2)
{
    static const double kE = 1e-4;

    return fabs(number_1 - number_2) > kE;
}
