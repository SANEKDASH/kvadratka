#include <stdio.h>
#include <math.h>
//
typedef enum
{
    kZeroRoots = 0,
    kOneRoot  = 1,
    kTwoRoots  = 2,
    kInfRoots  = 3,
} RootsCount_t;
//

typedef struct
{
    double a;
    double b;
    double c;
} sq_coeffs;
//

typedef struct
{
    double x1;
    double x2;
} salvs;
//

double find_dval(sq_coeffs cur_cfs)
{
    return pow(cur_cfs.b, 2) - 4 * cur_cfs.a * cur_cfs.c;
}


void solve_sq(sq_coeffs cur_cfs, double d, salvs* cur_salvs)
{
    cur_salvs->x1 = (-cur_cfs.b + sqrt(d)) / (2 * cur_cfs.a);
    cur_salvs->x2 = (-cur_cfs.b - sqrt(d)) / (2 * cur_cfs.a);
}


double solve_linear(sq_coeffs cur_cfs, salvs* cur_salvs)
{
    cur_salvs->x1 = cur_salvs->x2 = -cur_cfs.c / cur_cfs.b;
}


int read_cfs(sq_coeffs* coeffs)
{
    printf("enter A coeff. value: ");
    while(scanf("%lf", &coeffs->a) < 0 )
        printf("enter A coeff. value: ");

    printf("enter B coeff. value: ");
    while(scanf("%lf", &coeffs->b) < 0 )
        printf("enter A coeff. value: ");

    printf("enter C coeff. value: ");
    while(scanf("%lf", &coeffs->c) < 0 )
        printf("enter A coeff. value: ");
}


RootsCount_t solve_equasion(sq_coeffs cur_cfs,
                            double discr,
                            salvs* cur_salvs)
{
    if (discr < 0)
    {
        return kZeroRoots;
    }
    else if (cur_cfs.a != 0)
    {

        solve_sq(cur_cfs, discr, cur_salvs);

        if (cur_salvs->x1 == cur_salvs->x2)
        {
            return kOneRoot;
        }
        else
        {
            return kTwoRoots;

        }
    }
    else
    {
        if (cur_cfs.b == 0)
        {
            if (cur_cfs.c == 0)
            {
                return kInfRoots;
            }
            else
            {
                return kZeroRoots;
            }
        }
        else
        {


            solve_linear(cur_cfs, cur_salvs);

            return kOneRoot;
        }
    }


}


void print_output(sq_coeffs cur_cfs, double discr, salvs cur_salvs, RootsCount_t mode)
{
    printf("____________________________________\n");
    printf("\nA = %0.2lf | B = %0.2lf | C = %0.2lf\n", cur_cfs.a, cur_cfs.b, cur_cfs.c);
    printf("\tD = %.2lf\n", discr);
    printf("____________________________________\n");

    switch (mode)
    {
        case kZeroRoots:
            printf("there are no any solutions\n");
            break;

        case kOneRoot:
            printf("there is one solution:\n");
            printf("\tx = %.2lf", cur_salvs.x1);
            break;

        case kTwoRoots:
            printf("there are two roots:\n");
            printf("\tx1 = %.2lf\n\tx2 = %.2lf\n", cur_salvs.x1, cur_salvs.x2);
            break;

        case kInfRoots:
            printf("there are a lot of roots :)\n");
            break;

        default:
            printf("what the fuck!?\n");
    }

    printf("____________________________________\n");
}



int main()
{

    sq_coeffs cur_cfs;

    cur_cfs.a = 0;
    cur_cfs.c = 0;
    cur_cfs.b = 0;

    read_cfs(&cur_cfs);

    double d = 0;
    d = find_dval(cur_cfs);

    RootsCount_t mode;
    salvs cur_salvs;

    mode = solve_equasion(cur_cfs, d, &cur_salvs);

    print_output(cur_cfs, d, cur_salvs, mode);



    return 0;

}
