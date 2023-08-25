#include "types.h"
#include "algorithm.h"
#include <math.h>
#include "debug.h"

//!Calculates the roots of a quadratic equation, writes their value into a structure with roots.
//!Returns a constant corresponding to two or one root
//!
//! @param ptr_coeffients    pointer to a structure with coefficients of a quadratic equation
//! @param discriminant    discriminant value
//! @param ptr_solutions    pointer to the structure with the roots of the quadratic equation
//!
//! @note if the root of the square equation is one, then both roots in the solution structure are equal
//! @see types.h
static RootsCount SolveQuadCase(const Coeffs *ptr_coefficients,
                         double discriminant,
                         Solutions *ptr_solutions);

//! Calculates the values of the single root of the equation with the coefficient A = 0
//! Returns a constant corresponding to one root
//!
//! @param ptr_coeffients    pointer to a structure with coefficients of a quadratic equation
//! @param ptr_solutions    pointer to a structure with roots of a quadratic equation
//!
//! @note both roots in the structure become equal to each other *
//! @see types.h
static RootsCount SolveLinearCase(const Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);

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
    else if (!AreEqual(ptr_coefficients->a, 0))
    {
        ptr_solutions->roots_count = SolveQuadCase(ptr_coefficients, discriminant, ptr_solutions);

        return;
    }
    else
    {
        if (!AreEqual(ptr_coefficients->b, 0))
        {
            ptr_solutions->roots_count = SolveLinearCase(ptr_coefficients, ptr_solutions);

            return;
        }
        else
        {
            if (!AreEqual(ptr_coefficients->c, 0))
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

    if (AreEqual(ptr_solutions->x1, ptr_solutions->x2))
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

    return fabs(number_1 - number_2) < kE;
}
